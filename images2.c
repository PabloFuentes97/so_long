/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/02/14 09:27:50 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	mlx->img = malloc(sizeof(t_img *) * 5);
	set_player_images(*mlx);
	set_floor_images(*mlx);
	set_obstacle_images(*mlx);
	set_collectable_images(*mlx);
	set_exit_images(*mlx);
}
