/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_floor_ceiling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-10 15:58:32 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-11-10 15:58:32 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"

void	render_floor_ceiling(t_game *game)
{
	int	y;
	int	x;
	int	color;
	int	*dst;

	y = 0;
	while (y < WIN_H)
	{
		color = game->ceiling_color;
		if (y >= WIN_H / 2)
			color = game->floor_color;
		x = 0;
		while (x < WIN_W)
		{
			dst = game->screen.data
				+ y * (game->screen.line_len / 4) + x;
			*dst = color;
			x++;
		}
		y++;
	}
}