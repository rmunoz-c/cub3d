/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-29 15:57:16 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-10-29 15:57:16 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <sys/time.h>
# include <mlx.h>
# include "libft.h"

#include "struct.h"

/*_________________________________ color_parser.c __________________________*/

int		parse_rgb(int *r, int *g, int *b, char *line);
int		parse_floor_color(t_game *game, char *line);
int		parse_ceiling_color(t_game *game, char *line);

/*_________________________________ header_scan.c __________________________*/

int	scan_header(int fd, t_game *g, char **map_first);

/*_________________________________ map_checker_utils.c _____________________*/

int		check_map(t_game *game);

/*_________________________________ map_checker.c ___________________________*/

int		is_valid_char(char c);
int		count_players(t_map *m);
void	set_player(t_game *game);
int		validate_map_closed(t_game *game);

/*_________________________________ parser.c ________________________________*/

int		err(const char *msg);
int		parse_scene(t_game *g, const char *path);

/*_________________________________ texture_checker.c _______________________*/

int		set_texture(t_game *game, char *prefix, char *path);
int		parse_texture(t_game *game, char *line);
int		can_open_readonly(const char *p);

#endif