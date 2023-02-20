/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/02/15 10:33:50 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	num_rows(char **matrix)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (matrix[row])
	{
		while (matrix[row][col])
			col++;
		row++;
		col = 0;
	}
	return (row);
}

int	*find_char(char **map, char c)
{
	int	*cont;

	cont = malloc(sizeof(int) * 2);
	cont[0] = 0;
	cont[1] = 0;
	while (map[cont[1]])
	{
		while (map[cont[1]][cont[0]])
		{
			if (map[cont[1]][cont[0]] == c)
				return (cont);
			cont[0]++;
		}
		cont[0] = 0;
		cont[1]++;
	}
	return (NULL);
}

static int	num_collectable(char **map)
{
	int	col;
	int	row;
	int	collectable;

	col = 0;
	row = 0;
	collectable = 0;
	while (map[row])
	{
		while (map[row][col])
		{
			if (map[row][col] == 'C')
				collectable++;
			col++;
		}
		row++;
		col = 0;
	}
	return (collectable);
}

void	set_player(t_mlx *mlx)
{
	int	*pos;

	pos = find_char(mlx->map, 'P');
	mlx->player = malloc(sizeof(t_player));
	mlx->player->x = pos[0];
	mlx->player->y = pos[1];
	free(pos);
	mlx->player->pixel_x = mlx->player->x * IMG_WIDTH + X_OFFSET;
	mlx->player->pixel_y = mlx->player->y * IMG_HEIGHT + Y_OFFSET;
	mlx->player->to_move = 0;
	mlx->player->to_move_x = 0;
	mlx->player->to_move_y = 0;
}

void	set_info(t_mlx *mlx)
{
	int	*pos;

	pos = find_char(mlx->map, 'E');
	mlx->info = malloc(sizeof(t_info));
	mlx->info->x_exit = pos[0];
	mlx->info->y_exit = pos[1];
	free(pos);
	mlx->info->coll_total = num_collectable(mlx->map);
	mlx->info->coll_add = 0;
	mlx->info->step_x = ft_strlen(mlx->map[0]) * IMG_WIDTH;
	mlx->info->step_y = (num_rows(mlx->map) + 1) * IMG_HEIGHT;
}
