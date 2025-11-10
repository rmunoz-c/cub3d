/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-10 15:55:13 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-11-10 15:55:13 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"

int	dda_step(t_game *game, t_ray *ray)
{
	if (ray->side.x < ray->side.y)
	{
		ray->side.x += ray->delta.x;
		ray->map_x += ray->step_x;
		ray->side_hit = 0;
	}
	else
	{
		ray->side.y += ray->delta.y;
		ray->map_y += ray->step_y;
		ray->side_hit = 1;
	}
	if (game->map.grid[ray->map_y][ray->map_x] == '1')
		return (1);
	return (0);
}

void	dda_distance(t_game *game, t_ray *ray)
{
	if (ray->side_hit == 0)
		ray->dist = (ray->map_x - game->player.pos.x
				+ (1 - ray->step_x) * 0.5) / ray->dir.x;
	else
		ray->dist = (ray->map_y - game->player.pos.y
				+ (1 - ray->step_y) * 0.5) / ray->dir.y;
	ray->dist = fabs(ray->dist);
	if (ray->dist < EPS)
		ray->dist = EPS;
}
