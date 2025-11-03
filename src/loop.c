/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:00:43 by enogueir          #+#    #+#             */
/*   Updated: 2025/11/03 13:01:04 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ensure_screen(t_game *g)
{
	if (g->screen.ptr != NULL)
		return (0);
	if (img_create(g->mlx, &g->screen, WIDTH, HEIGHT) == -1)
		return (-1);
	return (0);
}

int	loop_hook(void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (ensure_screen(g) == -1)
		return (0);
	return (0);
}
