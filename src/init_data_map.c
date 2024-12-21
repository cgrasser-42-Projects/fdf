/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:21:28 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/21 17:41:19 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_map_x_y(t_map *map, char *file_fdf)
{
	int		fd;
	char	*line;
	char	**nums;

	fd = open(file_fdf, O_RDONLY);
	if (fd < 0)
		exit(1);
	line = get_next_line(fd);
	nums = ft_split(line, " \n");
	map->x = ft_strslen(nums);
	ft_strs_clear(nums);
	map->y = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		map->y++;
	}
	close(fd);
}

void	init_map_coords(t_map *map)
{
	int	i;

	map->coords = malloc((map->y + 1) * sizeof(t_point *));
	i = 0;
	while (i < map->y)
		map->coords[i++] = malloc(map->x * sizeof(t_point));
	map->coords[i] = NULL;
}

void	init_map_points(t_point *points, int y, char *line)
{
	char	**nums;
	int		x;

	nums = ft_split(line, " \n");
	x = 0;
	while (nums[x])
	{
		points[x].x = x;
		points[x].y = y;
		points[x].z = ft_atoi(nums[x]);
		points[x].color = 0xffffff;
		free(nums[x++]);
	}
	free(nums);
}

void	init_data_map(t_fdf *data, char *file_fdf)
{
	int		fd;
	int		y;
	char	*line;

	data->map = malloc(sizeof(t_map));
	init_map_x_y(data->map, file_fdf);
	init_map_coords(data->map);
	fd = open(file_fdf, O_RDONLY);
	if (fd < 0)
		exit(1);
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		init_map_points(data->map->coords[y], y, line);
		free(line);
		line = get_next_line(fd);
		y++;
	}
	close(fd);
}
