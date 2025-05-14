/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:16:03 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/05/14 20:17:01 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub.h"


void	exit_msg(t_cub *cub, char *str)
{
	ft_putstr_fd(2, str);
	exit(1);
}

void	close_window(void)
{
	exit(0);
}
