/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_sliding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-11 16:29:10 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-11-11 16:29:10 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static double	binary_search_safe_distance(t_game *g, t_vec2d pos, t_vec2d d)
{
	double	low;
	double	high;
	double	safe;
	double	mid;

	low = 0.0;
	high = 1.0;
	safe = 0.0;
	while (high - low > EPS)
	{
		mid = 0.5 * (low + high);
		if (!is_wall(g, pos.x + d.x * mid, pos.y + d.y * mid))
		{
			safe = mid;
			low = mid;
		}
		else
			high = mid;
	}
	return (safe);
}

static double	find_safe_distance(t_game *g, t_vec2d pos, t_vec2d d)
{
	return (binary_search_safe_distance(g, pos, d));
}

static void	handle_remaining_movement(t_game *g, double dx, double dy, double t)
{
	double	rx;
	double	ry;

	rx = dx * (1.0 - t);
	ry = dy * (1.0 - t);
	if (fabs(rx) > EPS || fabs(ry) > EPS)
		try_smooth_move(g, rx, ry);
}

void	apply_wall_sliding(t_game *g, double dx, double dy)
{
	t_vec2d	pos;
	t_vec2d	d;
	double	t;

	pos = g->player.pos;
	d.x = dx;
	d.y = dy;
	t = find_safe_distance(g, pos, d);
	if (t > EPS)
	{
		g->player.pos.x += dx * t;
		g->player.pos.y += dy * t;
		handle_remaining_movement(g, dx, dy, t);
	}
	else
		try_smooth_move(g, dx, dy);
}
