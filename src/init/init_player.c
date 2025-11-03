/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:00:12 by enogueir          #+#    #+#             */
/*   Updated: 2025/11/03 19:13:31 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	set_plane_dir_ns(t_player *p, char spawn)
{
	if (spawn == 'N')
	{
		p->dir.x = 0.0;
		p->dir.y = -1.0;
		p->plane.x = 0.66;
		p->plane.y = 0.0;
	}
	else
	{
		p->dir.x = 0.0;
		p->dir.y = -1.0;
		p->plane.x = -0.66;
		p->plane.y = 0.0;
	}
}

static void	set_plane_dir_ew(t_player *p, char spawn)
{
	if (spawn == 'E')
	{
		p->dir.x = 1.0;
		p->dir.y = 0.0;
		p->plane.x = 0.0;
		p->plane.y = 0.66;
	}
	else
	{
		p->dir.x = -1.0;
		p->dir.y = 0.0;
		p->plane.x = 0.0;
		p->plane.y = -0.66;
	}
}

static void	set_plane_dir(t_player *p, char spawn)
{
	if (spawn == 'N' || spawn == 'S')
		set_plane_dir_ns(p, spawn);
	else if (spawn == 'E' || spawn == 'W')
		set_plane_dir_ew(p, spawn);
}

int	init_player(t_game *g)
{
	g->player.pos.x = (double)g->player_x + 0.5;
	g->player.pos.y = (double)g->player_y + 0.5;
	set_plane_dir(&g->player, g->player_dir);
	return (0);
}
