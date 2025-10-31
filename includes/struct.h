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
} t_texture;

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
} t_game;


#endif