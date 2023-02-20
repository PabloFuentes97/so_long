/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/02/15 10:33:17 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(char *message)
{
	write(1, "Error\n", 7);
	write(1, message, ft_strlen(message));
	return (0);
}

void	error_exit(char *message)
{
	write(1, "Error\n", 7);
	write(1, message, ft_strlen(message));
	exit(0);
}

static void	set_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr,
			ft_strlen(mlx->map[0]) * IMG_WIDTH + X_OFFSET * 2,
			num_rows(mlx->map) * IMG_HEIGHT + Y_OFFSET * 2, "so_long");
	set_images(mlx);
	set_info(mlx);
	set_player(mlx);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
		return (-1);
	create_map(&mlx, argv[1]);
	call_pathfinding(mlx.map);
	set_mlx(&mlx);
	draw_low_map(mlx);
	draw_high_map(mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, exit_hook, (void *)0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
