/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/02/14 10:06:23 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_list	*ft_new_node(int x, int y, char value, int pos)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		exit(0);
	node->x = x;
	node->y = y;
	node->value = value;
	node->pos = pos;
	node->next = NULL;
	return (node);
}

int	vertex_num(char **map)
{
	int	num;
	int	row;
	int	col;

	num = 0;
	row = 0;
	col = 0;
	while (map[row])
	{
		while (map[row][col])
		{
			if (map[row][col] != '1')
				num++;
			col++;
		}
		row++;
		col = 0;
	}
	return (num);
}

int	entry_pos(char **map, int x, int y)
{
	int	row;
	int	col;
	int	pos;

	row = 0;
	col = 0;
	pos = 0;
	while (map[row])
	{
		while (map[row][col])
		{
			if (map[row][col] != '1' && (x == col && y == row))
				return (pos);
			if (map[row][col] != '1')
				pos++;
			col++;
		}
		row++;
		col = 0;
	}
	return (-1);
}

void	set_adyacent_lst(t_list **lst, char **map, int row, int col)
{
	if (map[row][col - 1] != '1')
		ft_lstadd_back(lst, ft_new_node(col - 1, row, map[row][col - 1],
				entry_pos(map, col - 1, row)));
	if (map[row][col + 1] != '1')
		ft_lstadd_back(lst, ft_new_node(col + 1, row, map[row][col + 1],
				entry_pos(map, col + 1, row)));
	if (map[row - 1][col] != '1')
		ft_lstadd_back(lst, ft_new_node(col, row - 1, map[row - 1][col],
				entry_pos(map, col, row - 1)));
	if (map[row + 1][col] != '1')
		ft_lstadd_back(lst, ft_new_node(col, row + 1, map[row + 1][col],
				entry_pos(map, col, row + 1)));
}

t_list	**set_entries(t_list **graph, char **map)
{
	int		row;
	int		col;
	int		pos;
	t_list	*curr;

	row = 0;
	col = 0;
	pos = 0;
	while (map[row])
	{
		while (map[row][col])
		{
			if (map[row][col] != '1')
			{
				graph[pos] = ft_new_node(col, row, map[row][col], pos);
				curr = graph[pos];
				set_adyacent_lst(&curr, map, row, col);
				pos++;
			}
			col++;
		}
		row++;
		col = 0;
	}
	return (graph);
}
