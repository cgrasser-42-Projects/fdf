/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 06:23:57 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/28 14:41:35 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>

# include "libft.h"
# include "mlx.h"
# include "mlx_key.h"

# define W_WIDTH 1300
# define W_HEIGHT 1100
# define I_WIDTH 1000
# define I_HEIGHT 1000

typedef enum e_vue
{
	ISO,
	ORTHO,
	SIDE,
	FRONT
}	t_vue;

typedef struct s_point
{
	float	x;
	float	y;
	int		z;
	int		color;
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
	int		z_div;
	int		shift_x;
	int		shift_y;
	int		angle_x;
	int		angle_y;
	int		angle_z;
	double	alpha;
	double	tetha;
	double	gamma;
}	t_plan;

typedef struct s_menu
{
	t_vue	vue;
	int		x_main;
	int		y_main;
	char	*main;
	int		is_active;
	int		x_img;
	int		y_img;
	char	*img;
	int		x_button;
	int		y_button;
	char	*button;
	char	*x;
	char	*y;
	char	*z;
	char	*zoom;
	char	*shift_x;
	char	*shift_y;
	char	*z_div;
}	t_menu;

typedef struct s_fdf
{
	void	*mlx;
	void	*window;
	t_menu	*menu;
	t_map	*map;
	t_plan	*plan;
	t_image	image;
}	t_fdf;

int		key_hook(int key, t_fdf *data);
int		mouse_hook(int button, int x, int y, t_fdf *data);

void	init_data(char *file_fdf, t_fdf *data);
void	init_data_plan(t_fdf *data);
void	init_data_map(t_fdf *data, char *file_fdf);

void	rotate_point(t_point *point, t_fdf *data);
void	set_valid_angle(t_plan *plan);

void	isometric(t_fdf *data);
void	orthographic(t_fdf *data);
void	side_vue(t_fdf *data);
void	front_vue(t_fdf *data);

int		mlx_draw_window(t_fdf *data);
int		mlx_draw_image(t_fdf *data);

void	mlx_destroy_data(t_fdf *data);
void	clear_values_menu(t_menu *menu);

void	fdf(char *file_fdf);

#endif
