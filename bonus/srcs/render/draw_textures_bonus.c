/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:03:58 by mkhabou           #+#    #+#             */
/*   Updated: 2022/04/12 00:04:00 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	set_west_and_east(t_vars *v, int *dir, float ry, float ra)
{
	v->ray.wall[0].tx = (int)(ry
			* (v->ray.wall[0].size / 64)) % (int)v->ray.wall[0].size;
	v->ray.wall[1].tx = (int)(ry
			* (v->ray.wall[1].size / 64)) % (int)v->ray.wall[1].size;
	v->ray.wall[2].tx = (int)(ry
			* (v->ray.wall[2].size / 64)) % (int)v->ray.wall[2].size;
	v->ray.wall[3].tx = (int)(ry
			* (v->ray.wall[3].size / 64)) % (int)v->ray.wall[3].size;
	if (ra > 90 && ra < 270)
	{
		v->ray.wall[0].tx = (v->ray.wall[0].size - 1) - v->ray.wall[0].tx;
		v->ray.wall[1].tx = (v->ray.wall[1].size - 1) - v->ray.wall[1].tx;
		v->ray.wall[2].tx = (v->ray.wall[2].size - 1) - v->ray.wall[2].tx;
		v->ray.wall[3].tx = (v->ray.wall[3].size - 1) - v->ray.wall[3].tx;
		*dir = 2;
	}
	else
		*dir = 3;
}

void	set_north_and_south(t_vars *v, int *dir, float rx, float ra)
{
	v->ray.wall[0].tx = (int)(rx
			* (v->ray.wall[0].size / 64)) % (int)v->ray.wall[0].size;
	v->ray.wall[1].tx = (int)(rx
			* (v->ray.wall[1].size / 64)) % (int)v->ray.wall[1].size;
	v->ray.wall[2].tx = (int)(rx
			* (v->ray.wall[2].size / 64)) % (int)v->ray.wall[2].size;
	v->ray.wall[3].tx = (int)(rx
			* (v->ray.wall[3].size / 64)) % (int)v->ray.wall[3].size;
	if (ra > 180)
	{
		v->ray.wall[0].tx = (v->ray.wall[0].size - 1) - v->ray.wall[0].tx;
		v->ray.wall[1].tx = (v->ray.wall[1].size - 1) - v->ray.wall[1].tx;
		v->ray.wall[2].tx = (v->ray.wall[2].size - 1) - v->ray.wall[2].tx;
		v->ray.wall[3].tx = (v->ray.wall[3].size - 1) - v->ray.wall[3].tx;
		*dir = 1;
	}
	else
		*dir = 0;
}

void	set_initial_values(t_vars *v, float *ty_off)
{
	v->ray.wall[0].ty_step = v->ray.wall[0].size / (float)v->ray.line_h;
	v->ray.wall[1].ty_step = v->ray.wall[1].size / (float)v->ray.line_h;
	v->ray.wall[2].ty_step = v->ray.wall[2].size / (float)v->ray.line_h;
	v->ray.wall[3].ty_step = v->ray.wall[3].size / (float)v->ray.line_h;
	if (v->ray.line_h > v->height)
	{
		*ty_off = (v->ray.line_h - v->height) / 2.0;
		v->ray.line_h = v->height;
	}
	v->ray.line_off = v->height2 - (v->ray.line_h >> 1);
	v->ray.wall[0].ty = *ty_off * v->ray.wall[0].ty_step;
	v->ray.wall[1].ty = *ty_off * v->ray.wall[1].ty_step;
	v->ray.wall[2].ty = *ty_off * v->ray.wall[2].ty_step;
	v->ray.wall[3].ty = *ty_off * v->ray.wall[3].ty_step;
}

void	draw_textures(t_vars *v, float rx, float ry, float ra)
{
	int		dir;
	float	ty_off;

	ty_off = 0;
	set_initial_values(v, &ty_off);
	if (v->ray.shade == 1)
		set_north_and_south(v, &dir, rx, ra);
	else
		set_west_and_east(v, &dir, ry, ra);
	draw_pixels(v, dir);
}
