/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 06:23:57 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/21 17:46:25 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>

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

typedef struct s_image
{
	void	*img;
	int		*data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_map
{
	t_point	**coords;
	int		x;
	int		y;
}	t_map;

typedef struct s_plan
{
	double	zoom;
	int		shift_x;
	int		shift_y;
	int		angle_x;
	int		angle_y;
	int		angle_z;
	double	alpha;
	double	thetha;
	double	gamma;
}	t_plan;

typedef struct s_fdf
{
	void	*mlx;
	void	*window;
	t_map	*map;
	t_plan	*plan;
	t_image	image;
}	t_fdf;

int		key_hook(int key, t_fdf *data);

void	init_data(char *file_fdf, t_fdf *data);
void	init_data_plan(t_fdf *data);
void	init_data_map(t_fdf *data, char *file_fdf);

void	rotate_z(t_point *point, int rotation);
void	ft_map_iter(t_map *map, void (*f)(t_point *, int), int rotation);

int		mlx_draw_image(t_fdf *data);
void	mlx_destroy_data(t_fdf *data);

void	fdf(char *file_fdf);

#endif
