/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_burning_ship.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:04:13 by jergashe          #+#    #+#             */
/*   Updated: 2022/12/30 10:27:19 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lib_frac.h"

void	restart_burning_ship(t_instances *instances)
{
	t_axe	*axe;

	axe = instances->axe;
	axe->end_x = 2.0;
	axe->start_x = -2.0;
	axe->end_y = 2.0;
	axe->start_y = -2.0;
	axe->y_offset = 0.0;
	axe->x_offset = 0.0;
	axe->width_axe = axe->end_x - axe->start_x;
	axe->height_axe = axe->end_y - axe->start_y;
	instances->max_iter = 80.0;
}

void	burning_ship_keyhook(void *param)
{
	t_instances	*instances;

	instances = (t_instances *)param;
	if (mlx_is_key_down(instances->mlx, MLX_KEY_RIGHT))
		move_real(instances, instances->axe->width_axe / 20);
	else if (mlx_is_key_down(instances->mlx, MLX_KEY_LEFT))
		move_real(instances, (-1) * instances->axe->width_axe / 20);
	else if (mlx_is_key_down(instances->mlx, MLX_KEY_UP))
		move_imaginary(instances, (-1) * instances->axe->height_axe / 20);
	else if (mlx_is_key_down(instances->mlx, MLX_KEY_DOWN))
		move_imaginary(instances, instances->axe->height_axe / 20);
	draw_burning_ship(instances);
	if (mlx_is_key_down(instances->mlx, MLX_KEY_R))
		restart_burning_ship(instances);
	else if (mlx_is_key_down(instances->mlx, MLX_KEY_M))
		draw_mandelbrot(instances);
}
