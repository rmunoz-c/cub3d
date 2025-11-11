/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-10 16:00:31 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-11-10 16:00:31 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	put_pixel(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= img->w || y < 0 || y >= img->h)
		return ;
	img->data[y * (img->line_len / 4) + x] = color;
}

static void	draw_slice(t_game *game, t_ray *ray, t_slice *slice)
{
	int	y;
	int	tex_y;
	int	color;

	y = slice->start;
	while (y < slice->end)
	{
		tex_y = (int)slice->tex_pos & (TEX_SIZE - 1);
		color = tex_sample(game, ray->tex_id, ray->tex_x, tex_y);
		if (ray->side_hit == 1)
			color = (color >> 1) & 8355711;
		put_pixel(&game->screen, slice->x, y, color);
		slice->tex_pos += slice->step;
		y++;
	}
}

void	render_walls(t_game *game, int x, t_ray *ray)
{
	int		line_h;
	int		start;
	int		end;
	t_slice	slice;

	line_h = (int)(WIN_H / ray->dist);
	if (line_h < 1)
		line_h = 1;
	start = -line_h / 2 + WIN_H / 2;
	if (start < 0)
		start = 0;
	end = line_h / 2 + WIN_H / 2;
	if (end >= WIN_H)
		end = WIN_H - 1;
	slice.x = x;
	slice.start = start;
	slice.end = end;
	slice.step = (double)TEX_SIZE / line_h;
	slice.tex_pos = (start - WIN_H / 2 + line_h / 2) * slice.step;
	draw_slice(game, ray, &slice);
}
