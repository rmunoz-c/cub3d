/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-29 18:11:36 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-10-29 18:11:36 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	read_u8_ws(const char **p, int *out)
{
	const char	*s;
	int			v;

	s = *p;
	while (*s == ' ' || *s == '\t')
		s++;
	if (*s < '0' || *s > '9')
		return (-1);
	v = ft_atoi_skip(&s);
	if (v < 0 || v > 255)
		return (-1);
	*out = v;
	*p = s;
	return (0);
}

static int	expect_comma(const char **p)
{
	const char	*s;

	s = *p;
	while (*s == ' ' || *s == '\t')
		s++;
	if (*s != ',')
		return (-1);
	s++;
	*p = s;
	return (0);
}

int	parse_rgb(int *r, int *g, int *b, const char *line)
{
	const char	*ptr;

	ptr = line;
	if (read_u8_ws(&ptr, r) < 0)
		return (-1);
	if (expect_comma(&ptr) < 0)
		return (-1);
	if (read_u8_ws(&ptr, g) < 0)
		return (-1);
	if (expect_comma(&ptr) < 0)
		return (-1);
	if (read_u8_ws(&ptr, b) < 0)
		return (-1);
	while (*ptr == ' ' || *ptr == '\t')
		ptr++;
	if (*ptr != '\0' && *ptr != '\n' && *ptr != '\r')
		return (-1);
	return (0);
}

int	parse_floor_color(t_game *game, const char *line)
{
	int	r;
	int	g;
	int	b;

	if (line[0] != 'F')
		return (0);
	if (line[1] != ' ' && line[1] != '\t')
		return (0);
	if (game->floor_color != -1)
		return (0);
	if (parse_rgb(&r, &g, &b, line + 2) == -1)
		return (0);
	game->floor_color = (r << 16) | (g << 8) | b;
	return (1);
}

int	parse_ceiling_color(t_game *game, const char *line)
{
	int	r;
	int	g;
	int	b;

	if (line[0] != 'C')
		return (0);
	if (line[1] != ' ' && line[1] != '\t')
		return (0);
	if (game->ceiling_color != -1)
		return (0);
	if (parse_rgb(&r, &g, &b, line + 2) == -1)
		return (0);
	game->ceiling_color = (r << 16) | (g << 8) | b;
	return (1);
}
