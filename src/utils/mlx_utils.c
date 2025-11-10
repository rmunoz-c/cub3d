/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:49:23 by enogueir          #+#    #+#             */
/*   Updated: 2025/11/03 18:50:23 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	img_create(void *mlx, t_img *img, int w, int h)
{
	img->ptr = mlx_new_image(mlx, w, h);
	if (img->ptr == NULL)
		return (-1);
	img->data = (int *)mlx_get_data_addr(img->ptr, &img->bpp, &img->line_len,
			&img->endian);
	if (img->data == NULL)
		return (-1);
	img->w = w;
	img->h = h;
	return (0);
}

void	cub_cleanup(t_game *g)
{
	if(!g)
		return ;
	if (g->screen.ptr != NULL)
		mlx_destroy_image(g->mlx, g->screen.ptr);
	if (g->win != NULL)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx != NULL)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
}

int	exit_program(void *param)
{
	t_game	*g;

	g = (t_game *)param;
	cub_cleanup(g);
	exit(0);
	return (0);
}
