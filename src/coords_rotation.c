/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:41:19 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/21 23:59:11 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_z(t_point *point, t_fdf *data)
{
	double	gamma;
	int		x_translated;
	int		y_translated;
	int		new_x;
	int		new_y;

	gamma = data->plan->gamma;
	x_translated = point->x - (data->map->x * data->plan->zoom) / 2;
	y_translated = point->y - (data->map->y * data->plan->zoom) / 2;
	new_x = x_translated * cos(gamma) - y_translated * sin(gamma);
	new_y = x_translated * sin(gamma) + y_translated * cos(gamma);
	point->x = new_x + (int)((data->map->x * data->plan->zoom) / 2);
	point->y = new_y + (int)((data->map->y * data->plan->zoom) / 2);
}

static void	rotate_y(t_point *point, t_fdf *data)
{
	double	tetha;
	int		x_translated;
	int		new_x;
	int		new_z;

	tetha = data->plan->tetha;
	x_translated = point->x - (data->map->x * data->plan->zoom) / 2;
	new_x = x_translated * cos(tetha) + point->z * sin(tetha);
	new_z = point->z * cos(tetha) + x_translated * cos(tetha);
	point->x = new_x + (int)((data->map->x * data->plan->zoom) / 2);
	point->z = new_z;
}

static void	rotate_x(t_point *point, t_fdf *data)
{
	double	alpha;
	int		y_translated;
	int		new_y;
	int		new_z;

	alpha = data->plan->alpha;
	y_translated = point->y - (data->map->y * data->plan->zoom) / 2;
	new_y = y_translated * cos(alpha) - point->z * sin(alpha);
	new_z = y_translated * sin(alpha) + point->z * cos(alpha);
	point->y = new_y + (int)((data->map->y * data->plan->zoom) / 2);
	point->z = new_z;
}

void	rotate_point(t_point *point, t_fdf *data)
{
	rotate_z(point, data);
	rotate_x(point, data);
	rotate_y(point, data);
}
