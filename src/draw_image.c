/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:32:23 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/27 13:41:38 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	apply_shift(t_point *point, t_plan *plan)
{
	point->x += plan->shift_x;
	point->y += plan->shift_y;
}

void	apply_zoom(t_point *point, t_plan *plan)
{
	point->x *= plan->zoom;
	point->y *= plan->zoom;
	point->z *= plan->zoom;
	point->z /= plan->z_div;
}

static void	bresenham(t_point point_a, t_point point_b, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;

	apply_zoom(&point_a, data->plan);
	apply_zoom(&point_b, data->plan);
	rotate_point(&point_a, data);
	rotate_point(&point_b, data);
	apply_shift(&point_a, data->plan);
	apply_shift(&point_b, data->plan);
	x_step = point_b.x - point_a.x;
	y_step = point_b.y - point_a.y;
	max = fmax(fabs(x_step), fabs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(point_a.x - point_b.x) || (int)(point_a.y - point_b.y))
	{
		if ((int)point_a.x >= 0 && (int)point_a.x < I_WIDTH
			&& (int)point_a.y >= 0 && (int)point_a.y < I_HEIGHT)
			data->image.data[(int)point_a.y * I_WIDTH + (int)point_a.x]
				= point_a.color;
		point_a.x += x_step;
		point_a.y += y_step;
	}
}

static void	draw_map(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->y)
	{
		x = 0;
		while (x < data->map->x)
		{
			if (x < data->map->x - 1)
				bresenham(data->map->coords[y][x],
					data->map->coords[y][x +1], data);
			if (y < data->map->y - 1)
				bresenham(data->map->coords[y][x],
					data->map->coords[y +1][x], data);
			x++;
		}
		y++;
	}
}

int	mlx_draw_image(t_fdf *data)
{
	ft_bzero(data->image.data, I_HEIGHT * I_WIDTH * sizeof(int));
	draw_map(data);
	return (mlx_put_image_to_window(data->mlx, data->window,
			data->image.img, 300, 100));
}
