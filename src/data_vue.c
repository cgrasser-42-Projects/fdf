/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_vue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 22:12:04 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/27 15:24:24 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	reset_plan(t_fdf *data)
{
	double	zoom_x;
	double	zoom_y;

	zoom_x = I_WIDTH / data->map->x / 1.5;
	zoom_y = I_HEIGHT / data->map->y / 1.5;
	if (zoom_x <= zoom_y)
		data->plan->zoom = zoom_x;
	else
		data->plan->zoom = zoom_y;
	data->plan->z_div = 10;
	data->plan->shift_x = (I_WIDTH - data->map->x * data->plan->zoom) / 2;
	data->plan->shift_y = (I_HEIGHT - data->map->y * data->plan->zoom) / 2;
	data->plan->alpha = data->plan->angle_x * (M_PI / 180.0);
	data->plan->tetha = data->plan->angle_y * (M_PI / 180.0);
	data->plan->gamma = data->plan->angle_z * (M_PI / 180.0);
}

void	isometric(t_fdf *data)
{
	data->plan->angle_x = 30;
	data->plan->angle_y = 330;
	data->plan->angle_z = 30;
	reset_plan(data);
}

void	orthographic(t_fdf *data)
{
	data->plan->angle_x = 0;
	data->plan->angle_y = 0;
	data->plan->angle_z = 0;
	reset_plan(data);
}

void	side_vue(t_fdf *data)
{
	data->plan->angle_x = 0;
	data->plan->angle_y = 0;
	data->plan->angle_z = 0;
	reset_plan(data);
}

void	front_vue(t_fdf *data)
{
	data->plan->angle_x = 0;
	data->plan->angle_y = 0;
	data->plan->angle_z = 0;
	reset_plan(data);
}
