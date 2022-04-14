/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_verti_horiz.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:01:45 by bbaatar           #+#    #+#             */
/*   Updated: 2022/04/12 20:01:48 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_vertical(t_vars *v)
{
	v->ray.dof = 0;
	v->ray.dis_v = 100000;
	v->ray.tang = tan(deg_to_rad(v->ray.ra));
	if (cos(deg_to_rad(v->ray.ra)) > 0.001)
	{
		v->ray.rx = (((int)v->px >> 6) << 6) + 64;
		v->ray.ry = (v->px - v->ray.rx) * v->ray.tang + v->py;
		v->ray.xo = 64;
		v->ray.yo = (-1) * v->ray.xo * v->ray.tang;
	}
	else if (cos(deg_to_rad(v->ray.ra)) < -0.001)
	{
		v->ray.rx = (((int)v->px >> 6) << 6) - 0.001;
		v->ray.ry = (v->px - v->ray.rx) * v->ray.tang + v->py;
		v->ray.xo = -64;
		v->ray.yo = (-1) * v->ray.xo * v->ray.tang;
	}
	else
	{
		v->ray.rx = v->px;
		v->ray.ry = v->py;
		v->ray.dof = DOF;
	}
}

void	check_next_horiz_v(t_vars *v)
{
	while (v->ray.dof < DOF)
	{
		v->ray.mx = (int)(v->ray.rx) >> 6;
		v->ray.my = (int)(v->ray.ry) >> 6;
		if (0 <= v->ray.mx && v->ray.mx < v->map_x && 0 <= v->ray.my
			&& v->ray.my < v->map_y && v->map[v->ray.my][v->ray.mx] == 49)
		{
			v->ray.vmt = v->map[v->ray.my][v->ray.mx] - 49;
			v->ray.dof = DOF;
			v->ray.dis_v = cos(deg_to_rad(v->ray.ra)) * (v->ray.rx - v->px)
				- sin(deg_to_rad(v->ray.ra)) * (v->ray.ry - v->py);
		}
		else
		{
			v->ray.rx += v->ray.xo;
			v->ray.ry += v->ray.yo;
			v->ray.dof += 1;
		}
	}
}

void	check_horiz(t_vars *v)
{
	v->ray.dof = 0;
	v->ray.dis_h = 100000;
	v->ray.tang = 1.0 / v->ray.tang;
	if (sin(deg_to_rad(v->ray.ra)) > 0.001)
	{
		v->ray.ry = (((int)v->py >> 6) << 6) - 0.001;
		v->ray.rx = (v->py - v->ray.ry) * v->ray.tang + v->px;
		v->ray.yo = -64;
		v->ray.xo = (-1) * v->ray.yo * v->ray.tang;
	}
	else if (sin(deg_to_rad(v->ray.ra)) < -0.001)
	{
		v->ray.ry = (((int)v->py >> 6) << 6) + 64;
		v->ray.rx = (v->py - v->ray.ry) * v->ray.tang + v->px;
		v->ray.yo = 64;
		v->ray.xo = (-1) * v->ray.yo * v->ray.tang;
	}
	else
	{
		v->ray.rx = v->px;
		v->ray.ry = v->py;
		v->ray.dof = DOF;
	}
}

void	check_next_horiz_h(t_vars *v)
{
	while (v->ray.dof < DOF)
	{
		v->ray.mx = (int)(v->ray.rx) >> 6;
		v->ray.my = (int)(v->ray.ry) >> 6;
		if (0 <= v->ray.mx && v->ray.mx < v->map_x
			&& 0 <= v->ray.my && v->ray.my < v->map_y
			&& v->map[v->ray.my][v->ray.mx] == 49)
		{
			v->ray.hmt = v->map[v->ray.my][v->ray.mx] - 49;
			v->ray.dof = DOF;
			v->ray.dis_h = cos(deg_to_rad(v->ray.ra)) * (v->ray.rx - v->px)
				- sin(deg_to_rad(v->ray.ra)) * (v->ray.ry - v->py);
		}
		else
		{
			v->ray.rx += v->ray.xo;
			v->ray.ry += v->ray.yo;
			v->ray.dof += 1;
		}
	}
}
