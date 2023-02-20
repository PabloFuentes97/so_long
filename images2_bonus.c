/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/02/15 10:37:54 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	set_enemy_images(t_mlx mlx)
{
	mlx.img[5] = malloc(sizeof(t_img) * 6);
	if (!mlx.img[5])
	{
		free(mlx.img[5]);
		exit(0);
	}
	mlx.img[5][0] = xpm_to_img(mlx, "textures/enemy1.xpm");
	mlx.img[5][1] = xpm_to_img(mlx, "textures/enemy2.xpm");
	mlx.img[5][2] = xpm_to_img(mlx, "textures/enemy3.xpm");
	mlx.img[5][3] = xpm_to_img(mlx, "textures/enemy4.xpm");
	mlx.img[5][4] = xpm_to_img(mlx, "textures/enemy5.xpm");
	mlx.img[5][5] = xpm_to_img(mlx, "textures/enemy6.xpm");
}

static void	set_explosion_images(t_mlx mlx)
{
	mlx.img[6] = malloc(sizeof(t_img) * 5);
	if (!mlx.img[6])
	{
		free(mlx.img[6]);
		exit(0);
	}
	mlx.img[6][0] = xpm_to_img(mlx, "textures/explosion1.xpm");
	mlx.img[6][1] = xpm_to_img(mlx, "textures/explosion2.xpm");
	mlx.img[6][2] = xpm_to_img(mlx, "textures/explosion3.xpm");
	mlx.img[6][3] = xpm_to_img(mlx, "textures/explosion4.xpm");
	mlx.img[6][4] = xpm_to_img(mlx, "textures/explosion5.xpm");
}

static void	set_black_image(t_mlx mlx)
{
	mlx.img[7] = malloc(sizeof(t_img) * 1);
	if (!mlx.img[7])
	{
		free(mlx.img[7]);
		exit(0);
	}
	mlx.img[7][0] = xpm_to_img(mlx, "textures/black.xpm");
}

t_img	xpm_to_img(t_mlx mlx, char *path)
{
	t_img	img;
	int		img_w;
	int		img_h;

	img.img_ptr = mlx_xpm_file_to_image(mlx.mlx_ptr, path, &img_w, &img_h);
	if (!img.img_ptr)
	{
		free(img.img_ptr);
		exit(EXIT_FAILURE);
	}
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp,
			&img.size_l, &img.endian);
	return (img);
}

void	set_images(t_mlx *mlx)
{
	mlx->img = malloc(sizeof(t_img *) * 8);
	set_player_images(*mlx);
	set_floor_images(*mlx);
	set_obstacle_images(*mlx);
	set_collectable_images(*mlx);
	set_exit_images(*mlx);
	set_explosion_images(*mlx);
	set_enemy_images(*mlx);
	set_black_image(*mlx);
}
