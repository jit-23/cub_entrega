/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@42porto.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:24:34 by mloureir          #+#    #+#             */
/*   Updated: 2025/04/24 18:14:51 by mloureir         ###   ########.pt       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_n_strjoin(char *str, char *next)
{
	char	*nstr;
	size_t	i;

	i = 0;
	nstr = malloc(ft_strlen(str) + ft_strlen(next) + 1);
	if (!nstr)
	{
		free(str);
		free(next);
		return (0);
	}
	while (str[i])
	{
		nstr[i] = str[i];
		i++;
	}
	while (*next)
	{
		nstr[i] = *next;
		next++;
		i++;
	}
	free(str);
	nstr[i] = '\0';
	return (nstr);
}

void	ft_cleanbuffer(char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && i < BUFFER_SIZE)
		i++;
	if (buffer[i] == '\n')
		i++;
	while (i < BUFFER_SIZE)
	{
		buffer[j] = buffer[i];
		buffer[i] = '\0';
		i++;
		j++;
	}
	while (j < BUFFER_SIZE)
	{
		buffer[j] = '\0';
		j++;
	}
}

char	*ft_readbuffer(int fd, char *str)
{
	static char	buffer[BUFFER_SIZE];
	char		*next;
	int			charead;

	charead = 0;
	while (buffer[charead] != '\0' && charead < BUFFER_SIZE)
		charead++;
	while (!ft_str_has_newline(str))
	{
		if (ft_buffer_is_empty(buffer))
			charead = read(fd, buffer, BUFFER_SIZE);
		if (charead <= 0)
			break ;
		next = ft_buffer_to_str(buffer, charead);
		if (!next)
			break ;
		str = ft_n_strjoin(str, next);
		if (!str)
			return (0);
		free(next);
		ft_cleanbuffer(buffer);
	}
	return (ft_check_str(str, charead));
}

char	*get_next_line(int fd)
{
	char	*str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	str = malloc(1);
	if (!str)
		return (0);
	str[0] = '\0';
	return (ft_readbuffer(fd, str));
}
