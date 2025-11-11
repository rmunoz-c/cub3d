/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_subdiv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-11 16:31:20 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-11-11 16:31:20 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	subdivide_movement_steps(t_game *g,
		double total_dx, double total_dy, int steps)
{
	const double	step_dx = total_dx / (double)steps;
	const double	step_dy = total_dy / (double)steps;
	int				i;

	i = 0;
	while (i < steps)
	{
		apply_wall_sliding(g, step_dx, step_dy);
		i++;
	}
}

void	subdiv_move(t_game *g, double total_dx, double total_dy)
{
	double	dist;
	int		steps;

	if (fabs(total_dx) < EPS && fabs(total_dy) < EPS)
		return ;
	if (!is_wall(g, g->player.pos.x + total_dx,
			g->player.pos.y + total_dy))
	{
		g->player.pos.x += total_dx;
		g->player.pos.y += total_dy;
		return ;
	}
	dist = sqrt(total_dx * total_dx + total_dy * total_dy);
	if (dist <= MAX_MOVE_STEP)
	{
		apply_wall_sliding(g, total_dx, total_dy);
		return ;
	}
	steps = (int)ceil(dist / MAX_MOVE_STEP);
	if (steps < 1)
		steps = 1;
	subdivide_movement_steps(g, total_dx, total_dy, steps);
}
