/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:57:27 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/27 15:43:46 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_values_menu(t_fdf *data)
{
	mlx_string_put(data->mlx, data->window, 360, 67, 0xFFFFFF, data->menu->x);
	mlx_string_put(data->mlx, data->window, 470, 67, 0xFFFFFF, data->menu->y);
	mlx_string_put(data->mlx, data->window, 580, 67, 0xFFFFFF, data->menu->z);
	mlx_string_put(data->mlx, data->window,
		720, 67, 0xFFFFFF, data->menu->zoom);
	mlx_string_put(data->mlx, data->window,
		870, 67, 0xFFFFFF, data->menu->shift_x);
	mlx_string_put(data->mlx, data->window,
		1020, 67, 0xFFFFFF, data->menu->shift_y);
	mlx_string_put(data->mlx, data->window,
		1200, 67, 0xFFFFFF, data->menu->z_div);
}

void	set_values_menu(t_fdf *data)
{
	data->menu->x = ft_itoa(data->plan->angle_x);
	data->menu->y = ft_itoa(data->plan->angle_y);
	data->menu->z = ft_itoa(data->plan->angle_z);
	data->menu->zoom = ft_itoa(data->plan->zoom);
	data->menu->shift_x = ft_itoa(data->plan->shift_x);
	data->menu->shift_y = ft_itoa(data->plan->shift_y);
	data->menu->z_div = ft_itoa(data->plan->z_div);
}

void	clear_values_menu(t_menu *menu)
{
	free(menu->x);
	free(menu->y);
	free(menu->z);
	free(menu->zoom);
	free(menu->shift_x);
	free(menu->shift_y);
	free(menu->z_div);
}

int	mlx_draw_window(t_fdf *data)
{
	mlx_clear_window(data->mlx, data->window);
	mlx_put_image_to_window(data->mlx, data->window, data->menu->img, 0, 0);
	clear_values_menu(data->menu);
	set_values_menu(data);
	put_values_menu(data);
	return (mlx_draw_image(data));
}
