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

static int	set_map_first_skip_empty(int fd, char **out)
{
	char	*l;

	l = get_next_line(fd);
	while (l && (l[0] == '\n' || l[0] == '\r'))
	{
		free(l);
		l = get_next_line(fd);
	}
	if (!l)
		return (0);
	*out = l;
	return (1);
}

static int	handle_non_header_line(int fd, t_game *g,
									char *line, char **map_first)
{
	if (!header_complete(g))
	{
		if (!is_empty_line(line))
		{
			free(line);
			return (err("Header incomplete before map"));
		}
		free(line);
		return (0);
	}
	if (is_empty_line(line))
	{
		free(line);
		if (!set_map_first_skip_empty(fd, map_first))
			return (err("Missing map"));
		return (1);
	}
	*map_first = line;
	return (1);
}

int	scan_header(int fd, t_game *g, char **map_first)
{
	char	*line;
	int		r;
	int		h;

	*map_first = NULL;
	while ((line = get_next_line(fd)))
	{
		r = parse_header_line(g, line);
		if (r == 2)
		{
			free(line);
			if (!set_map_first_skip_empty(fd, map_first))
				return (err("Missing map"));
			return (1);
		}
		if (r != 1)
		{
			h = handle_non_header_line(fd, g, line, map_first);
			if (h == 0)
				continue ;
			return (h > 0);
		}
		free(line);
	}
	return (err("Missing identifiers (NO, SO, WE, EA, F, C)"));
}
