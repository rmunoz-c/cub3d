/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-29 17:42:26 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-10-29 17:42:26 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*get_texture_path(char *line)
{
	char	*start;
	char	*end;
	size_t	len;

	start = line + 2;
	while (*start == ' ' || *start == '\t')
		start++;
	if (*start == '\0')
		return (NULL);
	end = start;
	while (*end && *end != '\n' && *end != '\r')
		end++;
	while (end > start && (end[-1] == ' ' || end[-1] == '\t'))
		end--;
	len = (size_t)(end - start);
	if (len == 0)
		return (NULL);
	return (ft_substr(start, 0, len));
}

static int	assign_texture(char **texture_field, char *path)
{
	if (*texture_field)
		return (0);
	*texture_field = path;
	return (1);
}

int	set_texture(t_game *game, char *prefix, char *path)
{
	if (ft_strncmp(prefix, "NO", 2) == 0)
		return (assign_texture(&game->no_texture, path));
	else if (ft_strncmp(prefix, "SO", 2) == 0)
		return (assign_texture(&game->so_texture, path));
	else if (ft_strncmp(prefix, "WE", 2) == 0)
		return (assign_texture(&game->we_texture, path));
	else if (ft_strncmp(prefix, "EA", 2) == 0)
		return (assign_texture(&game->ea_texture, path));
	return (0);
}

int	parse_texture(t_game *game, char *line)
{
	char	*path;

	if (!(line[0] && line[1]))
		return (0);
	if (line[2] != ' ' && line[2] != '\t')
		return (0);
	path = get_texture_path(line);
	if (!path)
		return (0);
	if (!set_texture(game, line, path))
	{
		free(path);
		return (0);
	}
	return (1);
}

int	can_open_readonly(const char *p)
{
	int	fd;

	fd = open(p, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}