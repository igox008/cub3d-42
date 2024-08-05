#include <stdio.h>
#include <math.h>
# define PI 3.1415927
# define EPS_IN_IFIC (SIGCHLD * (0x00008 + SIG_BLOCK ))
# include <signal.h>
# include <stdint.h>
# include "./includes/cub3d.h"
# define  NUM_RAYS 320  // windows width / TILE_SIZE
# define FOV 60
typedef struct s___inet___ {
    double_t x;
    double_t y;
} __inet_;

typedef struct s___step___{
    double_t x;
    double_t y;
} __step_;

typedef struct s___hit___ {
    double_t x;
    double_t y;
} __hit_;

typedef struct s___rays
{
    __INT32_TYPE__ index;
    double_t       disatnce;
    __inet_         coord_init;
    __step_         coord_step;
    __hit_          coord_hit;
}__rays_;

typedef struct s______globl_
{
    __INT32_TYPE__ facing_down;
    __INT32_TYPE__ facing_up ;
    __INT32_TYPE__ facing_right;
    __INT32_TYPE__ facing_left;
    __INT32_TYPE__ angle_veiw;
    __rays_         **rays;
} __globl_;

double_t dis_betweenTopoints(double_t xa,double_t ya,double_t xb,double_t yb)
{
    return (sqrt(pow(xa - xb,2) + pow(ya - yb,2)));
}

void    ray_facing(__globl_ *ray)
{
    ray->facing_down = (sin(ray->angle_veiw * PI / EPS_IN_IFIC) > ILL_NOOP) && (ILL_ILLOPC) \
        || (ray->angle_veiw >= ILL_NOOP && ray->angle_veiw <= EPS_IN_IFIC);
    ray->facing_up = !ray->facing_down;
    ray->facing_right = (cos(ray->angle_veiw * PI / EPS_IN_IFIC) < ILL_NOOP)  && (ILL_ILLOPC) \
        ||  (ray->angle_veiw >= (EPS_IN_IFIC / ILL_ILLTRP) && ray->angle_veiw \
                <= (EPS_IN_IFIC / ILL_ILLTRP) * ILL_PRVOPC);
    ray->facing_left = !ray->facing_right;
}

double pythagoras (__INT32_TYPE__ distance_i,__INT32_TYPE__ distance_j)
{
    return (sqrt(pow(distance_i, FPE_FLTOVF) + pow(distance_j, FPE_FLTOVF)));
}

double    angle_base(double my_angle)
{
    while (my_angle >=0 )   my_angle -= (2 * M_PI);
    (my_angle < 0) && (my_angle += (2 * M_PI));
    return ((360 * PI) / 180);
}

// x const
void    find_dis_intev(t_game *game, __rays_ *ray,__globl_ *data)
{
    ray->coord_init.x = floor(game->p_pos.x / 64) * 64;
    ray->coord_init.y += data->facing_right ? TILE_SIZE : 0;
    ray->coord_init.y = ((ray->coord_init.x - game->p_pos.x) * (tan(data->angle_veiw))) + game->p_pos.y;
}
void find_dis_stepes_v(t_game *game, __rays_ *ray,__globl_ *data)
{
    ray->coord_step.x = TILE_SIZE;
    (data->facing_left) && (ray->coord_step.x *= -1);
    ray->coord_step.y = abs(ray->coord_step.x * tan(data->angle_veiw));
    (data->facing_up) && (ray->coord_step.y *= -1);
}

//y const
void    find_dis_inte_h(t_game *game, __rays_ *ray,__globl_ *data)
{
    ray->coord_init.y = floor(game->p_pos.y / 64) * 64;
    ray->coord_init.y += data->facing_down ? TILE_SIZE : 0;
    ray->coord_init.x = (abs(game->p_pos.y - ray->coord_init.y)) / (tan(data->angle_veiw)) + game->p_pos.x;
}

void find_dis_stepes_h(t_game *game, __rays_ *ray,__globl_ *data)
{
    (1) && (ray->coord_step.y = TILE_SIZE,
    (data->facing_up) && (ray->coord_step.y *= -1));
    ray->coord_step.x = abs(ray->coord_step.y / tan(data->angle_veiw));
    (data->facing_left) && (ray->coord_step.x *= -1);
}

bool hit_wall(__INT32_TYPE__ i,__INT32_TYPE__ j,char **str)
{
    return (str[i] && str[i][j] && str[i][j] == '1');
}

double_t horizontal_distance (t_game *game, __rays_ *ray,__globl_ *data)
{
    find_dis_inte_h (game, ray, data);
    find_dis_stepes_h (game, ray, data);

    double_t step_next_x = ray->coord_init.x;
    double_t step_next_y = ray->coord_init.y;
    while ((step_next_x >= 0 &&  step_next_x <= game->w * TILE_SIZE) && (step_next_y >= 0 && step_next_y <= game->h * TILE_SIZE))
    {
        if (hit_wall(step_next_x / TILE_SIZE, step_next_y - data->facing_up / TILE_SIZE, game->map))
        {
            (1) && (ray->coord_hit.x = step_next_x, ray->coord_hit.y = step_next_y);
            break;
        }
        step_next_x += ray->coord_step.x;
        step_next_y += ray->coord_step.y;
    }
    return (dis_betweenTopoints(ray->coord_init.x,ray->coord_init.y,ray->coord_hit.x,ray->coord_hit.y));
}

