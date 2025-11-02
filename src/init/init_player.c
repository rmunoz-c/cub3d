#include "../../includes/cub3d.h"

static void set_plane_dir(t_player *p, char spawn)
{
	if (spawn == 'N')
	{
		p->dir.x = 0.0;
		p->dir.y = -1.0;
		p->plane.x = 0.66;
		p->plane.y = 0.0;
	}
	else if (spawn == 'S')
	{
		p->dir.x = 0.0;
		p->dir.y = -1.0;
		p->plane.x = -0.66;
		p->plane.y = 0.0;
	}
	else if (spawn == 'E')
	{
		p->dir.x = 1.0;
		p->dir.y = 0.0;
		p->plane.x = 0.0;
		p->plane.y = 0.66;
	}
	else if (spawn == 'W')
	{
		p->dir.x = -1.0;
		p->dir.y = 0.0;
		p->plane.x = 0.0;
		p->plane.y = -0.66;
	}
}

int	init_player(t_game *g)
{
	g->player.pos.x = (double)g->player_x + 0.5;
	g->player.pos.y = (double)g->player_y + 0.5;
	set_plane_dir(&g->player, g->player_dir);
	return (0);
}