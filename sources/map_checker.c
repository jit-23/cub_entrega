/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@42porto.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:34:22 by mloureir          #+#    #+#             */
/*   Updated: 2025/06/05 09:11:14 by mloureir         ###   ########.pt       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <unistd.h>

int	ft_strlen_slash(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '/' && str[i])
		i++;
	i++;
	while (str[i])
	{
		count++;
		i++;
	}
	return (count);
}

int	check_xpm(char *str)
{
	if (ft_strncmp(str + ft_strlen(str) - 4, ".xpm", 4) != 0)
		return (1);
	else
		return (0);
}

int	check_dotfile(char *map_dir)
{
	if (ft_strncmp(map_dir + ft_strlen(map_dir) - 4, ".cub", 4) != 0)
		return (1);
	else
		return (0);
}

int	check_errs(char *map_dir)
{
	int	tmp_fd;

	if (check_dotfile(map_dir) != 0)
	{
		ft_putstr_fd("No .cub\n", STDERR_FILENO);
		return (1);
	}
	tmp_fd = open(map_dir, O_RDONLY);
	if (tmp_fd == -1)
	{
		ft_putstr_fd("Map doesn't exist\n", STDERR_FILENO);
		return (1);
	}
	close(tmp_fd);
	if (check_content(map_dir) != 0)
		return (1);
	if (check_values(map_dir) != 0)
		return (1);
	return (0);
}
