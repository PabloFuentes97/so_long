/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/02/15 09:52:44 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(int fd)
{
	int		len;
	char	*buf;
	int		bytes;

	len = 1;
	bytes = 1;
	while (bytes > 0)
	{
		buf = malloc(sizeof(char) * 2);
		bytes = read(fd, buf, 1);
		if (bytes > 0)
		{
			buf[1] = '\0';
			if (buf[0] == '\n')
				len++;
		}
		free(buf);
	}
	return (len);
}

static char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned long int		c1;
	unsigned long int		c2;

	if (to_find[0] == '\0')
		return ((char *)str);
	if (len == 0 && !str)
		return (0);
	c1 = 0;
	while (c1 < len && str[c1] != '\0')
	{
		c2 = 0;
		if ((str[c1 + c2]) && str[c1 + c2] == to_find[c2])
		{
			while ((str[c1 + c2])
				&& (str[c1 + c2] == to_find[c2]) && (c1 + c2) < len)
			{
				c2++;
				if (to_find[c2] == '\0')
					return ((char *)&str[c1]);
			}
		}
	c1++;
	}
	return (0);
}

static int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	cont;

	cont = 0;
	while (cont < n && (s1[cont] || s2[cont]))
	{
		if (s1[cont] != s2[cont])
			return ((unsigned char)s1[cont] - (unsigned char)s2[cont]);
		cont++;
	}
	return (0);
}

void	fill_map(t_mlx *mlx, char *file, int len)
{
	int	cont;
	int	fd;

	cont = 0;
	fd = open(file, O_RDONLY);
	mlx->map = (char **)malloc(sizeof(char *) * (len + 1));
	mlx->map[len] = NULL;
	while (cont < len)
	{
		mlx->map[cont] = get_next_line(fd);
		if (!mlx->map[cont])
		{
			free_array2d(mlx->map, cont);
			error_exit("Bad EOF\n");
		}
		cont++;
	}
	close(fd);
}

void	create_map(t_mlx *mlx, char *file)
{
	int		fd;
	int		len;
	char	*format;

	if (file)
	{
		format = ft_strnstr(file, ".ber", ft_strlen(file));
		if (format)
		{
			if (ft_strncmp(format, ".ber", 5) != 0)
				error_exit("Bad format\n");
		}
		else
			error_exit("Bad format\n");
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("Bad file\n");
	len = count_lines(fd);
	close(fd);
	fill_map(mlx, file, len);
	if (check_map(mlx->map, len) == 0)
		exit(1);
}
