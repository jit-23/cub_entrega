/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@42porto.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:34:22 by mloureir          #+#    #+#             */
/*   Updated: 2025/05/31 14:08:48 by mloureir         ###   ########.pt       */
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
	int		len;
	char	*test;

	len = ft_strlen_slash(str);
	test = str + len - 4;
	if (ft_strnstr(test, ".xpm", ft_strlen(test)) && len > 4)
		return (0);
	else
		return (1);
	return (0);
}

int	check_dotfile(char *map_dir)
{
	int		len;
	char	*test;

	len = ft_strlen_slash(map_dir);
	test = map_dir + len - 4;
	if (ft_strnstr(test, ".cub", ft_strlen(test)) && len > 4)
		return (0);
	else
		return (1);
}

int	check_errs(char *map_dir)
{
	int	tmp_fd;

	if (check_dotfile(map_dir) != 0)
	{
		ft_putstr_fd("No .cub", STDERR_FILENO);
		return (1);
	}
	tmp_fd = open(map_dir, O_RDONLY);
	if (tmp_fd == -1)
		return (1);
	close(tmp_fd);
	if (check_content(map_dir) != 0)
		return (1);
	if (check_values(map_dir) != 0)
		return (1);
	return (0);
}
