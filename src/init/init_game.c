/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:17:33 by enogueir          #+#    #+#             */
/*   Updated: 2025/11/10 15:17:45 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_game(t_game *g)
{
	ft_bzero(g, sizeof(t_game));
	g->floor_color = -1;
	g->ceiling_color = -1;
}
