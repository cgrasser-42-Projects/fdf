/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:32:23 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/21 17:45:17 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
}

static void	bresenham(t_point point_a, t_point point_b, t_fdf *data)
{
	int	x_step;
	int	y_step;
	int	max;

	apply_zoom(&point_a, data->plan);
	apply_zoom(&point_b, data->plan);
	apply_shift(&point_a, data->plan);
	apply_shift(&point_b, data->plan);
	x_step = point_b.x - point_a.x;
	y_step = point_b.y - point_a.y;
	max = fmax(abs(x_step), abs(y_step));
	x_step /= max;
	y_step /= max;
	while (point_a.x - point_b.x || point_a.y - point_b.y)
	{
		if (point_a.x >= 0 && point_a.x < WIDTH
			&& point_a.y >= 0 && point_a.y < HEIGHT)
			data->image.data[point_a.y * WIDTH + point_a.x] = point_a.color;
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
	ft_bzero(data->image.data, HEIGHT * WIDTH * sizeof(int));
	draw_map(data);
	return (mlx_put_image_to_window(data->mlx, data->window,
			data->image.img, 0, 0));
}
