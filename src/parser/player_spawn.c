/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_spawn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:54:37 by enogueir          #+#    #+#             */
/*   Updated: 2025/11/03 19:08:05 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_player_char(char c)
{
	if (c == 'N' || c == 'S')
		return (1);
	if (c == 'E' || c == 'W')
		return (1);
	return (0);
}

static int	set_player_position(t_map *m, t_game *g, int x, int y)
{
	g->player_x = x + 0.5;
	g->player_y = y + 0.5;
	g->player_dir = m->grid[y][x];
	m->grid[y][x] = '0';
	return (1);
}

int	extract_player_spawn(t_map *m, t_game *g)
{
	int	y;
	int	x;
	int	found;

	y = 0;
	found = 0;
	while (y < m->h)
	{
		x = 0;
		while (x < m->w)
		{
			if (is_player_char(m->grid[y][x]))
			{
				if (found)
					return (err("Multiple players"));
				found = set_player_position(m, g, x, y);
			}
			x++;
		}
		y++;
	}
	if (!found)
		return (err("No player"));
	return (1);
}
