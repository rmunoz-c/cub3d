/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-10 16:03:41 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-11-10 16:03:41 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	tex_sample(t_game *game, int id, int x, int y)
{
	t_texture	*tex;
	int			color;

	if (id == DIR_NORTH)
		tex = &game->no;
	else if (id == DIR_SOUTH)
		tex = &game->so;
	else if (id == DIR_WEST)
		tex = &game->we;
	else
		tex = &game->ea;
	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0);
	color = *(int *)(tex->data + (y * tex->line_len + x * (tex->bpp / 8)));
	return (color);
}
