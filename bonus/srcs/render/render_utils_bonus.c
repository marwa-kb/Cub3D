/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:26:07 by bbaatar           #+#    #+#             */
/*   Updated: 2022/04/11 22:26:11 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

float	deg_to_rad(float a)
{
	return (a * M_PI / 180.0);
}

float	fix_ang(float a)
{
	if (a > 359)
		a -= 360;
	if (a < 0)
		a += 360;
	return (a);
}

void	update_checks(t_vars *v, int xo, int yo)
{
	v->check.ipx = v->px / 64.0;
	v->check.ipxa = (v->px + xo) / 64.0;
	v->check.ipxs = (v->px - xo) / 64.0;
	v->check.ipy = v->py / 64.0;
	v->check.ipya = (v->py + yo) / 64.0;
	v->check.ipys = (v->py - yo) / 64.0;
}

float	fix(float a)
{
	if (a < 1)
		return (a + 1);
	return (a);
}

int	check_limit(t_vars *v, float x, float y)
{
	if (x <= v->wid_min[(int)y] + 1 || x >= v->wid_max[(int)y]
		|| y <= 1 || y >= v->len[(int)x]
		|| !v->map[(int)x][(int)y]
		|| v->map[(int)x][(int)y] == '1')
		return (0);
	return (1);
}
