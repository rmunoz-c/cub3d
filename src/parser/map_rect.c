/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-29 19:58:22 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-10-29 19:58:22 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	row_len(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

static int	max_len(char **a, int n)
{
	int	i;
	int	len;
	int	max;

	i = 0;
	max = 0;
	while (i < n)
	{
		len = row_len(a[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

static void	fill_row(char *dst, int w, const char *src)
{
	int	x;
	int	len;

	len = row_len(src);
	x = 0;
	while (x < w)
	{
		if (x < len)
			dst[x] = src[x];
		else
			dst[x] = ' ';
		x++;
	}
	dst[x] = '\0';
}

static void	free_rows(char **grid, int rows)
{
	int	y;

	y = 0;
	while (y < rows)
	{
		free(grid[y]);
		y++;
	}
	free(grid);
}

int	build_map_rect(t_map *m, char **lines, int n)
{
	int	y;

	if (!m || !lines || n <= 0)
		return (0);
	m->h = n;
	m->w = max_len(lines, n);
	if (m->w <= 0)
		return (err("Empty map"));
	m->grid = (char **)malloc(sizeof(char *) * m->h);
	if (!m->grid)
		return (err("Memory error building map"));
	y = 0;
	while (y < m->h)
	{
		m->grid[y] = (char *)malloc(m->w + 1);
		if (!m->grid[y])
		{
			free_rows(m->grid, y);
			return (err("Memory error building map"));
		}
		fill_row(m->grid[y], m->w, lines[y]);
		y++;
	}
	return (1);
}
