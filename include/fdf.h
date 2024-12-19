/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 06:23:57 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/19 09:44:36 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include "mlx_key.h"

# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_map
{
	t_point	**coords;
	int		x;
	int		y;
}	t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*window;
	t_map	map;
}	t_fdf;

int		key_hook(int key, t_fdf *data);

void	init_data(char *file_fdf, t_fdf *data);

void	fdf(char *file_fdf);

#endif
