/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:54:47 by enogueir          #+#    #+#             */
/*   Updated: 2025/11/11 19:17:32 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	load_texture(void *mlx, t_texture *tex, const char *path)
{
	if (!path || !*path)
		return (err("Missing texture path"));
	if (!can_open_readonly(path))
		return (err("Cannot open texture file"));
	tex->img_ptr = mlx_xpm_file_to_image(mlx, (char *)path,
			&tex->width, &tex->height);
	if (!tex->img_ptr)
		return (err("Failed to load texture"));
	tex->data = mlx_get_data_addr(tex->img_ptr, &tex->bpp,
			&tex->line_len, &tex->endian);
	if (!tex->data)
	{
		mlx_destroy_image(mlx, tex->img_ptr);
		tex->img_ptr = NULL;
		return (err("Failed to get texture data"));
	}
	return (1);
}

int	init_textures(t_game *g)
{
	if (!g || !g->mlx)
		return (err("MLX not initialized"));
	if (!load_texture(g->mlx, &g->no, g->no_texture))
		return (0);
	if (!load_texture(g->mlx, &g->so, g->so_texture))
		return (0);
	if (!load_texture(g->mlx, &g->we, g->we_texture))
		return (0);
	if (!load_texture(g->mlx, &g->ea, g->ea_texture))
		return (0);
	return (1);
}
