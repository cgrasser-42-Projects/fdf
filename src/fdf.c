/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 06:57:44 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/27 17:11:30 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_hooks(t_fdf *data)
{
	mlx_hook(data->window, DESTROYNOTIFY, KEYRELEASEMASK,
		mlx_loop_end, data->mlx);
	mlx_mouse_hook(data->window, mouse_hook, data);
	mlx_hook(data->window, KEYPRESS, KEYPRESSMASK, key_hook, data);
}

void	fdf(char *file_fdf)
{
	t_fdf	data;

	init_data(file_fdf, &data);
	init_hooks(&data);
	mlx_draw_window(&data);
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.image.img);
	mlx_destroy_image(data.mlx, data.menu->img);
	mlx_destroy_image(data.mlx, data.menu->button);
	mlx_destroy_window(data.mlx, data.window);
	mlx_destroy_display(data.mlx);
	mlx_destroy_data(&data);
}
