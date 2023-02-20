/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/02/15 09:36:42 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_more_char(char **matrix, int c)
{
	int	row;
	int	col;
	int	num;

	row = 0;
	col = 0;
	num = 0;
	while (matrix[row])
	{
		while (matrix[row][col])
		{
			if (matrix[row][col] == c)
				num++;
			if (num >= 1)
				return (1);
			col++;
		}
		row++;
		col = 0;
	}
	return (error("Bad number of simbols\n"));
}

static int	check_walled_player(char **map)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (map[row])
	{
		while (map[row][col])
		{
			if (map[row][col] == 'P')
			{
				if (map[row][col - 1] == '1'
					&& map[row][col + 1] == '1'
					&& map[row - 1][col] == '1'
					&& map[row + 1][col] == '1')
					return (error("Walled player\n"));
				else
					return (1);
			}
			col++;
		}
		row++;
		col = 0;
	}
	return (error("No player found\n"));
}

int	check_map(char **map_2d, int len)
{
	int	len_line;

	len_line = ft_strlen(map_2d[0]);
	if (valid_shape(map_2d) == 1 && check_hor_limits(map_2d, 0) == 1
		&& check_hor_limits(map_2d, len - 1) == 1
		&& check_ver_limits(map_2d, 0, len - 1) == 1
		&& check_ver_limits(map_2d, len_line - 1, len - 1) == 1
		&& check_simbols(map_2d, len - 1) == 1
		&& check_one_char(map_2d, 'P') == 1
		&& check_one_char(map_2d, 'E') == 1
		&& check_more_char(map_2d, 'C') == 1
		&& check_walled_player(map_2d) == 1)
		return (1);
	return (0);
}
