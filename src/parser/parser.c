/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:26:45 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025/11/03 18:59:21 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	open_scene_fd(const char *path)
{
	int	fd;

	if (!path)
		return (-1);
	fd = open(path, O_RDONLY);
	return (fd);
}

static int	parse_header_stage(int fd, t_game *g, char **map_first)
{
	if (!scan_header(fd, g, map_first))
		return (0);
	return (1);
}

static int	parse_map_stage(int fd, char *map_first, t_game *g)
{
	char	**lines;
	int		n;

	if (!read_map_lines(fd, map_first, &lines, &n))
		return (0);
	if (!build_map_rect(&g->map, lines, n))
	{
		while (n-- > 0)
			free(lines[n]);
		free(lines);
		return (0);
	}
	while (n-- > 0)
		free(lines[n]);
	free(lines);
	if (!check_map(g))
		return (err("Invalid map"));
	return (1);
}

int	err(const char *msg)
{
	write(2, "Error\n", 6);
	ft_error((char *)msg, FALSE);
	write(2, "\n", 1);
	return (0);
}

int	parse_scene(t_game *g, const char *path)
{
	int		fd;
	char	*map_first;

	if (!g || !path)
		return (0);
	g->floor_color = -1;
	g->ceiling_color = -1;
	fd = open_scene_fd(path);
	if (fd < 0)
		return (err("Cannot open .cub file"));
	if (!parse_header_stage(fd, g, &map_first))
	{
		close(fd);
		return (err("Invalid header"));
	}
	if (!parse_map_stage(fd, map_first, g))
	{
		close(fd);
		return (err("Invalid map block"));
	}
	if (!extract_player_spawn(&g->map, g))
		return (0);
	close(fd);
	return (1);
}
