/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_plan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:28:39 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/27 13:39:15 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_data_zoom(t_fdf *data)
{
	double	zoom_max_x;
	double	zoom_max_y;

	zoom_max_x = I_WIDTH / data->map->x / 1.5;
	zoom_max_y = I_HEIGHT / data->map->y / 1.5;
	if (zoom_max_x <= zoom_max_y)
		data->plan->zoom = zoom_max_x;
	else
		data->plan->zoom = zoom_max_y;
}

void	init_data_plan(t_fdf *data)
{
	data->plan = malloc(sizeof(t_plan));
	init_data_zoom(data);
	data->plan->z_div = 10;
	data->plan->shift_x = (I_WIDTH - data->map->x * data->plan->zoom) / 2;
	data->plan->shift_y = (I_HEIGHT - data->map->y * data->plan->zoom) / 2;
	data->plan->angle_x = 0;
	data->plan->angle_y = 0;
	data->plan->angle_z = 0;
	data->plan->alpha = data->plan->angle_x * (M_PI / 180.0);
	data->plan->tetha = data->plan->angle_y * (M_PI / 180.0);
	data->plan->gamma = data->plan->angle_z * (M_PI / 180.0);
}
