/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@42porto.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:34:22 by mloureir          #+#    #+#             */
/*   Updated: 2025/04/30 15:33:47 by mloureir         ###   ########.pt       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_dotfile(char *map_dir)
{
	int		len;
	char	*test;

	len = ft_strlen(map_dir);
	test = map_dir + len - 4;
	if (ft_strnstr(test, ".cub", ft_strlen(test)))
		return (0);
	else
		return (1);
}

int	check_errs(char *map_dir)
{
	int	tmp_fd;

	if (check_dotfile(map_dir) != 0)
		return (1);
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
