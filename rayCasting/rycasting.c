# include "../includes/cub3d.h"

double_t dis_betweenTopoints(double_t xa, double_t ya, double_t xb, double_t yb)
{
    return (sqrt((xb - xa)*((xb - xa)) + (yb - ya)*(yb - ya)));
}


void    ray_facing(__rays_ *ray, __globl_ *data)
{
    data->facing_down = ray->angle_ray > 0 && ray->angle_ray < M_PI;
    data->facing_up = !data->facing_down;
    data->facing_right = ray->angle_ray < 0.5 * M_PI || ray->angle_ray > 1.5 * M_PI;
    data->facing_left = !data->facing_right;
}


double normalizeAngle(double angle) {
    angle = fmod(angle , (2 * M_PI));
    if (angle < 0) {
        angle = (2 * M_PI) + angle;
    }
    return angle;
}

bool hasWallAt(double_t i, double_t j, t_game *game)
{
    if (i < 0 || i > (game->w * TILE_SIZE) || j < 0 || j > (game->h * TILE_SIZE))
        return (1);
    int x = floor(i / TILE_SIZE);
    int y = floor(j / TILE_SIZE);
    return (game->map[y][x] == '1');
}

double_t horizontal_distance (t_game *game, __rays_ *ray,__globl_ *data)
{
    int foundHorzWalHit = 0;
    double initY = 0;
    double initX = 0;
    double stepY = 0;
    double stepX = 0;
    initY = floor(game->p_pos.y / TILE_SIZE) * TILE_SIZE;
    initY += data->facing_down ? TILE_SIZE : 0;
    initX = game->p_pos.x + ((initY - game->p_pos.y) / tan(ray->angle_ray));
    
    stepY = TILE_SIZE;
    (data->facing_up)   && (stepY *= -1);
    stepX = TILE_SIZE / tan(ray->angle_ray);
    stepX *= data->facing_left && stepX > 0 ? -1 : 1;
    stepX *= data->facing_right && stepX < 0 ? -1 : 1;

    double_t step_next_x = initX;
    double_t step_next_y = initY;
    if (data->facing_up)
        step_next_y--;
    while ((step_next_x >= 0 &&  step_next_x <= game->w * TILE_SIZE) && (step_next_y >= 0 && step_next_y <= (game->h * TILE_SIZE)))
    {
        if (hasWallAt(step_next_x, step_next_y ,game))
        {
            foundHorzWalHit = 1;
            ray->coord_hit_h.x = step_next_x;
            ray->coord_hit_h.y = step_next_y;
            // _daa_line(game->p_pos.x, game->p_pos.y, ray->coord_hit_h.x, ray->coord_hit_h.y, game);
            break;
        }
        step_next_x += stepX;
        step_next_y += stepY;
    }
    if (foundHorzWalHit)
        return (dis_betweenTopoints(game->p_pos.x,game->p_pos.y,ray->coord_hit_h.x,ray->coord_hit_h.y));
    return (INT_MAX);
}

double_t vertical_distance (t_game *game, __rays_ *ray,__globl_ *data)
{
    int foundVertWalHit = 0;
    double initY = 0;
    double initX = 0;
    double stepY = 0;
    double stepX = 0;
    initX = floor(game->p_pos.x / TILE_SIZE) * TILE_SIZE;
    initX += data->facing_right ? TILE_SIZE : 0;
    initY = game->p_pos.y + ((initX - game->p_pos.x) * tan(ray->angle_ray));

    stepX = TILE_SIZE;
    (data->facing_left) && (stepX *= -1);
    stepY = TILE_SIZE * tan(ray->angle_ray);
    stepY *= (data->facing_up && stepY > 0) ? -1 : 1;
    stepY *= (data->facing_down && stepY < 0) ? -1 : 1;

    double_t step_next_x = initX;
    double_t step_next_y = initY;
    if (data->facing_left)
        step_next_x--;
    while ((step_next_x >= 0 &&  step_next_x <= game->w * TILE_SIZE) && (step_next_y >= 0 && step_next_y <= game->h * TILE_SIZE))
    {
        if (hasWallAt(step_next_x,step_next_y,game))
        {
            foundVertWalHit = 1;
            ray->coord_hit_v.x = step_next_x;
            ray->coord_hit_v.y = step_next_y;
            // _daa_line(game->p_pos.x, game->p_pos.y, ray->coord_hit_v.x, ray->coord_hit_v.y, game);
            break ;
        }
        step_next_x += stepX;
        step_next_y += stepY;
    }
    if (foundVertWalHit)
        return (dis_betweenTopoints(game->p_pos.x,game->p_pos.y,ray->coord_hit_v.x,ray->coord_hit_v.y));
    return (INT_MAX);
}

void castRay(__rays_ *ray,t_game *game,__globl_ *data)
{
    ray_facing(ray, data);
    double_t hor_dis = horizontal_distance(game,ray,data);
    double_t ver_dis = vertical_distance(game,ray,data);
    if (hor_dis < ver_dis)
    {
        ray->coord_hit.x = ray->coord_hit_h.x;
        ray->coord_hit.y = ray->coord_hit_h.y;
        ray->distance = hor_dis;
    }
    else
    {
        ray->coord_hit.x = ray->coord_hit_v.x;
        ray->coord_hit.y = ray->coord_hit_v.y;
        ray->distance= ver_dis;
    }
    _daa_line(game->p_pos.x, game->p_pos.y, ray->coord_hit.x, ray->coord_hit.y, game);
}

void    cast_all_rays(t_game *game, __globl_ *data)
{
    double_t initAngle;
    __rays_             *ray;
    __INT32_TYPE__        i;

    data->angle_view =  0;
    (1) && (i = -1, initAngle = data->angle_view - (FOV / 2));
    int num_rays = game->w * TILE_SIZE;
    while (++i < num_rays)
    {
        ray = malloc (sizeof(__rays_));
        initAngle = normalizeAngle(initAngle);
        ray->angle_ray = initAngle;
        castRay(ray, game, data);

        initAngle += FOV / num_rays;
        free(ray);
    }
}
