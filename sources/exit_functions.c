/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:16:03 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/05/21 02:55:22 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	exit_msg(t_cub *cub, char *str)
{
	(void )cub;
	ft_putstr_fd(str, 2);
	exit(1);
}

void	close_window(void)
{
	exit(0);
}
