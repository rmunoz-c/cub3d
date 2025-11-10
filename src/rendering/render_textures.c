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

#include "../../includes/struct.h"

int	tex_sample(t_game *game, int id, int x, int y)
{
	if (id < 0 || id >= 4)
		return (0);
	if (x < 0 || x >= TEX_SIZE || y < 0 || y >= TEX_SIZE)
		return (0);
	if (id == DIR_NORTH)
		return (game->no.data[y * TEX_SIZE + x]);
	else if (id == DIR_SOUTH)
		return (game->so.data[y * TEX_SIZE + x]);
	else if (id == DIR_WEST)
		return (game->we.data[y * TEX_SIZE + x]);
	else
		return (game->ea.data[y * TEX_SIZE + x]);
}
