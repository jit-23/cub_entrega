/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@42porto.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:25:14 by mloureir          #+#    #+#             */
/*   Updated: 2025/04/30 15:34:14 by mloureir         ###   ########.pt       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*get_path(char *buffer)
{
	int		i;
	char	*toret;

	i = 2;
	while (buffer[i] == 32 || (buffer[i] >= 9 && buffer[i] <= 13))
		i++;
	toret = ft_strdup(buffer + i);
	return (rm_nl(toret));
}

void	find_texture(char *buffer, t_textures *t_txt)
{
	if (ft_strnstr(buffer, "NO", 2))
	{
		t_txt[0].identifier = ft_strdup("NO");
		t_txt[0].path = get_path(buffer);
	}
	else if (ft_strnstr(buffer, "EA", 2))
	{
		t_txt[1].identifier = ft_strdup("EA");
		t_txt[1].path = get_path(buffer);
	}
	else if (ft_strnstr(buffer, "WE", 2))
	{
		t_txt[2].identifier = ft_strdup("WE");
		t_txt[2].path = get_path(buffer);
	}
	else if (ft_strnstr(buffer, "SO", 2))
	{
		t_txt[3].identifier = ft_strdup("SO");
		t_txt[3].path = get_path(buffer);
	}
}

int	get_texture(t_textures *textures, char *map_dir)
{
	int		fd;
	char	*buffer;

	fd = open(map_dir, O_RDONLY);
	buffer = get_next_line(fd);
	while (buffer)
	{
		find_texture(buffer, textures);
		free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
	free(buffer);
	return (0);
}
