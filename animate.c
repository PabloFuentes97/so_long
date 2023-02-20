/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/02/14 09:02:18 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_entry(t_mlx *mlx)
{
	if (mlx->info->coll_add == mlx->info->coll_total)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img[4][0].img_ptr,
			(mlx->info->x_exit) * IMG_WIDTH + X_OFFSET,
			(mlx->info->y_exit) * IMG_HEIGHT + Y_OFFSET);
	}
	if ((mlx->player->x + mlx->player->to_move_x == mlx->info->x_exit)
		&& (mlx->player->y + mlx->player->to_move_y == mlx->info->y_exit)
		&& (mlx->info->coll_add == mlx->info->coll_total))
		exit(1);
}

void	animate_collectable(t_mlx mlx, int frame)
{
	t_img				curr;
	static int			pos;

	if (frame == 0)
	{
		curr = mlx.img[3][0];
		print_image_char(mlx, 'C', curr);
	}
	else if (frame % 4000 == 0 && frame % 16000 != 0)
	{
		curr = mlx.img[3][pos];
		print_image_char(mlx, 'C', curr);
		pos++;
	}	
	else if (frame % 16000 == 0)
		pos = 0;
}

void	animate_enemy(t_mlx mlx, int frame)
{
	t_img				curr;
	static int			pos;

	if (frame == 0 || (frame % 2500 == 0 && frame % 15000 != 0))
	{
		curr = mlx.img[5][pos];
		print_image_char(mlx, 'F', curr);
		pos++;
	}
	if (frame % 15000 == 0)
		pos = 0;
}

void	player_death_explosion(t_mlx *mlx)
{
	static int		frame;
	t_img			curr;
	static int		pos;

	if (frame % 2000 == 0)
	{
		if (pos < 5)
		{
			curr = mlx->img[6][pos];
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
				mlx->img[1][0].img_ptr, mlx->player->pixel_x,
				mlx->player->pixel_y);
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, curr.img_ptr,
				mlx->player->pixel_x, mlx->player->pixel_y);
			pos++;
		}
		else if (pos == 5)
		{
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
				mlx->img[1][0].img_ptr, mlx->player->pixel_x,
				mlx->player->pixel_y);
			exit(0);
		}
	}
	frame++;
}
