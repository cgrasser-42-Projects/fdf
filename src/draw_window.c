/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:57:27 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/28 12:34:37 by cgrasser         ###   ########.fr       */
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

static void	put_text(t_fdf *data)
{
	mlx_string_put(data->mlx, data->window,
		45, 220, 0xFFFFFF, "isometric");
	mlx_string_put(data->mlx, data->window,
		195, 220, 0xFFFFFF, "orthographic");
	mlx_string_put(data->mlx, data->window,
		60, 260, 0xFFFFFF, "side");
	mlx_string_put(data->mlx, data->window,
		210, 260, 0xFFFFFF, "front");
}

static void	set_values_menu(t_fdf *data)
{
	data->menu->x = ft_itoa(data->plan->angle_x);
	data->menu->y = ft_itoa(data->plan->angle_y);
	data->menu->z = ft_itoa(data->plan->angle_z);
	data->menu->zoom = ft_itoa(data->plan->zoom);
	data->menu->shift_x = ft_itoa(data->plan->shift_x);
	data->menu->shift_y = ft_itoa(data->plan->shift_y);
	data->menu->z_div = ft_itoa(data->plan->z_div);
}

static void	put_button(t_fdf *data)
{
	if (data->menu->vue == ORTHO)
		mlx_put_image_to_window(data->mlx, data->window,
			data->menu->button, 150, 200);
	if (data->menu->vue == ISO)
		mlx_put_image_to_window(data->mlx, data->window,
			data->menu->button, 0, 200);
	if (data->menu->vue == SIDE)
		mlx_put_image_to_window(data->mlx, data->window,
			data->menu->button, 0, 240);
	if (data->menu->vue == FRONT)
		mlx_put_image_to_window(data->mlx, data->window,
			data->menu->button, 150, 240);
}

int	mlx_draw_window(t_fdf *data)
{
	mlx_clear_window(data->mlx, data->window);
	mlx_put_image_to_window(data->mlx, data->window, data->menu->img, 0, 0);
	put_button(data);
	clear_values_menu(data->menu);
	set_values_menu(data);
	put_values_menu(data);
	put_text(data);
	return (mlx_draw_image(data));
}
