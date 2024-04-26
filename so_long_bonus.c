/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/08/15 11:52:47 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	print_steps(t_mlx mlx)
{
	static int	steps;
	int			steps_len;
	char		*steps_str;
	int			cont;

	steps++;
	steps_len = num_len(steps);
	steps_str = ft_itoa(steps);
	write(1, steps_str, num_len(steps));
	write(1, "\n", 1);
	cont = 0;
	while (cont < steps_len)
	{
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img[7][0].img_ptr,
			mlx.info->step_x / 2 + IMG_WIDTH * cont + X_OFFSET,
			mlx.info->step_y + 5);
		cont++;
	}
	mlx_string_put(mlx.mlx_ptr, mlx.win,
		(mlx.info->step_x / 2 + steps_len) + X_OFFSET,
		mlx.info->step_y, 0xFFFFFF, steps_str);
	free(steps_str);
}

static void	set_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr,
			ft_strlen(mlx->map[0]) * IMG_WIDTH + (X_OFFSET * 2),
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
	mlx_hook(mlx.win, 2, 0, key_hook, &mlx);
	//mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, exit_hook, (void *)0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
