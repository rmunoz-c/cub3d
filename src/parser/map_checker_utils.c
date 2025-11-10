/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:26:38 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025/11/03 19:00:00 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	has_only_valid_chars(const t_map *m)
{
	int	y;
	int	x;

	y = 0;
	while (y < m->h)
	{
		x = 0;
		while (x < m->w)
		{
			if (!is_valid_char(m->grid[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_map(t_game *game)
{
	int	players;

	if (!has_only_valid_chars(&game->map))
		return (0);
	players = count_players(&game->map);
	if (players != 1)
		return (0);
	set_player(game);
	if (!validate_map_closed(game))
		return (0);
	return (1);
}

int	is_empty_line(const char *s)
{
	int	i;

	if (!s)
		return (1);
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\r')
		i++;
	return (s[i] == '\0' || s[i] == '\n');
}
