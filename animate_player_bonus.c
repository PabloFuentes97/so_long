/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/02/14 12:59:00 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	draw_animation_step(t_mlx *mlx, t_img curr)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img[1][0].img_ptr,
		mlx->player->pixel_x, mlx->player->pixel_y);
	if (mlx->player->to_move_x != 0)
		mlx->player->pixel_x += (IMG_WIDTH / 4) * (mlx->player->to_move_x);
	if (mlx->player->to_move_y != 0)
		mlx->player->pixel_y += (IMG_WIDTH / 4) * (mlx->player->to_move_y);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
		mlx->img[1][0].img_ptr, mlx->player->pixel_x, mlx->player->pixel_y);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
		curr.img_ptr, mlx->player->pixel_x, mlx->player->pixel_y);
}

static void	reset_animation_values(t_mlx *mlx)
{
	mlx->player->to_move = 0;
	mlx->player->to_move_x = 0;
	mlx->player->to_move_y = 0;
}

static void	animation_end(t_mlx *mlx)
{
	mlx->map[mlx->player->y][mlx->player->x] = '0';
	if (mlx->map[mlx->player->y + mlx->player->to_move_y]
		[mlx->player->x + mlx->player->to_move_x] == 'C')
			mlx->info->coll_add++;
	mlx->map[mlx->player->y + mlx->player->to_move_y]
	[mlx->player->x + mlx->player->to_move_x] = 'P';
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img[1][0].img_ptr,
		mlx->player->pixel_x, mlx->player->pixel_y);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img[1][0].img_ptr,
		mlx->player->x * IMG_WIDTH + X_OFFSET,
		mlx->player->y * IMG_HEIGHT + Y_OFFSET);
	mlx->player->x = mlx->player->x + mlx->player->to_move_x;
	mlx->player->y = mlx->player->y + mlx->player->to_move_y;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img[0][0].img_ptr,
		mlx->player->pixel_x, mlx->player->pixel_y);
	reset_animation_values(mlx);
}

static void	move_animation(t_mlx *mlx)
{
	static int		pos;
	t_img			curr;

	exit_entry(mlx);
	if (mlx->player->to_move_x == -1)
		curr = mlx->img[0][1];
	else if (mlx->player->to_move_x == 1)
		curr = mlx->img[0][2];
	else if (mlx->player->to_move_x == 0)
		curr = mlx->img[0][0];
	if (pos < 4)
	{
		if (mlx->map[mlx->player->y + mlx->player->to_move_y]
			[mlx->player->x + mlx->player->to_move_x] != '1')
		{
			draw_animation_step(mlx, curr);
			pos++;
		}
	}
	else
	{
		animation_end(mlx);
		pos = 0;
	}
}

int	animate_sprites(t_mlx *mlx)
{
	static int			frame;

	animate_collectable(*mlx, frame);
	animate_enemy(*mlx, frame);
	if (mlx->player->to_move == 1 && frame % 500 == 0
		&& mlx->map[mlx->player->y + mlx->player->to_move_y]
		[mlx->player->x + mlx->player->to_move_x] != '1'
		&& mlx->map[mlx->player->y + mlx->player->to_move_y]
		[mlx->player->x + mlx->player->to_move_x] != 'F')
		move_animation(mlx);
	else if (mlx->player->to_move == 1
		&& mlx->map[mlx->player->y + mlx->player->to_move_y]
		[mlx->player->x + mlx->player->to_move_x] == '1')
		reset_animation_values(mlx);
	else if (mlx->player->to_move == 1
		&& mlx->map[mlx->player->y + mlx->player->to_move_y]
		[mlx->player->x + mlx->player->to_move_x] == 'F')
		player_death_explosion(mlx);
	frame++;
	return (0);
}
