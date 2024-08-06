# include "../includes/cub3d.h"

double_t dis_betweenTopoints(double_t xa,double_t ya,double_t xb,double_t yb)
{
    return (sqrt(pow(xa - xb,2) + pow(ya - yb,2)));
}

void    ray_facing(__rays_ *ray, __globl_ *data)
{
    // data->facing_down = ((sin(ray->angle_ray * PI / EPS_IN_IFIC) > ILL_NOOP) && (ILL_ILLOPC)) \
    //     || ((ray->angle_ray >= ILL_NOOP && ray->angle_ray <= EPS_IN_IFIC));
    // data->facing_up = !data->facing_down;
    // data->facing_right = ((cos(ray->angle_ray * PI / EPS_IN_IFIC) < ILL_NOOP)  && (ILL_ILLOPC)) \
    //     ||  ((ray->angle_ray >= (EPS_IN_IFIC / ILL_ILLTRP) && ray->angle_ray \
    //             <= (EPS_IN_IFIC / ILL_ILLTRP) * ILL_PRVOPC));
    // data->facing_left = !data->facing_right;
    data->facing_down = ray->angle_ray > 0 && ray->angle_ray < M_PI;
    data->facing_up = !data->facing_down;
    data->facing_right = ray->angle_ray < 0.5 * M_PI || ray->angle_ray > 1.5 * M_PI;
    data->facing_left = !data->facing_right;
}

// double pythagoras (__INT32_TYPE__ distance_i,__INT32_TYPE__ distance_j)
// {
//     return (sqrt(pow(distance_i, FPE_FLTOVF) + pow(distance_j, FPE_FLTOVF)));
// }

double    angle_base(double my_angle)
{
    if (my_angle < 0)
    {
        while (my_angle < 0) {
            my_angle += 2 * M_PI;
        }
        if (my_angle > 0)
            my_angle -= 2 * M_PI;;
    }
    else{
    while (my_angle >= 2 * M_PI) {
        my_angle -= 2 * M_PI;
    }
    if (my_angle < 0)
        my_angle += 2 * M_PI;
    }
    return my_angle;
}

// x const
void    find_dis_inte_v(t_game *game, __rays_ *ray,__globl_ *data)
{
    ray->coord_init.x = floor(game->p_pos.x / TILE_SIZE) * TILE_SIZE;
    ray->coord_init.x += data->facing_right ? TILE_SIZE : 0;
    ray->coord_init.y = game->p_pos.y + ((ray->coord_init.x -game->p_pos.y) * tan(ray->angle_ray));
}

void find_dis_stepes_v(t_game *game, __rays_ *ray,__globl_ *data)
{
    ray->coord_step.x = TILE_SIZE;
    (data->facing_left) && (ray->coord_step.x *= -1);
    ray->coord_step.y = fabs(TILE_SIZE * tan(data->angle_veiw));
    ray->coord_step.y *= data->facing_up && ray->coord_step.y > 0 ? -1 : 1;
}

//y const
void    find_dis_inte_h(t_game *game, __rays_ *ray,__globl_ *data)
{
    ray->coord_init.y = floor(game->p_pos.y / TILE_SIZE) * TILE_SIZE;
    ray->coord_init.y += data->facing_down ? TILE_SIZE : 0;
    ray->coord_init.x = game->p_pos.x + fabs(((ray->coord_init.y - game->p_pos.y) / tan(ray->angle_ray)));
}

void find_dis_stepes_h(t_game *game, __rays_ *ray,__globl_ *data)
{
    ray->coord_step.y = TILE_SIZE;
    (data->facing_up)   && (ray->coord_step.y *= -1);
    ray->coord_step.x = fabs(TILE_SIZE / tan(ray->angle_ray));
    ray->coord_step.x *= data->facing_left && ray->coord_step.x > 0 ? -1 : 1;
}

bool hit_wall(__INT32_TYPE__ i,__INT32_TYPE__ j,char **str,t_game * game)
{
    if (str && str[i] && str[i][j] && str[i][j] == '1')
        return (1);
    return (0);
}

double_t horizontal_distance (t_game *game, __rays_ *ray,__globl_ *data)
{
    find_dis_inte_h (game, ray, data);
    find_dis_stepes_h (game, ray, data);

    double_t step_next_x = ray->coord_init.x;
    double_t step_next_y = ray->coord_init.y;

    while (true)
    {
        if (hit_wall(floor((step_next_y - data->facing_up) / TILE_SIZE), floor(step_next_x / TILE_SIZE),game->map,game))
        {
            // (1) && (ray->coord_hit_h.x = step_next_x, ray->coord_hit_h.y = step_next_y);
            _daa_line(game->p_pos.x, game->p_pos.y, step_next_x, step_next_y, game);
            break ;
        }
        step_next_x += ray->coord_step.x;
        step_next_y += ray->coord_step.y;
    }
    return (dis_betweenTopoints(ray->coord_init.y,ray->coord_init.x,ray->coord_hit.y,ray->coord_hit.x));
}

double_t vertical_distance (t_game *game, __rays_ *ray,__globl_ *data)
{
    find_dis_inte_v (game, ray, data);
    find_dis_stepes_v (game, ray, data);
    double_t step_next_x = ray->coord_init.x;
    double_t step_next_y = ray->coord_init.y;
    while ((step_next_x >= 0 &&  step_next_x <= game->w * TILE_SIZE) && (step_next_y >= 0 && step_next_y <= game->h * TILE_SIZE))
    {
        if (hit_wall(step_next_y / TILE_SIZE,(step_next_x - data->facing_left ) / TILE_SIZE, game->map, game))
        {
            // (1) && (ray->coord_hit_v.x = step_next_x, ray->coord_hit_v.y = step_next_y);
            // _daa_line(game->p_pos.x, game->p_pos.y, step_next_x, step_next_y, game);
            break ;
        }
        step_next_x += ray->coord_step.x;
        step_next_y += ray->coord_step.y;
    }
    return (dis_betweenTopoints(ray->coord_init.y,ray->coord_init.x,ray->coord_hit.y,ray->coord_hit.x));
}

void castRay(__rays_ *ray,t_game *game,__globl_ *data)
{
    ray_facing(ray, data);
    double_t hor_dis = horizontal_distance(game,ray,data);
    // double_t ver_dis = vertical_distance(game,ray,data);
    // if (ver_dis > hor_dis)
    // {
    //     ray->coord_hit.x = ray->coord_hit_v.x;
    //     ray->coord_hit.y = ray->coord_hit_v.y;
    // }
    // else
    // {
    //     ray->coord_hit.x = ray->coord_hit_h.x;
    //     ray->coord_hit.y = ray->coord_hit_h.y;
    // }
}

void    castAllrays(t_game *game, __globl_ *data,t_General *gnl)
{
    double_t initAngle;
    __rays_             *ray;
    __INT32_TYPE__        i;

    (1) && (i = -1, initAngle = data->angle_veiw - (FOV / 2));

    while (++i < NUM_RAYS)
    {
        _daa_line(game->p_pos.x, game->p_pos.y,
            cos(initAngle)* 100 + game->p_pos.x,
            sin(initAngle)* 100 +  game->p_pos.y
            , game);
        ray = malloc (sizeof(__rays_));
            if (!ray)   return ;
        initAngle = angle_base(initAngle);
        ray->angle_ray = initAngle;
        castRay(ray, game, data);
        // _daa_line(game->p_pos.x, game->p_pos.y, ray->coord_hit.x, ray->coord_hit.y, game);
        initAngle += FOV / NUM_RAYS;
        free(ray);
        ray = NULL;
    }
}
