/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:49:57 by mloureir          #+#    #+#             */
/*   Updated: 2025/04/24 12:36:14 by mloureir         ###   ########.pt       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
// #include <stdio.h>
// int main()
// {
// 	char str[] = "Hello World!";
// 	printf("%zu\n", ft_strlen(str));
// 	return (0);
// }
