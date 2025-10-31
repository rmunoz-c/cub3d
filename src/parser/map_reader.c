/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-29 19:49:06 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-10-29 19:49:06 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	free_lines(char **a, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(a[i]);
		i++;
	}
	free(a);
}

static int	is_blank_map(char *s)
{
	int	len;

	if (!s)
		return (1);
	len = ft_strlen(s);
	if (len > 0 && s[len - 1] == '\n')
	{
		s[len - 1] = '\0';
		len--;
	}
	if (len > 0 && s[len - 1] == '\r')
	{
		s[len - 1] = '\0';
		len--;
	}
	return (s[0] == '\0');
}

static int	append_line(char ***arr, int *cap, int *n, char *line)
{
	char	**tmp;
	int		new_cap;

	if (*n == *cap)
	{
		if (*cap == 0)
			new_cap = 16;
		else
			new_cap = *cap * 2;
		tmp = (char **)malloc(sizeof(char *) * new_cap);
		if (!tmp)
			return (0);
		if (*arr && *n > 0)
			ft_memcpy(tmp, *arr, sizeof(char *) * (*n));
		free(*arr);
		*arr = tmp;
		*cap = new_cap;
	}
	(*arr)[*n] = line;
	*n = *n + 1;
	return (1);
}

static int	take_next_line(int fd, char **first)
{
	char	*line;

	if (*first)
		return (1);
	line = get_next_line(fd);
	if (!line)
		return (0);
	*first = line;
	return (1);
}

int	read_map_lines(int fd, char *first, char ***out, int *out_n)
{
	char	**arr;
	int		cap;
	int		n;
	int		ended;

	arr = NULL;
	cap = 0;
	n = 0;
	ended = 0;
	while (take_next_line(fd, &first))
	{
		if (is_blank_map(first))
			ended = 1;
		else if (ended)
			return (free(first), free_lines(arr, n),
				err("Empty line inside map (gaps not allowed)"));
		if (!append_line(&arr, &cap, &n, first))
			return (free(first), free_lines(arr, n), err("Memory error"));
		first = NULL;
	}
	if (n == 0)
		return (err("Empty map"));
	*out = arr;
	*out_n = n;
	return (1);
}
