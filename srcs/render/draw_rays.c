/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:00:43 by bbaatar           #+#    #+#             */
/*   Updated: 2022/04/12 20:00:44 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	horiz_hit_first(t_vars *v)
{
	if (v->ray.dis_v < v->ray.dis_h)
	{
		v->ray.hmt = v->ray.vmt;
		v->ray.shade = 0.5;
		v->ray.rx = v->ray.vx;
		v->ray.ry = v->ray.vy;
		return (v->ray.dis_v);
	}
	return (v->ray.dis_h);
}

void	put_pixels(t_vars *v)
{
	int	y;

	y = v->ray.line_off + v->ray.line_h;
	while (y < v->height)
	{
		my_mlx_pixel_put2(v, v->ray.r, y, v->c_floor);
		my_mlx_pixel_put2(v, v->ray.r, v->height - y, v->c_ceiling);
		y++;
	}
}

void	draw_rays(t_vars *v)
{
	float	ca;

	v->ray.ra = fix_ang(v->pa + 30);
	v->ray.r = 0;
	while (v->ray.r < v->rays)
	{
		v->ray.vmt = 0;
		v->ray.hmt = 0;
		check_vertical(v);
		check_next_horiz_v(v);
		v->ray.vx = v->ray.rx;
		v->ray.vy = v->ray.ry;
		check_horiz(v);
		check_next_horiz_h(v);
		v->ray.shade = 1;
		v->ray.dis_h = horiz_hit_first(v);
		ca = fix_ang(v->pa - v->ray.ra);
		v->ray.dis_h = v->ray.dis_h * cos(deg_to_rad(ca));
		v->ray.line_h = (MAP_S * v->height) / (v->ray.dis_h);
		draw_textures(v, v->ray.rx, v->ray.ry, v->ray.ra);
		put_pixels(v);
		v->ray.ra = fix_ang(v->ray.ra - v->view);
		v->ray.r++;
	}
}
