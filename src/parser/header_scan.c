/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_scan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-29 20:06:45 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-10-29 20:06:45 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_empty_line(const char *s)
{
	int	i;

	if (!s)
		return (1);
	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	return (s[i] == '\0' || s[i] == '\n');
}

static int	header_complete(const t_game *g)
{
	if (!g)
		return (0);
	if (!g->no_texture || !g->so_texture || !g->we_texture || !g->ea_texture)
		return (0);
	if (g->floor_color == -1 || g->ceiling_color == -1)
		return (0);
	return (1);
}

static int	parse_header_line(t_game *g, const char *line)
{
	if (!line)
		return (-1);
	if (is_empty_line(line))
		return (1);
	if (parse_texture(g, (char *)line))
	{
		if (header_complete(g))
			return (2);
		return (1);
	}
	if (parse_floor_color(g, line))
	{
		if (header_complete(g))
			return (2);
		return (1);
	}
	if (parse_ceiling_color(g, line))
	{
		if (header_complete(g))
			return (2);
		return (1);
	}
	return (0);
}

int	scan_header(int fd, t_game *g, char **map_first)
{
	char	*line;
	int		r;

	*map_first = NULL;
	while ((line = get_next_line(fd)))
	{
		r = parse_header_line(g, line);
		if (r == 2)
		{
			*map_first = get_next_line(fd);
			return (free(line), 1);
		}
		if (r != 1 && !is_empty_line(line))
		{
			if (!header_complete(g))
				return (free(line), err("Header incomplete before map"));
			*map_first = line;
			return (1);
		}
		free(line);
	}
	return (err("Missing identifiers (NO, SO, WE, EA, F, C)"));
}
