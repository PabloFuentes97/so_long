/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/02/14 09:21:17 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_low_map(t_mlx mlx)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (mlx.map[row])
	{
		while (mlx.map[row][col])
		{
			if (mlx.map[row][col] == '1')
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.win,
					mlx.img[2][0].img_ptr,
					IMG_WIDTH * col + X_OFFSET, IMG_HEIGHT * row + Y_OFFSET);
			else
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.win,
					mlx.img[1][0].img_ptr,
					IMG_WIDTH * col + X_OFFSET, IMG_HEIGHT * row + Y_OFFSET);
			col++;
		}
		row++;
		col = 0;
	}
}

void	print_image_char(t_mlx mlx, char c, t_img img)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (mlx.map[row])
	{
		while (mlx.map[row][col])
		{
			if (mlx.map[row][col] == c)
			{
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.win,
					mlx.img[1][0].img_ptr, IMG_WIDTH * col + X_OFFSET,
					IMG_HEIGHT * row + Y_OFFSET);
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, img.img_ptr,
					IMG_WIDTH * col + X_OFFSET, IMG_HEIGHT * row + Y_OFFSET);
			}
			col++;
		}
		row++;
		col = 0;
	}
}

void	draw_high_map(t_mlx mlx)
{
	print_image_char(mlx, 'P', mlx.img[0][0]);
	print_image_char(mlx, 'C', mlx.img[3][0]);
}
