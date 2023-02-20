/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/02/15 10:34:46 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_player_images(t_mlx mlx)
{
	mlx.img[0] = malloc(sizeof(t_img) * 3);
	if (!mlx.img[0])
	{
		free(mlx.img[0]);
		exit(0);
	}
	mlx.img[0][0] = xpm_to_img(mlx, "textures/ship_center.xpm");
	mlx.img[0][1] = xpm_to_img(mlx, "textures/ship_left.xpm");
	mlx.img[0][2] = xpm_to_img(mlx, "textures/ship_right.xpm");
}

void	set_floor_images(t_mlx mlx)
{
	mlx.img[1] = malloc(sizeof(t_img) * 1);
	if (!mlx.img[1])
	{
		free(mlx.img[1]);
		exit(0);
	}
	mlx.img[1][0] = xpm_to_img(mlx, "textures/floor.xpm");
}

void	set_obstacle_images(t_mlx mlx)
{
	mlx.img[2] = malloc(sizeof(t_img) * 1);
	if (!mlx.img[2])
	{
		free(mlx.img[2]);
		exit(0);
	}
	mlx.img[2][0] = xpm_to_img(mlx, "textures/obstacle.xpm");
}

void	set_collectable_images(t_mlx mlx)
{
	mlx.img[3] = malloc(sizeof(t_img) * 3);
	if (!mlx.img[3])
	{
		free(mlx.img[3]);
		exit(0);
	}
	mlx.img[3][0] = xpm_to_img(mlx, "textures/collectable1.xpm");
	mlx.img[3][1] = xpm_to_img(mlx, "textures/collectable2.xpm");
	mlx.img[3][2] = xpm_to_img(mlx, "textures/collectable3.xpm");
}

void	set_exit_images(t_mlx mlx)
{
	mlx.img[4] = malloc(sizeof(t_img) * 1);
	if (!mlx.img[4])
	{
		free(mlx.img[4]);
		exit(0);
	}
	mlx.img[4][0] = xpm_to_img(mlx, "textures/exit.xpm");
}
