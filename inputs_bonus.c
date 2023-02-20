/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/02/14 13:00:57 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	move_player(t_mlx *mlx, int x, int y)
{
	mlx->player->to_move = 1;
	mlx->player->to_move_x = x;
	mlx->player->to_move_y = y;
	if (mlx->map[mlx->player->y + mlx->player->to_move_y]
		[mlx->player->x + mlx->player->to_move_x] != '1')
		print_steps(*mlx);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (mlx->player->to_move == 0)
	{
		if (keycode == 13)
			move_player(mlx, 0, -1);
		if (keycode == 0)
			move_player(mlx, -1, 0);
		if (keycode == 1)
			move_player(mlx, 0, 1);
		if (keycode == 2)
			move_player(mlx, 1, 0);
	}
	if (keycode == 53)
		exit(1);
	return (0);
}

int	exit_hook(void)
{
	exit(0);
}