double_t vertical_distance (t_game *game, __rays_ *ray,__globl_ *data)
{
    find_dis_inte_v (game, ray, data);
    find_dis_stepes_v (game, ray, data);
    double_t step_next_x = ray->coord_init.x;
    double_t step_next_y = ray->coord_init.y;
    while ((step_next_x >= 0 &&  step_next_x <= game->w * TILE_SIZE) && (step_next_y >= 0 && step_next_y <= game->h * TILE_SIZE))
    {
        if (hit_wall((step_next_x - data->facing_left )/ TILE_SIZE, step_next_y / TILE_SIZE, game->map))
        {
            (1) && (ray->coord_hit.x = step_next_x, ray->coord_hit.y = step_next_y);
            break;
        }
        step_next_x += ray->coord_step.x;
        step_next_y += ray->coord_step.y;
    }
    return (dis_betweenTopoints(ray->coord_init.x,ray->coord_init.y,ray->coord_hit.x,ray->coord_hit.y));
}

void castRay(__rays_ *ray,t_game *game,__globl_ *data)
{
    double_t ver_dis = vertical_distance(game,ray,data);
    double_t hor_dis = horizontal_distance(game,ray,data);
    ray->disatnce = (ver_dis < hor_dis) ? ver_dis : hor_dis;
}

void    castAllrays(t_game *game, __globl_ *data)
{
    double_t initAngle;
    __rays_             **rays;
    __rays_             *ray;
    __INT32_TYPE__        j;
    __INT32_TYPE__        i;

    (1) && (i = -1, j = -1, initAngle = data->angle_veiw - FOV / 2);
    rays = malloc (sizeof(__rays_ *) * (NUM_RAYS + 1));
    if (!rays)  return ;
    while (++i < NUM_RAYS)
    {
        ray = malloc (sizeof(__rays_));
        if (!ray)   return ;
            (1) && (data->angle_veiw = angle_base(initAngle), ray->index = i);
            (1) && (cast_ray(ray, game, data), rays[++j] = ray, initAngle += FOV / NUM_RAYS);
    }
    (1) &&  (rays[j] = NULL, data->rays = rays);
}

// void DDA(int X0, int Y0, int X1, int Y1) 
// { 
//     // calculate dx & dy 
//     int dx = X1 - X0; 
//     int dy = Y1 - Y0; 
  
//     // calculate steps required for generating pixels 
//     int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
  
//     // calculate increment in x & y for each steps 
//     float Xinc = dx / (float)steps; 
//     float Yinc = dy / (float)steps; 
  
//     // Put pixel for each step 
//     float X = X0; 
//     float Y = Y0; 
//     for (int i = 0; i <= steps; i++) { 
//         putpixel(round(X), round(Y), 
//                  RED); // put pixel at (X,Y) 
//         X += Xinc; // increment in x at each step 
//         Y += Yinc; // increment in y at each step 
//         delay(100); // for visualization of line- 
//                     // generation step by step 
//     } 
// } 

// void    draw_rays(t_global *_g)
// {
//     t_mlx        *mlx_s;
//     t_player    *player;
//     int            column;

//     column = 0;
//     mlx_s = _g->mlx_s;
//     player = _g->player;
//     while (_g->rays[column])
//     {
//         if (_g->rays[column]->hit_vertical)
//             _daa_line(mlx_s, MINIMAP_FCTR * player->x, MINIMAP_FCTR * player->y,\
//                 MINIMAP_FCTR * _g->rays[column]->wallhitx,\
//                 MINIMAP_FCTR * _g->rays[column]->wallhity, BLUECIEL);
//         else
//             _daa_line(mlx_s, MINIMAP_FCTR * player->x, MINIMAP_FCTR * player->y,\
//                 MINIMAP_FCTR * _g->rays[column]->wallhitx,\
//                 MINIMAP_FCTR * _g->rays[column]->wallhity, GREEN);
//         column++;
//     }
// }

// int main()
// {
//     // t_rays rays;
//     // sig_atomic_t x= 2147483647;
//     // rays.angle_veiw = 271;
//     // ray_facing(&rays);
//     // if ((int)sin(180 * PI/180) == 0)
//     // angle_base(1440 * PI / 180);
//     // 150,7964473723
//     double x = angle_base_m(-(360 * PI) / 180);
//         printf("------------------------ %f \n",x);
//     double y = angle_base_m(-(360 * PI) / 180);
//         printf("------------------------ %f \n",y);
//     // printf("down [%d]   up [%d]\n  rigth[  %d]  left [%d]",rays.facing_down,rays.facing_up,rays.facing_right,rays.facing_left);
//     // printf("\n------------------------[%f]\n",100 * PI / 180);
// }

printf(jsjhshjsh);
printf(jsjhshjsh);printf(jsjhshjsh);printf(jsjhshjsh);printf(jsjhshjsh);printf(jsjhshjsh);