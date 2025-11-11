/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-11 16:33:22 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-11-11 16:33:22 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	try_move_x(t_game *g, double dx)
{
	double	nx;

	if (fabs(dx) < EPS)
		return ;
	nx = g->player.pos.x + dx;
	if (!is_wall(g, nx, g->player.pos.y))
		g->player.pos.x = nx;
}

static void	try_move_y(t_game *g, double dy)
{
	double	ny;

	if (fabs(dy) < EPS)
		return ;
	ny = g->player.pos.y + dy;
	if (!is_wall(g, g->player.pos.x, ny))
		g->player.pos.y = ny;
}

void	try_smooth_move(t_game *g, double dx, double dy)
{
	try_move_x(g, dx);
	try_move_y(g, dy);
}

int	check_collision_corners(t_game *g, double x, double y, double r)
{
	if (is_point_wall(g, x - r, y - r)
		|| is_point_wall(g, x + r, y - r)
		|| is_point_wall(g, x - r, y + r)
		|| is_point_wall(g, x + r, y + r))
		return (1);
	return (0);
}
