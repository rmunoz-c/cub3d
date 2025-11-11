/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-10 15:47:39 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-11-10 15:47:39 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	set_step_side(t_game *game, t_ray *ray)
{
	if (ray->dir.x < 0.0)
	{
		ray->step_x = -1;
		ray->side.x = (game->player.pos.x - ray->map_x) * ray->delta.x;
	}
	else
	{
		ray->step_x = 1;
		ray->side.x = (ray->map_x + 1.0 - game->player.pos.x) * ray->delta.x;
	}
	if (ray->dir.y < 0.0)
	{
		ray->step_y = -1;
		ray->side.y = (game->player.pos.y - ray->map_y) * ray->delta.y;
	}
	else
	{
		ray->step_y = 1;
		ray->side.y = (ray->map_y + 1.0 - game->player.pos.y) * ray->delta.y;
	}
}

static void	ray_init(t_game *game, t_ray *ray, int x)
{
	double	camera_x;

	camera_x = 2.0 * (double)x / (double)WIN_W - 1.0;
	ray->dir.x = game->player.dir.x + game->player.plane.x * camera_x;
	ray->dir.y = game->player.dir.y + game->player.plane.y * camera_x;
	if (fabs(ray->dir.x) < EPS)
	{
		if (ray->dir.x < 0.0)
			ray->dir.x = -EPS;
		else
			ray->dir.x = EPS;
	}
	if (fabs(ray->dir.y) < EPS)
	{
		if (ray->dir.y < 0.0)
			ray->dir.y = -EPS;
		else
			ray->dir.y = EPS;
	}
	ray->map_x = (int)game->player.pos.x;
	ray->map_y = (int)game->player.pos.y;
	ray->delta.x = fabs(1.0 / ray->dir.x);
	ray->delta.y = fabs(1.0 / ray->dir.y);
	set_step_side(game, ray);
}

static void	set_tex_info(t_game *game, t_ray *ray)
{
	double	wall_x;

	if (ray->side_hit == 0)
		wall_x = game->player.pos.y + ray->dist * ray->dir.y;
	else
		wall_x = game->player.pos.x + ray->dist * ray->dir.x;
	wall_x -= floor(wall_x);
	ray->tex_x = (int)(wall_x * (double)TEX_SIZE);
	if (ray->side_hit == 0 && ray->dir.x > 0.0)
		ray->tex_id = DIR_WEST;
	else if (ray->side_hit == 0)
		ray->tex_id = DIR_EAST;
	else if (ray->dir.y > 0.0)
		ray->tex_id = DIR_NORTH;
	else
		ray->tex_id = DIR_SOUTH;
}

static void	dda(t_game *game, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (!hit)
		hit = dda_step(game, ray);
	dda_distance(game, ray);
}

void	raycaster(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WIN_W)
	{
		ray_init(game, &ray, x);
		dda(game, &ray);
		set_tex_info(game, &ray);
		draw_walls(game, x, &ray);
		x++;
	}
}
