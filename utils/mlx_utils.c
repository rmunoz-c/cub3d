#include "../../includes/cub3d.h"

int img_create(void *mlx, t_img *img, int w, int h)
{
    img->ptr = mlx_new_image(mlx, w, h);
    if (img->ptr == NULL)
        return (-1);
    img->data = (int *)mlx_get_data_addr(
        img->ptr, &img->bpp, &img->line_len, &img->endian);
    if (img->data == NULL)
        return (-1);
    img->w = w;
    img->h = h;
    return (0);
}

void img_destroy(void *mlx, t_img *img)
{
    if (img->ptr != NULL)
        mlx_destroy_image(mlx, img->ptr);
    img->ptr = NULL;
}

void cub_cleanup(t_game *g)
{
    if (g->screen.ptr != NULL)
        img_destroy(g->mlx, &g->screen);
    if (g->win != NULL)
        mlx_destroy_window(g->mlx, g->win);
    if (g->mlx != NULL)
    {
        mlx_destroy_display(g->mlx);
        free(g->mlx);
    }
}

int exit_program(void *param)
{
    t_game *g;

    g = (t_game *)param;
    cub_cleanup(g);
    exit(0);
    return (0);
}
