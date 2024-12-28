/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:37:07 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/28 13:04:38 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	button_vue(int button, int x, int y, t_fdf *data)
{
	if (button == 1 && (x >= 0 && x <= 150) && (y >= 200 && y <= 240))
		return (isometric(data), mlx_draw_window(data));
	if (button == 1 && (x >= 0 && x <= 150) && (y >= 240 && y <= 280))
		return (side_vue(data), mlx_draw_window(data));
	if (button == 1 && (x >= 150 && x <= 300) && (y >= 200 && y <= 240))
		return (orthographic(data), mlx_draw_window(data));
	if (button == 1 && (x >= 150 && x <= 300) && (y >= 240 && y <= 280))
		return (front_vue(data), mlx_draw_window(data));
	return (0);
}

int	scroll_hook(int button, int x, int y, t_fdf *data)
{
	(void) x;
	(void) y;
	if (button == 4)
		data->plan->zoom++;
	if (button == 5)
		data->plan->zoom--;
	return (mlx_draw_window(data));
}

int	mouse_hook(int button, int x, int y, t_fdf *data)
{
	if (button == 4 || button == 5)
		return (scroll_hook(button, x, y, data));
	if (button == 1)
		return (button_vue(button, x, y, data));
	return (0);
}
