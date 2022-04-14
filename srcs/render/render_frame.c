/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:26:33 by bbaatar           #+#    #+#             */
/*   Updated: 2022/04/11 23:04:55 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	x_offset(float pdx)
{
	int	xo;

	xo = 20;
	if (pdx < 0)
		xo = -20;
	return (xo);
}

int	y_offset(float pdy)
{
	int	yo;

	yo = 20;
	if (pdy < 0)
		yo = -20;
	return (yo);
}

void	look_left(t_vars *v)
{
	v->pa += 6;
	v->pa = fix_ang(v->pa);
	v->pdx = cos(deg_to_rad(v->pa));
	v->pdy = -sin(deg_to_rad(v->pa));
}

void	look_right(t_vars *v)
{
	v->pa -= 6;
	v->pa = fix_ang(v->pa);
	v->pdx = cos(deg_to_rad(v->pa));
	v->pdy = -sin(deg_to_rad(v->pa));
}

int	render_frame(t_vars *v)
{
	int	xo;
	int	yo;

	if (v->keys.left == 1)
		look_left(v);
	if (v->keys.right == 1)
		look_right(v);
	xo = x_offset(v->pdx);
	yo = x_offset(v->pdy);
	update_checks(v, xo, yo);
	if (v->keys.w == 1)
		move_forward(v);
	if (v->keys.s == 1)
		move_backword(v);
	if (v->keys.d == 1)
		move_right(v);
	if (v->keys.a == 1)
		move_left(v);
	draw_rays(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	return (0);
}
