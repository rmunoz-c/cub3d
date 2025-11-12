/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:51:10 by enogueir          #+#    #+#             */
/*   Updated: 2025/11/03 18:53:00 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_hooks(t_game *g)
{
	mlx_hook(g->win, 2, 1L << 0, key_press, g);
	mlx_hook(g->win, 3, 1L << 1, key_release, g);
	mlx_hook(g->win, 17, 0, exit_program, g);
	mlx_loop_hook(g->mlx, loop_hook, g);
}

int	key_press(int keycode, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (keycode == KEY_ESC)
		exit_program(g);
	else if (keycode == KEY_W)
		g->keys.w = 1;
	else if (keycode == KEY_A)
		g->keys.a = 1;
	else if (keycode == KEY_S)
		g->keys.s = 1;
	else if (keycode == KEY_D)
		g->keys.d = 1;
	else if (keycode == KEY_RIGHT)
		g->keys.right = 1;
	else if (keycode == KEY_LEFT)
		g->keys.left = 1;
	return (0);
}

int	key_release(int keycode, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (keycode == KEY_ESC)
		exit_program(g);
	else if (keycode == KEY_W)
		g->keys.w = 0;
	else if (keycode == KEY_A)
		g->keys.a = 0;
	else if (keycode == KEY_S)
		g->keys.s= 0;
	else if (keycode == KEY_D)
		g->keys.d = 0;
	else if (keycode == KEY_RIGHT)
		g->keys.right = 0;
	else if (keycode == KEY_LEFT)
		g->keys.left = 0;
	return (0);
}

int	exit_program(void *param)
{
	t_game	*g;

	g = (t_game *)param;
	cub_cleanup(g);
	exit(0);
	return (0);
}
