/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:27:01 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025/11/03 19:00:48 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ')
		return (1);
	return (0);
}

int	count_players(t_map *m)
{
	int	y;
	int	x;
	int	count;

	count = 0;
	y = 0;
	while (y < m->h)
	{
		x = 0;
		while (x < m->w)
		{
			if (m->grid[y][x] == 'N' || m->grid[y][x] == 'S'
				|| m->grid[y][x] == 'E' || m->grid[y][x] == 'W')
			{
				count++;
				if (count > 1)
					return (count);
			}
			x++;
		}
		y++;
	}
	return (count);
}

void	set_player(t_game *game)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < game->map.h)
	{
		x = 0;
		while (x < game->map.w)
		{
			c = game->map.grid[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				game->player_x = x;
				game->player_y = y;
				game->player_dir = c;
				return ;
			}
			x++;
		}
		y++;
	}
}

static int	is_surrounded(t_map *m, int y, int x)
{
	if (y <= 0 || y >= m->h - 1 || x <= 0 || x >= m->w - 1)
		return (0);
	if (m->grid[y - 1][x] == ' ' || m->grid[y + 1][x] == ' ' || m->grid[y][x
		- 1] == ' ' || m->grid[y][x + 1] == ' ' || m->grid[y - 1][x] == '\t'
		|| m->grid[y + 1][x] == '\t' || m->grid[y][x - 1] == '\t'
		|| m->grid[y][x + 1] == '\t' || m->grid[y - 1][x] == '\r' || m->grid[y
		+ 1][x] == '\r' || m->grid[y][x - 1] == '\r' || m->grid[y][x
		+ 1] == '\r')
		return (0);
	return (1);
}

int	validate_map_closed(t_game *game)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < game->map.h)
	{
		x = 0;
		while (x < game->map.w)
		{
			c = game->map.grid[y][x];
			if ((c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
				&& !is_surrounded(&game->map, y, x))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
