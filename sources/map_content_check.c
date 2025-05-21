/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@42porto.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:34:25 by mloureir          #+#    #+#             */
/*   Updated: 2025/04/30 14:09:57 by mloureir         ###   ########.pt       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	add_counter(char *buffer, t_counters *count)
{
	if (ft_strnstr(buffer, "NO", 2))
		count->no += 1;
	if (ft_strnstr(buffer, "EA", 2))
		count->ea += 1;
	if (ft_strnstr(buffer, "WE", 2))
		count->we += 1;
	if (ft_strnstr(buffer, "SO", 2))
		count->so += 1;
	if (ft_strnstr(buffer, "F", 1))
		count->f += 1;
	if (ft_strnstr(buffer, "C", 1))
		count->c += 1;
}

int	check_counters(t_counters *count)
{
	if (count->c != 1 || count->f != 1)
		return (1);
	if (count->no != 1 || count->so != 1)
		return (1);
	if (count->ea != 1 || count->we != 1)
		return (1);
	return (0);
}

int	check_content(char *map_dir)
{
	int			fd;
	char		*buffer;
	t_counters	count;

	start_counters(&count);
	fd = open(map_dir, O_RDONLY);
	buffer = get_next_line(fd);
	while (buffer)
	{
		add_counter(buffer, &count);
		free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
	if (check_counters(&count) != 0)
		return (1);
	else
		return (0);
}
