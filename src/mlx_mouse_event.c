/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:37:07 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/28 14:48:25 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	reset_vue(t_fdf *data)
{
	if (data->menu->vue == ISO)
		isometric(data);
	else if (data->menu->vue == ORTHO)
		orthographic(data);
	else if (data->menu->vue == SIDE)
		side_vue(data);
	else if (data->menu->vue == FRONT)
		front_vue(data);
	return (mlx_draw_window(data));
}

int	button_vue(int x, int y, t_fdf *data)
{
	if ((x >= 0 && x <= 150) && (y >= 200 && y <= 240))
		return (isometric(data), mlx_draw_window(data));
	if ((x >= 0 && x <= 150) && (y >= 240 && y <= 280))
		return (side_vue(data), mlx_draw_window(data));
	if ((x >= 150 && x <= 300) && (y >= 200 && y <= 240))
		return (orthographic(data), mlx_draw_window(data));
	if ((x >= 150 && x <= 300) && (y >= 240 && y <= 280))
		return (front_vue(data), mlx_draw_window(data));
	if ((x >= 80 && x <= 227) && (y >= 1000 && y <= 1040))
		return (reset_vue(data));
	return (0);
}

int	scroll_hook(int button, int x, int y, t_fdf *data)
{
	(void) x;
	(void) y;
	if (button == 4)
	{
		data->plan->zoom++;
		data->plan->shift_x -= data->map->x / 2;
		data->plan->shift_y -= data->map->y / 2;
	}
	if (button == 5)
	{
		data->plan->zoom--;
		if (data->plan->zoom < 1)
			return (data->plan->zoom = 1, 0);
		data->plan->shift_x += data->map->x / 2;
		data->plan->shift_y += data->map->y / 2;
	}
	return (mlx_draw_window(data));
}

int	mouse_hook(int button, int x, int y, t_fdf *data)
{
	if (data->menu->is_active == 0)
		return (0);
	if (button == 4 || button == 5)
		return (scroll_hook(button, x, y, data));
	if (button == 1)
		return (button_vue(x, y, data));
	return (0);
}
