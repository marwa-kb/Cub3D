/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:05:21 by mkhabou           #+#    #+#             */
/*   Updated: 2022/04/12 00:05:22 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	find_color(char *ptr, int pixel)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	red = (unsigned int)ptr[pixel + 2];
	green = (unsigned int)ptr[pixel + 1];
	blue = (unsigned int)ptr[pixel + 0];
	return (get_rgb(red, green, blue));
}

int	set_pixel(t_vars *v, int dir)
{
	int	pixel0;
	int	pixel1;
	int	pixel2;
	int	pixel3;
	int	color;

	pixel0 = ((int)v->ray.wall[0].ty
			* (int)v->ray.wall[0].size + (int)v->ray.wall[0].tx) * 4;
	pixel1 = ((int)v->ray.wall[1].ty
			* (int)v->ray.wall[1].size + (int)v->ray.wall[1].tx) * 4;
	pixel2 = ((int)v->ray.wall[2].ty
			* (int)v->ray.wall[2].size + (int)v->ray.wall[2].tx) * 4;
	pixel3 = ((int)v->ray.wall[3].ty
			* (int)v->ray.wall[3].size + (int)v->ray.wall[3].tx) * 4;
	if (dir == 0)
		color = find_color(v->n.addr, pixel0);
	else if (dir == 1)
		color = find_color(v->s.addr, pixel1);
	else if (dir == 2)
		color = find_color(v->w.addr, pixel2);
	else
		color = find_color(v->e.addr, pixel3);
	return (color);
}

void	draw_pixels(t_vars *v, int dir)
{
	int	y;
	int	color;

	y = 0;
	while (y < v->ray.line_h)
	{
		color = set_pixel(v, dir);
		my_mlx_pixel_put2(v, v->ray.r, y + v->ray.line_off, color);
		v->ray.wall[0].ty += v->ray.wall[0].ty_step;
		v->ray.wall[1].ty += v->ray.wall[1].ty_step;
		v->ray.wall[2].ty += v->ray.wall[2].ty_step;
		v->ray.wall[3].ty += v->ray.wall[3].ty_step;
		y++;
	}
}
