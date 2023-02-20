/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/02/15 09:56:10 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <sys/fcntl.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>
# include <mlx.h>
# include <math.h>

# define IMG_WIDTH 16
# define IMG_HEIGHT 16
# define X_OFFSET 20
# define Y_OFFSET 20

typedef struct s_list
{
	int				x;
	int				y;
	int				pos;
	char			value;
	struct s_list	*next;
}	t_list;

typedef struct s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct s_player
{
	int		x;
	int		y;
	int		pixel_x;
	int		pixel_y;
	int		to_move;
	int		to_move_x;
	int		to_move_y;
}			t_player;

typedef struct s_info
{
	int		coll_add;
	int		coll_total;
	int		x_exit;
	int		y_exit;
	int		step_x;
	int		step_y;
}				t_info;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		**img;
	t_player	*player;
	t_info		*info;
	char		**map;
}				t_mlx;

//create and check map
char		*get_next_line(int fd);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
void		*ft_calloc(size_t count, size_t size);
char		*free_join(char *buf, char *stash);
size_t		ft_strlen(const char *str);
char		*ft_itoa(int n);
void		free_array2d(char **array_2d, int j);
int			num_len(unsigned int n);
void		create_map(t_mlx *mlx, char *file);
int			error(char *message);
void		error_exit(char *message);
int			valid_shape(char **map_2d);
int			check_hor_limits(char **map_2d, int row);
int			check_ver_limits(char	**map_2d, int col, int len);
int			check_simbols(char **map_2d, int len);
int			check_one_char(char **matrix, int c);
int			check_map(char **map_2d, int len);
int			num_rows(char **matrix);

//create graph and pathfinding
t_list		*ft_new_node(int x, int y, char value, int pos);
int			search_adyacent(char **map, int row, int col);
int			vertex_num(char **map);
int			entry_pos(char **map, int x, int y);
void		set_adyacent_lst(t_list **lst, char **map, int row, int col);
t_list		**set_entries(t_list **graph, char **map);
int			find_node(t_list *lst, int x, int y);
t_list		*find_player(t_list **graph);
int			num_collectables(char **map);
void		free_list(t_list **head);
void		free_graph(t_list **graph);
int			check_result_coll(t_list *queue, t_list *visited,
				int cont_col, int num_coll);
int			check_result_exit(t_list *queue, t_list *visited);
void		call_pathfinding(char **map);

//mlx
t_img		xpm_to_img(t_mlx mlx, char *path);
int			key_hook(int keycode, t_mlx *mlx);
int			exit_hook(void);
void		print_steps(t_mlx mlx);
void		draw_low_map(t_mlx mlx);
void		draw_high_map(t_mlx mlx);
void		animate_collectable(t_mlx mlx, int frame);
void		animate_enemy(t_mlx mlx, int frame);
int			animate_sprites(t_mlx *mlx);
void		print_image_char(t_mlx mlx, char c, t_img img);
void		set_images(t_mlx *mlx);
void		set_player_images(t_mlx mlx);
void		set_floor_images(t_mlx mlx);
void		set_obstacle_images(t_mlx mlx);
void		set_collectable_images(t_mlx mlx);
void		set_exit_images(t_mlx mlx);
void		set_info(t_mlx *mlx);
void		set_player(t_mlx *mlx);
void		move_character(t_mlx *mlx, int x, int y);
void		change_move_pos(t_mlx *mlx, int x, int y);
void		draw_player_next(t_mlx *mlx, int x, int y);
void		player_death_explosion(t_mlx *mlx);
void		exit_entry(t_mlx *mlx);
void		remove_head(t_list **lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);

#endif