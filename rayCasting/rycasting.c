#include "../includes/cub3d.h"


static void    ray_facing(t_rays *ray)
{
    ray->facing_down = ray->angle_veiw > 0 && ray->angle_veiw < PI;
    ray->facing_up = !ray->facing_down;
    ray->facing_right = ray->angle_veiw < 0.5 * PI || ray->angle_veiw > 1.5 * PI;
    ray->facing_left = !ray->facing_right;
}

dir_views (int angle)
{
    if (angle > 90 && angle <)
}

int calcAngle()
{
    return ();
}

void castray (t_game *game)
{
    int angle_init = calcAngle();
}