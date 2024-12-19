/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 07:54:57 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/19 17:41:22 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_coords(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
			ft_printf("%3d", map->coords[y][x++].z);
		ft_printf("\n");
		y++;
	}
}

void	init_data(char *file_fdf, t_fdf *data)
{
	init_data_map(data, file_fdf);
	ft_print_coords(data->map);
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, HEIGHT, WIDTH, "FDF");
}
