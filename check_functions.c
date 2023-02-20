/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/02/14 10:11:35 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_hor_limits(char **map_2d, int row)
{
	int	cont;
	int	row_len;

	row_len = ft_strlen(map_2d[row]);
	cont = 0;
	while (cont < row_len)
	{
		if (map_2d[row][cont] == '0')
			return (error("Bad horizontal limits\n"));
		cont++;
	}
	return (1);
}

int	check_ver_limits(char	**map_2d, int col, int len)
{
	int	cont;

	cont = 0;
	while (cont < len)
	{
		if (map_2d[cont][col] == '0')
			return (error("Bad vertical limits\n"));
		cont++;
	}
	return (1);
}

int	check_simbols(char **map_2d, int len)
{
	int	cont_row;
	int	cont_col;

	cont_row = 0;
	cont_col = 0;
	while (cont_col < len)
	{
		while (map_2d[cont_col][cont_row])
		{
			if (map_2d[cont_col][cont_row] != '0'
			&& map_2d[cont_col][cont_row] != '1'
			&& map_2d[cont_col][cont_row] != 'C'
			&& map_2d[cont_col][cont_row] != 'E'
			&& map_2d[cont_col][cont_row] != 'P')
				return (error("Bad simbols\n"));
			cont_row++;
		}
		cont_row = 0;
		cont_col++;
	}
	return (1);
}

int	valid_shape(char **map_2d)
{
	int	cont1;
	int	cont2;
	int	len_line1;
	int	len_line2;

	cont1 = 0;
	cont2 = 1;
	len_line1 = ft_strlen(map_2d[cont1]);
	while (map_2d[cont1])
	{
		while (map_2d[cont2])
		{
			len_line2 = ft_strlen(map_2d[cont2]);
			if (len_line1 != len_line2)
				return (error("Bad shape\n"));
			cont2++;
		}
		cont1++;
		if (cont2 > num_rows(map_2d))
			cont2 = cont1 + 1;
	}
	return (1);
}

int	check_one_char(char **matrix, int c)
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
			if (num > 1)
				return (error("Bad number of simbols\n"));
			col++;
		}
		row++;
		col = 0;
	}
	return (1);
}
