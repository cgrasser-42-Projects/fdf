/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:27:20 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/27 15:36:11 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_map_clear(t_point **coords)
{
	int	i;

	i = 0;
	while (coords[i])
		free(coords[i++]);
	free(coords);
}

void	mlx_destroy_data(t_fdf *data)
{
	ft_map_clear(data->map->coords);
	free(data->map);
	free(data->mlx);
	free(data->plan);
	clear_values_menu(data->menu);
	free(data->menu);
}
