/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:51:17 by enogueir          #+#    #+#             */
/*   Updated: 2025/11/11 19:34:05 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	validate_cub_extension(const char *path)
{
	char	*dot;

	if (!path)
		return (err("No map path"));
	dot = ft_strrchr(path, '.');
	if (!dot || ft_strcmp(dot, ".cub") != 0)
		return (err("Invalid file extension"));
	return (1);
}

static int	check_file_openable(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (err("Cannot open map file"));
	if (close(fd) < 0)
		return (err("Cannot close map file"));
	return (1);
}

static int	init_all(t_game *g, const char *path)
{
	if (!parse_scene(g, path))
		return (err("Parse failed"));
	if (init_mlx(g) == -1)
		return (err("MLX init failed"));
	if (!init_textures(g))
		return (err("Textures init failed"));
	if (init_player(g) == -1)
		return (err("Player init failed"));
	set_hooks(g);
	return (1);
}

int	cub3d_run(const char *path)
{
	t_game	g;

	init_game(&g);
	if (!validate_cub_extension(path))
	{
		cub_cleanup(&g);
		return (1);
	}
	if (!check_file_openable(path))
	{
		cub_cleanup(&g);
		return (1);
	}
	if (!init_all(&g, path))
	{
		cub_cleanup(&g);
		return (1);
	}
	mlx_loop(g.mlx);
	cub_cleanup(&g);
	return (0);
}
