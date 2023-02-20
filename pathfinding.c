/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/02/15 09:47:00 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_list	**create_graph(char **map)
{
	int		vertices;
	t_list	**graph;

	vertices = vertex_num(map);
	graph = malloc(sizeof(t_list *) * vertices + 1);
	graph[vertices] = NULL;
	graph = set_entries(graph, map);
	return (graph);
}

static int	check_result(t_list *queue, t_list *visited,
	int cont_objs, int objs)
{
	free_list(&visited);
	free_list(&queue);
	if (cont_objs == objs)
		return (1);
	return (0);
}

static int	pathfinding(t_list **graph, t_list *player,
		int cont_objs, int objs)
{
	t_list		*c;
	t_list		*q;
	t_list		*v;

	v = NULL;
	q = ft_new_node(player->x, player->y, player->value, player->pos);
	while (q && cont_objs != objs)
	{
		if (q->value == 'C' || q->value == 'E')
			cont_objs++;
		ft_lstadd_back(&v, ft_new_node(q->x, q->y, q->value, q->pos));
		c = graph[q->pos]->next;
		while (c)
		{
			if (find_node(v, c->x, c->y) == 0)
			{
				ft_lstadd_back(&v, ft_new_node(c->x, c->y, c->value, c->pos));
				ft_lstadd_back(&q, ft_new_node(c->x, c->y, c->value, c->pos));
			}
			c = c->next;
		}
		remove_head(&q);
	}
	return (check_result(q, v, cont_objs, objs));
}

void	call_pathfinding(char **map)
{
	t_list	**graph;
	t_list	*player;

	graph = create_graph(map);
	player = find_player(graph);
	if (pathfinding(graph, player, 0,
			num_collectables(map) + 1) == 1)
	{
		free_graph(graph);
		player = NULL;
	}
	else
	{
		free_graph(graph);
		player = NULL;
		error_exit("No possible path to exit or/and collectables\n");
	}
}
