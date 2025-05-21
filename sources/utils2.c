/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@42porto.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:15:40 by mloureir          #+#    #+#             */
/*   Updated: 2025/05/20 09:22:03 by mloureir         ###   ########.pt       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_line_empty(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (if_space(str[i]) == 0)
			count++;
		i++;
	}
	if (count == (int)ft_strlen(str))
		return (1);
	else
		return (0);
}

char	*jump_empty(int fd)
{
	char	*buffer;

	buffer = get_next_line(fd);
	while (buffer)
	{
		if (is_line_empty(buffer) == 0)
			break ;
		free(buffer);
		buffer = get_next_line(fd);
	}
	return (buffer);
}

void	print_debug(t_map *map)
{
	t_counters	c;

	start_counters(&c);
	while (c.c < MAX_TEXTURE)
	{
		printf("[%s]", map->texture[c.c].identifier);
		printf("[%s]\n", map->texture[c.c].path);
		c.c++;
	}
	while (c.f < COLOR)
	{
		printf("[%c]", map->color[c.f].identifier);
		printf("[%d, %d,", map->color[c.f].red, map->color[c.f].green);
		printf(" %d]\n", map->color[c.f].blue);
		c.f++;
	}
	while (c.ea < map->map_y)
	{
		printf("%s\n", map->map[c.ea]);
		c.ea++;
	}
}

int	map_chars(int c)
{
	if (c == '1' || c == '0')
		return (4);
	else if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (3);
	else
		return (1);
}

void	change_spaces(t_map *map)
{
	int	i;
	int	f;

	f = 0;
	while (f <= map->map_y)
	{
		i = 0;
		while (i < (int)ft_strlen(map->map[f]))
		{
			if (if_space(map->map[f][i]) == 0)
				map->map[f][i] = '0';
			i++;
		}
		f++;
	}
}
