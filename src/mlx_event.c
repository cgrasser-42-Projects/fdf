/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 08:42:48 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/22 00:38:06 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_plan_hook(int key, t_fdf *data)
{
	if (key == R || key == T)
	{
		if (key == R)
			data->plan->angle_z--;
		else
			data->plan->angle_z++;
		data->plan->gamma = data->plan->angle_z * (M_PI / 180.0);
	}
	else if (key == D || key == F)
	{
		if (key == D)
			data->plan->angle_x--;
		else
			data->plan->angle_x++;
		data->plan->alpha = data->plan->angle_x * (M_PI / 180.0);
	}
	else if (key == G || key == H)
	{
		if (key == G)
			data->plan->angle_y--;
		else
			data->plan->angle_y++;
		data->plan->tetha = data->plan->angle_y * (M_PI / 180.0);
	}
	return (mlx_draw_image(data));
}

int	key_plan_iso_hook(int key, t_fdf *data)
{
	if (key == I)
	{
		data->plan->angle_x = 60;
		data->plan->angle_y = 345;
		data->plan->angle_z = 30;
	}
	if (key == O)
	{
		data->plan->angle_x = 0;
		data->plan->angle_y = 0;
		data->plan->angle_z = 0;
	}
	data->plan->alpha = data->plan->angle_x * (M_PI / 180.0);
	data->plan->tetha = data->plan->angle_y * (M_PI / 180.0);
	data->plan->gamma = data->plan->angle_z * (M_PI / 180.0);
	return (mlx_draw_image(data));
}

int	key_hook(int key, t_fdf *data)
{
	if (key == ESCAPE)
		return (mlx_loop_end(data->mlx), 0);
	if (key == R || key == T || key == D
		|| key == F || key == G || key == H)
		return (key_plan_hook(key, data));
	if (key == I || key == O)
		return (key_plan_iso_hook(key, data));
	return (0);
}
