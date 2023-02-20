/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/02/14 11:33:41 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_move_pos(t_mlx *mlx, int x, int y)
{
	mlx->map[mlx->player->y][mlx->player->x] = '0';
	mlx->map[mlx->player->y + y][mlx->player->x + x] = 'P';
	mlx->player->x = mlx->player->x + x;
	mlx->player->pixel_x = mlx->player->x * IMG_WIDTH + X_OFFSET;
	mlx->player->y = mlx->player->y + y;
	mlx->player->pixel_y = mlx->player->y * IMG_HEIGHT + Y_OFFSET;
}

void	draw_player_next(t_mlx *mlx, int x, int y)
{
	static int	step;
	char		*step_str;

	step++;
	step_str = ft_itoa(step);
	write(1, step_str, ft_strlen(step_str));
	write(1, "\n", 1);
	free(step_str);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img[1][0].img_ptr,
		mlx->player->pixel_x, mlx->player->pixel_y);
	change_move_pos(mlx, x, y);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img[1][0].img_ptr,
		mlx->player->pixel_x, mlx->player->pixel_y);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img[0][0].img_ptr,
		mlx->player->pixel_x, mlx->player->pixel_y);
}

void	move_character(t_mlx *mlx, int x, int y)
{
	if (mlx->map[mlx->player->y + y][mlx->player->x + x] == 'C')
			mlx->info->coll_add++;
	if (mlx->map[mlx->player->y + y][mlx->player->x + x] != '1')
		draw_player_next(mlx, x, y);
	if (mlx->info->coll_add == mlx->info->coll_total)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img[4][0].img_ptr,
			(mlx->info->x_exit) * IMG_WIDTH + X_OFFSET,
			(mlx->info->y_exit) * IMG_HEIGHT + Y_OFFSET);
	}
	if ((mlx->player->x == mlx->info->x_exit)
		&& (mlx->player->y == mlx->info->y_exit)
		&& (mlx->info->coll_add == mlx->info->coll_total))
		exit(1);
}
