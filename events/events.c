#include "../../includes/cub3d.h"

void set_hooks(t_game *g)
{
    mlx_hook(g->win, 2, 1L << 0, key_press, g);
    mlx_hook(g->win, 17, 0, exit_program, g);
    mlx_loop_hook(g->mlx, loop_hook, g);
}

int key_press(int keycode, void *param)
{
    t_game *g;

    g = (t_game *)param;
    if (keycode == KEY_ESC)
        return (exit_program(g));
    return (0);
}

int exit_program(void *param)
{
    t_game *g;

    g = (t_game *)param;
    cub_cleanup(g);
    exit(0);
    return (0);
}
