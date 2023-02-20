/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/02/10 12:50:17 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_node(t_list *lst, int x, int y)
{
	t_list	*curr;

	if (lst)
	{
		curr = lst;
		while (curr)
		{
			if (curr->x == x && curr->y == y && curr->value != '1')
				return (1);
			curr = curr->next;
		}
		return (0);
	}
	return (0);
}

t_list	*find_player(t_list **graph)
{
	t_list	*entry;
	int		pos;

	pos = 0;
	while (graph[pos])
	{
		entry = graph[pos];
		if (entry->value == 'P')
			return (entry);
		pos++;
	}
	return (NULL);
}

int	num_collectables(char **map)
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
			if (map[row][col] == 'C')
				num++;
			col++;
		}
		row++;
		col = 0;
	}
	return (num);
}

void	free_list(t_list **head)
{
	t_list	*curr;
	t_list	*next;

	if (head)
	{
		if (*head)
		{
			curr = *head;
			while (curr)
			{
				next = (curr)->next;
				curr->next = NULL;
				free(curr);
				curr = next;
			}
		}
	}
	head = NULL;
}

void	free_graph(t_list **graph)
{
	int		cont;

	cont = 0;
	if (graph)
	{
		while (graph[cont])
		{
			free_list(&graph[cont]);
			cont++;
		}
		free(graph);
	}
	graph = NULL;
}
