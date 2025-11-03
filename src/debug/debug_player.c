/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:30:14 by enogueir          #+#    #+#             */
/*   Updated: 2025/11/03 18:53:26 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* src/debug_player.c */
#include "../../includes/cub3d.h"
#include <stdio.h> /* solo debug temporal */

void	debug_player(const t_game *g)
{
	printf("player.pos = (%.2f, %.2f)\n", g->player.pos.x, g->player.pos.y);
	printf("player.dir = (%.2f, %.2f)\n", g->player.dir.x, g->player.dir.y);
	printf("player.plane = (%.2f, %.2f)\n", g->player.plane.x,
		g->player.plane.y);
	printf("spawn parser = (%d,%d) dir %c\n", g->player_x, g->player_y,
		g->player_dir);
}
