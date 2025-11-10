/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:01:52 by enogueir          #+#    #+#             */
/*   Updated: 2025/11/10 18:48:50 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc != 2)
		return (err("Usage: ./cub3D <map.cub>"));
	init_game(&g);
	if (!parse_scene(&g, argv[1]))
		return (err("Parse failed"));
	if (init_mlx(&g) == -1)
		return (1);
	if (init_player(&g) == -1)
		return (1);
#ifdef DEBUG
	debug_player(&g);
#endif
	set_hooks(&g);
	mlx_loop(g.mlx);
	cub_cleanup(&g);
	return (0);
}
