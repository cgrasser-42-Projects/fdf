/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:37:07 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/27 13:13:44 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	scroll_hook(int button, int x, int y, t_fdf *data)
{
	(void) x;
	(void) y;
	if (button == 4 || button == 5)
	{
		if (button == 4)
			data->plan->zoom++;
		if (button == 5)
			data->plan->zoom--;
		return (mlx_draw_image(data));
	}
	return (0);
}
