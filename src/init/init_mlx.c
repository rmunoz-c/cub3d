/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:00:03 by enogueir          #+#    #+#             */
/*   Updated: 2025/11/10 16:35:50 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


int	init_mlx(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		return (err("mlx_init failed"));
	g->win = mlx_new_window(g->mlx, WIDTH, HEIGHT, "Cub3D");
	if (!g->win)
		return (err("mlx_new_window failed"));
	g->screen.ptr = mlx_new_image(g->mlx, WIDTH, HEIGHT);
	if (!g->screen.ptr)
		return (err("mlx_new_image failed"));
	g->screen.data = (int *)mlx_get_data_addr(
			g->screen.ptr,
			&g->screen.bpp,
			&g->screen.line_len,
			&g->screen.endian);
	if (!g->screen.data)
		return (err("mlx_get_data_addr failed"));
	g->screen.w = WIDTH;
	g->screen.h = HEIGHT;
	return (0);
}
