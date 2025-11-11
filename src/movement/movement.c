/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-11 16:06:54 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-11-11 16:06:54 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rotate_player(t_player *p, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir.x;
	old_plane_x = p->plane.x;
	p->dir.x = old_dir_x * cos(angle) - p->dir.y * sin(angle);
	p->dir.y = old_dir_x * sin(angle) + p->dir.y * cos(angle);
	p->plane.x = old_plane_x * cos(angle) - p->plane.y * sin(angle);
	p->plane.y = old_plane_x * sin(angle) + p->plane.y * cos(angle);
}

static void	calculate_movement_wasd(t_game *g, double *dx, double *dy)
{
	if (g->keys.w)
	{
		*dx += g->player.dir.x * MOVE_SPEED;
		*dy += g->player.dir.y * MOVE_SPEED;
	}
	if (g->keys.s)
	{
		*dx -= g->player.dir.x * MOVE_SPEED;
		*dy -= g->player.dir.y * MOVE_SPEED;
	}
	if (g->keys.a)
	{
		*dx += g->player.dir.y * MOVE_SPEED;
		*dy -= g->player.dir.x * MOVE_SPEED;
	}
	if (g->keys.d)
	{
		*dx -= g->player.dir.y * MOVE_SPEED;
		*dy += g->player.dir.x * MOVE_SPEED;
	}
}

static void	handle_rotation(t_game *g)
{
	if (g->keys.left)
		rotate_player(&g->player, -ROT_SPEED);
	if (g->keys.right)
		rotate_player(&g->player, ROT_SPEED);
}

int	movement_update(t_game *g)
{
	double	total_dx;
	double	total_dy;

	total_dx = 0.0;
	total_dy = 0.0;
	calculate_movement_wasd(g, &total_dx, &total_dy);
	if (fabs(total_dx) > MIN_MOVE_DISTANCE || fabs(total_dy) > MIN_MOVE_DISTANCE)
		subdiv_move(g, total_dx, total_dy);
	handle_rotation(g);
	return (0);
}
