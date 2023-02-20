/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/02/14 09:13:56 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	if (mlx->player->to_move == 0)
	{
		if (keycode == 13)
			move_character(mlx, 0, -1);
		if (keycode == 0)
			move_character(mlx, -1, 0);
		if (keycode == 1)
			move_character(mlx, 0, 1);
		if (keycode == 2)
			move_character(mlx, 1, 0);
	}
	if (keycode == 53)
		exit(1);
	return (0);
}

int	exit_hook(void)
{
	exit(0);
}
