/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_lefts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:42:44 by mkhabou           #+#    #+#             */
/*   Updated: 2022/04/11 23:54:19 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/cub3d.h"

void	move_l_090(float a2, float b2, t_vars *v)
{
	if (check_limit(v, v->check.ipy, a2))
		v->px -= fix(v->pdx) * 6;
	if (check_limit(v, b2, v->check.ipx))
		v->py -= fix(v->pdy) * 6;
}

void	move_l_90180(float a2, float b1, t_vars *v)
{
	if (check_limit(v, v->check.ipy, a2))
		v->px -= fix(v->pdx) * 6;
	if (check_limit(v, b1, v->check.ipx))
		v->py += fix(v->pdy) * 6;
}

void	move_l_18027(float a1, float b1, t_vars *v)
{
	if (check_limit(v, v->check.ipy, a1))
		v->px += fix(v->pdx) * 6;
	if (check_limit(v, b1, v->check.ipx))
		v->py += fix(v->pdy) * 6;
}

void	move_l_27036(float a1, float b2, t_vars *v)
{
	if (check_limit(v, v->check.ipy, a1))
		v->px += fix(v->pdx) * 6;
	if (check_limit(v, b2, v->check.ipx))
		v->py -= fix(v->pdy) * 6;
}
