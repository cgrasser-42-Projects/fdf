/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 06:57:44 by cgrasser          #+#    #+#             */
/*   Updated: 2025/01/17 17:30:46 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw(t_fdf *data)
{
	if (data->menu->is_active == 1)
	{
		mlx_draw_window(data);
		data->is_print = 1;
	}
	return (0);
}

static void	init_hooks(t_fdf *data)
{
	mlx_put_image_to_window(data->mlx, data->window, data->menu->main, 0, 0);
	mlx_hook(data->window, DESTROYNOTIFY, KEYRELEASEMASK,
		mlx_loop_end, data->mlx);
	mlx_mouse_hook(data->window, mouse_hook, data);
	mlx_hook(data->window, KEYPRESS, KEYPRESSMASK, key_hook, data);
	mlx_loop_hook(data->mlx, draw, data);
}

void	fdf(char *file_fdf)
{
	t_fdf	*data;

	data = malloc(sizeof(t_fdf));
	init_data(file_fdf, data);
	init_hooks(data);
	mlx_loop(data->mlx);
	mlx_destroy_image(data->mlx, data->image.img);
	mlx_destroy_image(data->mlx, data->menu->main);
	mlx_destroy_image(data->mlx, data->menu->img);
	mlx_destroy_image(data->mlx, data->menu->button);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	mlx_destroy_data(data);
	free(data);
}
