/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-29 16:37:09 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-10-29 16:37:09 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_map {
    char	**grid;
    int		w;
    int		h;
} t_map;

typedef struct s_texture {
    void	*img_ptr;
    int		width;
    int		height;
    char	*data;
    int		line_len;
	int		bpp;
	int		endian;
} t_texture;

typedef struct s_vec2d {
    double x;
    double y;
} t_vec2d;

typedef struct s_img {
    void *ptr;
    int  *data;
    int   w;
    int   h;
    int   line_len;
    int   bpp;
    int   endian;
} t_img;

typedef struct s_player {
    t_vec2d pos;
    t_vec2d dir;
    t_vec2d plane;
} t_player;


typedef struct s_game {
    char		*no_texture;
    char		*so_texture;
    char		*we_texture;
    char		*ea_texture;

	t_texture	no;
	t_texture	so;
	t_texture	we;
	t_texture	ea;

    int		floor_color;
    int		ceiling_color;
	
    t_map	map;
    int		player_x;
    int		player_y;
    char	player_dir;

    void		*mlx;
	void		*win;
	t_img		screen;
	t_player	player;
} t_game;

#define HEIGHT 800
#define WIDTH 600
#define KEY_ESC 65307


#endif