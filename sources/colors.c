/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:31:02 by mloureir          #+#    #+#             */
/*   Updated: 2025/06/05 01:38:36 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <unistd.h>

char	*get_c_path(char *buffer)
{
	int		i;
	char	*toret;

	i = 1;
	while (buffer[i] == 32 || (buffer[i] >= 9 && buffer[i] <= 13))
		i++;
	toret = ft_strdup(buffer + i);
	return (rm_nl(toret));
}

int	find_color(char *buffer, t_colors *colors)
{
	if (ft_strnstr(buffer, "F", 1))
	{
		colors[0].identifier = 'F';
		colors[0].path = get_c_path(buffer);
		colors[0].allocd = 1;
		if (verify_color_path(colors[0].path) != 0)
			return (1);
	}
	else if (ft_strnstr(buffer, "C", 1))
	{
		colors[1].identifier = 'C';
		colors[1].path = get_c_path(buffer);
		colors[1].allocd = 1;
		if (verify_color_path(colors[1].path) != 0)
			return (1);
	}
	return (0);
}

int	startup_check(char *str)
{
	t_counters	c;

	start_counters(&c);
	while (str[c.c])
	{
		if (str[c.c] == ',')
			c.f += 1;
		else if (ft_isdigit(str[c.c]) == 0)
			return (1);
		c.c += 1;
	}
	if (c.f != 2)
		return (1);
	return (0);
}

int	check_coloms(char *str, t_colors *colors, int i)
{
	t_counters	c;

	start_counters(&c);
	if (startup_check(str) != 0)
		return (1);
	while (str[c.c])
	{
		if (str[c.c] == ',' || str[c.c + 1] == '\0')
		{
			c.no = c.ea;
			c.ea = c.c;
			if (c.f == 0)
				colors[i].red = ft_n_atoi(str, c.ea, c.no);
			else if (c.f == 1)
				colors[i].green = ft_n_atoi(str, c.ea, c.no + 1);
			else
				colors[i].blue = ft_n_atoi(str, c.ea + 1, c.no + 1);
			c.f += 1;
		}
		c.c += 1;
	}
	return (0);
}

int	seperate_colors(t_colors *colors)
{
	int	i;

	i = 0;
	while (i < COLOR)
	{
		if (check_coloms(colors[i].path, colors, i) != 0)
		{
			ft_putstr_fd("Invalid RGB values\n", STDERR_FILENO);
			return (1);
		}
		i++;
	}
	colors[0].allocd = 0;
	colors[1].allocd = 0;
	free(colors[0].path);
	free(colors[1].path);
	return (0);
}
