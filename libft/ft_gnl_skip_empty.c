/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_skip_empty.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-31 16:20:11 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-10-31 16:20:11 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnl_skip_empty(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && (line[0] == '\n' || line[0] == '\r'))
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}