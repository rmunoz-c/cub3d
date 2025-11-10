/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:37:09 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025/11/10 18:51:54 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_map
{
	char		**grid;
	int			w;
	int			h;
}				t_map;

typedef struct s_texture
{
	void		*img_ptr;
	int			width;
	int			height;
	char		*data;
	int			line_len;
	int			bpp;
	int			endian;
}				t_texture;

typedef struct s_vec2d
{
	double		x;
	double		y;
}				t_vec2d;

typedef struct s_img
{
	void		*ptr;
	int			*data;
	int			w;
	int			h;
	int			line_len;
	int			bpp;
	int			endian;
}				t_img;

typedef struct s_player
{
	t_vec2d		pos;
	t_vec2d		dir;
	t_vec2d		plane;
}				t_player;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}				t_keys;

typedef struct s_game
{
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;

	t_texture	no;
	t_texture	so;
	t_texture	we;
	t_texture	ea;

	int			floor_color;
	int			ceiling_color;

	t_map		map;
	int			player_x;
	int			player_y;
	char		player_dir;

	void		*mlx;
	void		*win;
	t_img		screen;
	t_player	player;
	t_keys		keys;
}				t_game;

typedef struct s_spawn_entry
{
	char		c;
	double		dx;
	double		dy;
	double		px;
	double		py;
}				t_spawn_entry;

typedef struct s_ray
{
    t_vec2d	dir;
    t_vec2d	delta;
    t_vec2d	side;
    int		step_x;
    int		step_y;
    int		map_x;
    int		map_y;
    int		side_hit;
    double	dist;
    int		tex_id;
    int		tex_x;
}				t_ray;

typedef struct s_slice
{
    int		x;
    int		start;
    int		end;
    double	tex_pos;
    double	step;
}				t_slice;


# define HEIGHT 600
# define WIDTH 800

# ifdef __APPLE__
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_ESC 53
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
# else
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_ESC 65307
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
# endif

# define WIN_W WIDTH
# define WIN_H HEIGHT
# define TEX_SIZE 64
# define DIR_NORTH 0
# define DIR_SOUTH 1
# define DIR_WEST  2
# define DIR_EAST  3
# define EPS 1e-6

# ifndef COLLISION_RADIUS
#  define COLLISION_RADIUS 0.20
# endif

# ifndef MAX_MOVE_STEP
#  define MAX_MOVE_STEP 0.25
# endif

# ifndef MIN_MOVE_DISTANCE
#  define MIN_MOVE_DISTANCE 1e-6
# endif

#endif