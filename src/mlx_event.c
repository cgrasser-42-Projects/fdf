/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 08:42:48 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/28 14:37:05 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_rotation_hook(int key, t_fdf *data)
{
	if (key == R)
		data->plan->angle_z--;
	else if (key == T)
		data->plan->angle_z++;
	else if (key == D)
		data->plan->angle_x--;
	else if (key == F)
		data->plan->angle_x++;
	else if (key == G)
		data->plan->angle_y--;
	else if (key == H)
		data->plan->angle_y++;
	set_valid_angle(data->plan);
	return (mlx_draw_window(data));
}

static int	key_vue_hook(int key, t_fdf *data)
{
	if (key == I)
		isometric(data);
	else if (key == O)
		orthographic(data);
	else if (key == P)
		front_vue(data);
	else if (key == L)
		side_vue(data);
	return (mlx_draw_window(data));
}

static int	key_shift_hook(int key, t_fdf *data)
{
	if (key == UP)
		data->plan->shift_y -= 15;
	else if (key == DOWN)
		data->plan->shift_y += 15;
	else if (key == LEFT)
		data->plan->shift_x -= 15;
	else if (key == RIGHT)
		data->plan->shift_x += 15;
	return (mlx_draw_window(data));
}

static int	key_zdiv_hook(int key, t_fdf *data)
{
	if (key == PLUS)
		data->plan->z_div++;
	if (key == MINUS)
		data->plan->z_div--;
	if (data->plan->z_div == 0)
		data->plan->z_div = 1;
	return (mlx_draw_window(data));
}

int	key_hook(int key, t_fdf *data)
{
	if (key == SPACE && data->menu->is_active == 0)
		return (data->menu->is_active = 1, mlx_draw_window(data));
	if (data->menu->is_active == 0)
		return (0);
	if (key == ESCAPE)
		mlx_loop_end(data->mlx);
	else if (key == R || key == T || key == D
		|| key == F || key == G || key == H)
		return (key_rotation_hook(key, data));
	else if (key == I || key == O || key == P || key == L)
		return (key_vue_hook(key, data));
	else if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		return (key_shift_hook(key, data));
	else if (key == PLUS || key == MINUS)
		return (key_zdiv_hook(key, data));
	return (0);
}
