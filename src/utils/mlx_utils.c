/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:49:23 by enogueir          #+#    #+#             */
/*   Updated: 2025/11/11 18:16:38 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	img_create(void *mlx, t_img *img, int w, int h)
{
	img->ptr = mlx_new_image(mlx, w, h);
	if (!img->ptr)
		return (0);
	img->data = (int *)mlx_get_data_addr(img->ptr,
			&img->bpp, &img->line_len, &img->endian);
	if (!img->data)
	{
		mlx_destroy_image(mlx, img->ptr);
		img->ptr = NULL;
		return (0);
	}
	img->w = w;
	img->h = h;
	return (1);
}

static void	free_map(t_game *g)
{
	int	y;

	if (!g->map.grid)
		return ;
	y = 0;
	while (y < g->map.h)
	{
		free(g->map.grid[y]);
		y++;
	}
	free(g->map.grid);
	g->map.grid = NULL;
}

static void	destroy_texture(void *mlx, t_texture *t)
{
	if (t->img_ptr)
	{
		mlx_destroy_image(mlx, t->img_ptr);
		t->img_ptr = NULL;
	}
	t->data = NULL;
}

static void	free_texture_paths(t_game *g)
{
	free(g->no_texture);
	free(g->so_texture);
	free(g->we_texture);
	free(g->ea_texture);
	g->no_texture = NULL;
	g->so_texture = NULL;
	g->we_texture = NULL;
	g->ea_texture = NULL;
}

void	cub_cleanup(t_game *g)
{
	if (!g)
		return ;
	free_map(g);
	free_texture_paths(g);
	if (g->mlx)
	{
		destroy_texture(g->mlx, &g->no);
		destroy_texture(g->mlx, &g->so);
		destroy_texture(g->mlx, &g->we);
		destroy_texture(g->mlx, &g->ea);
		if (g->screen.ptr)
			mlx_destroy_image(g->mlx, g->screen.ptr);
		if (g->win)
			mlx_destroy_window(g->mlx, g->win);
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
}
