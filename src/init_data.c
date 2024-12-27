/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 07:54:57 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/27 15:42:47 by cgrasser         ###   ########.fr       */
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

void	init_menu(t_fdf *data)
{
	data->menu = malloc(sizeof(t_menu));
	data->menu->img = mlx_xpm_file_to_image(data->mlx, "resources/menu.xpm",
			&data->menu->x_img, &data->menu->y_img);
	data->menu->x = ft_itoa(data->plan->angle_x);
	data->menu->y = ft_itoa(data->plan->angle_y);
	data->menu->z = ft_itoa(data->plan->angle_z);
	data->menu->zoom = ft_itoa(data->plan->zoom);
	data->menu->shift_x = ft_itoa(data->plan->shift_x);
	data->menu->shift_y = ft_itoa(data->plan->shift_y);
	data->menu->z_div = ft_itoa(data->plan->z_div);
}

void	init_data(char *file_fdf, t_fdf *data)
{
	init_data_map(data, file_fdf);
	init_data_plan(data);
	data->mlx = mlx_init();
	init_menu(data);
	data->window = mlx_new_window(data->mlx, W_WIDTH, W_HEIGHT, "FDF");
	data->image.img = mlx_new_image(data->mlx, I_WIDTH, I_HEIGHT);
	data->image.data = (int *) mlx_get_data_addr(data->image.img,
			&data->image.bits_per_pixel, &data->image.size_line,
			&data->image.endian);
}
