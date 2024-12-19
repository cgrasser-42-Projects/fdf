/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 07:54:57 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/19 09:43:15 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_data(char *file_fdf, t_fdf *data)
{
	file_fdf = 0;
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, HEIGHT, WIDTH, "FDF");
}
