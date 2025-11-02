#include "../../includes/cub3d.h"

int	init_mlx(t_game *g)
{
	g->mlx = mlx_init();
	if (g->mlx == NULL)
		return (-1);
	g->win = mlx_new_window(g->mlx, WIDTH, HEIGHT, "Cub 3D");
	if (g->win == NULL)
		return (-1);
		g->screen.ptr = NULL;
	return (0);
}