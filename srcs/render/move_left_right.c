/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:42:44 by mkhabou           #+#    #+#             */
/*   Updated: 2022/04/11 23:53:49 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/cub3d.h"

void	move_right(t_vars *v)
{
	float	a1;
	float	a2;
	float	b1;
	float	b2;

	a1 = find_a1(v->pdx, v);
	a2 = find_a2(v->pdx, v);
	b1 = find_b1(v->pdy, v);
	b2 = find_b2(v->pdy, v);
	if (!v->pa && check_limit(v, b1, v->check.ipx))
		v->py += 6;
	else if (v->pa == 180 && check_limit(v, b2, v->check.ipx))
		v->py -= 6;
	else if (v->pa == 90 && check_limit(v, v->check.ipy, a1))
		v->px += 6;
	else if (v->pa == 270 && check_limit(v, v->check.ipy, a2))
		v->px -= 6;
	else if (v->pa > 0 && v->pa < 90)
		move_r_090(a1, b1, v);
	else if (v->pa > 90 && v->pa < 180)
		move_r_90180(a1, b2, v);
	else if (v->pa > 180 && v->pa < 270)
		move_r_18027(a2, b2, v);
	else if (v->pa > 270 && v->pa < 360)
		move_r_27036(a2, b1, v);
}

void	move_left(t_vars *v)
{
	float	a1;
	float	a2;
	float	b1;
	float	b2;

	a1 = find_a1(v->pdx, v);
	a2 = find_a2(v->pdx, v);
	b1 = find_b1(v->pdy, v);
	b2 = find_b2(v->pdy, v);
	if (!v->pa && check_limit(v, b2, v->check.ipx))
		v->py -= 6;
	else if (v->pa == 180 && check_limit(v, b1, v->check.ipx))
		v->py += 6;
	else if (v->pa == 90 && check_limit(v, v->check.ipy, a2))
		v->px -= 6;
	else if (v->pa == 270 && check_limit(v, v->check.ipy, a1))
		v->px += 6;
	else if (v->pa > 0 && v->pa < 90)
		move_l_090(a2, b2, v);
	else if (v->pa > 90 && v->pa < 180)
		move_l_90180(a2, b1, v);
	else if (v->pa > 180 && v->pa < 270)
		move_l_18027(a1, b1, v);
	else if (v->pa > 270 && v->pa < 360)
		move_l_27036(a1, b2, v);
}
