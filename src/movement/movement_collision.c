/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-11 16:25:35 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-11-11 16:25:35 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_sprite_collision(t_game *g, double x, double y)
{
	(void)g;
	(void)x;
	(void)y;
	return (0);
}

int	is_point_wall(t_game *g, double x, double y)
{
	char	tile;

	if (y < 0 || y >= g->map.h || x < 0 || x >= g->map.w)
		return (1);
	tile = g->map.grid[(int)y][(int)x];
	if (tile == '1')
		return (1);
	return (check_sprite_collision(g, x, y));
}

static int	check_collision_edges(t_game *g, double x, double y, double r)
{
	if (is_point_wall(g, x, y - r)
		|| is_point_wall(g, x, y + r)
		|| is_point_wall(g, x - r, y)
		|| is_point_wall(g, x + r, y))
		return (1);
	return (0);
}

int	is_wall(t_game *g, double x, double y)
{
	const double	r = COLLISION_RADIUS;

	if (x - r < 0 || x + r >= g->map.w || y - r < 0 || y + r >= g->map.h)
		return (1);
	if (is_point_wall(g, x, y))
		return (1);
	if (check_collision_edges(g, x, y, r))
		return (1);
	if (check_collision_corners(g, x, y, r))
		return (1);
	return (0);
}

void	wall_slide_move(t_game *g, double dx, double dy)
{
	double	nx;
	double	ny;

	nx = g->player.pos.x + dx;
	ny = g->player.pos.y + dy;
	if (!is_wall(g, nx, ny))
	{
		g->player.pos.x = nx;
		g->player.pos.y = ny;
		return ;
	}
	if (!is_wall(g, nx, g->player.pos.y))
		g->player.pos.x = nx;
	else if (!is_wall(g, g->player.pos.x, ny))
		g->player.pos.y = ny;
}
