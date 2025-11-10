/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:42:26 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025/11/03 17:48:31 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*get_texture_path(char *line)
{
	char	*start;
	char	*end;
	size_t	len;

	if (!line || !line[0] || !line[1])
        return (NULL);
	start = line + 2;
	while (*start == ' ' || *start == '\t')
		start++;
	if (*start == '\0')
		return (NULL);
	end = start;
	while (*end && *end != '\n' && *end != '\r')
		end++;
	while (end > start && (end[-1] == ' ' ||
			end[-1] == '\t' || end[-1] == '\n' || end[-1] == '\r'))
		end--;
	len = (size_t)(end - start);
	if (len == 0)
		return (NULL);
	return (ft_substr(start, 0, len));
}

static int	assign_texture(char **texture_field, char *path)
{
	if (*texture_field)
	{
		free(path);
		return (0);
	}
	*texture_field = path;
	return (1);
}

int	set_texture(t_game *game, const char *line, char *path)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (ft_strncmp(line, "NO", 2) == 0 && (line[2] == ' ' || line[2] == '\t'))
		return (assign_texture(&game->no_texture, path));
	if (ft_strncmp(line, "SO", 2) == 0 && (line[2] == ' ' || line[2] == '\t'))
		return (assign_texture(&game->so_texture, path));
	if (ft_strncmp(line, "WE", 2) == 0 && (line[2] == ' ' || line[2] == '\t'))
		return (assign_texture(&game->we_texture, path));
	if (ft_strncmp(line, "EA", 2) == 0 && (line[2] == ' ' || line[2] == '\t'))
		return (assign_texture(&game->ea_texture, path));
	free(path);
	return (0);
}

int parse_texture(t_game *game, char *line)
{
    char *path;

    if (!line)
        return (0);

    while (*line == ' ' || *line == '\t')
        line++;
    if (!(*line && *(line + 1)))
        return (0);
    if (*(line + 2) != ' ' && *(line + 2) != '\t')
        return (0);
    path = get_texture_path(line);
    if (!path)
        return (0);
    if (!set_texture(game, line, path))
        return (0);
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
