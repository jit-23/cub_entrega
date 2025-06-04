/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@42porto.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:33:56 by mloureir          #+#    #+#             */
/*   Updated: 2025/06/04 13:59:21 by mloureir         ###   ########.pt       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	verify_color_path(char *str)
{
	t_counters	c;

	start_counters(&c);
	while (str[c.f])
	{
		if (ft_isdigit(str[c.f]) == 1)
			c.ea++;
		if (str[c.f] == ',')
		{
			if (c.ea == 0 || c.ea > 3)
				return (1);
			c.ea = 0;
		}
		c.f++;
	}
	return (0);
}
