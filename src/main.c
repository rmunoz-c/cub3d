/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:01:52 by enogueir          #+#    #+#             */
/*   Updated: 2025/11/11 18:54:28 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (err("Usage: ./cub3D <map.cub>"));
	if (cub3d_run(argv[1]) != 0)
		return (1);
	return (0);
}
