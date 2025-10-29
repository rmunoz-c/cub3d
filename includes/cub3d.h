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


/*_________________________________ map_checker.c ___________________________*/

int		is_valid_char(char c);
int		count_players(t_map *m);
void	set_player(t_game *game);
int		validate_map_closed(t_game *game);

#endif