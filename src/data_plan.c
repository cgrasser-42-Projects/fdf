/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_plan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 22:12:04 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/26 22:49:29 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	reset_plan(t_plan *plan)
{
	plan->z_div = 10;
	plan->shift_x = (WIDTH - map->x * plan->zoom) / 2;
	plan->shift_y = (HEIGHT - map->y * plan->zoom) / 2;
	plan->alpha = plan->angle_x * (M_PI / 180.0);
	plan->tetha = plan->angle_y * (M_PI / 180.0);
	plan->gamma = plan->angle_z * (M_PI / 180.0);
}

void	isometric(t_plan *plan)
{
	plan->angle_x = 30;
	plan->angle_y = 330;
	plan->angle_z = 30;
	reset_plan(plan);
}

void	orthographic(t_plan *plan)
{
	plan->angle_x = 0;
	plan->angle_y = 0;
	plan->angle_z = 0;
	reset_plan(plan);
}

void	side_vue(t_plan *plan)
{
	plan->angle_x = 0;
	plan->angle_y = 0;
	plan->angle_z = 0;
	reset_plan(plan);
}

void	front_vue(t_plan *plan)
{
	plan->angle_x = 0;
	plan->angle_y = 0;
	plan->angle_z = 0;
	reset_plan(plan);
}
