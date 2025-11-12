/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:00:43 by enogueir          #+#    #+#             */
/*   Updated: 2025/11/11 21:00:29 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ensure_screen(t_game *g)
{
	if (!g->screen.ptr)
	{
		if (!img_create(g->mlx, &g->screen, WIDTH, HEIGHT))
			return (-1);
	}
	return (0);
}

static void	update_position(t_game *g, double dx, double dy)
{
	int	nx;
	int	ny;

	if (dx == 0.0 && dy == 0.0)
		return ;
	nx = (int)(g->player.pos.x + dx);
	ny = (int)(g->player.pos.y + dy);
	if (ny >= 0 && ny < g->map.h && nx >= 0 && nx < g->map.w
		&& g->map.grid[ny][nx] != '1')
	{
		g->player.pos.x += dx;
		g->player.pos.y += dy;
	}
}

static void	handle_move(t_game *g)
{
	double	speed;
	double	dx;
	double	dy;

	speed = MOVE_SPEED;
	dx = 0.0;
	dy = 0.0;
	if (g->keys.w)
	{
		dx += g->player.dir.x * speed;
		dy += g->player.dir.y * speed;
	}
	if (g->keys.s)
	{
		dx -= g->player.dir.x * speed;
		dy -= g->player.dir.y * speed;
	}
	if (g->keys.a)
	{
		dx += -g->player.dir.y * speed;
		dy += g->player.dir.x * speed;
	}
	if (g->keys.d)
	{
		dx += g->player.dir.y * speed;
		dy += -g->player.dir.x * speed;
	}
	update_position(g, dx, dy);
}

static void	handle_rotate(t_game *g)
{
	double	rot;
	double	old_dir_x;
	double	old_plane_x;

	if (!g->keys.left && !g->keys.right)
		return ;
	rot = ROT_SPEED;
	if (g->keys.left)
		rot = -rot;
	old_dir_x = g->player.dir.x;
	g->player.dir.x = old_dir_x * cos(rot) - g->player.dir.y * sin(rot);
	g->player.dir.y = old_dir_x * sin(rot) + g->player.dir.y * cos(rot);
	old_plane_x = g->player.plane.x;
	g->player.plane.x = old_plane_x * cos(rot)
		- g->player.plane.y * sin(rot);
	g->player.plane.y = old_plane_x * sin(rot)
		+ g->player.plane.y * cos(rot);
}

int	loop_hook(void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (ensure_screen(g) == -1)
		return (0);
	handle_move(g);
	handle_rotate(g);
	render_floor_ceiling(g);
	raycaster(g);
	mlx_put_image_to_window(g->mlx, g->win, g->screen.ptr, 0, 0);
	return (0);
}