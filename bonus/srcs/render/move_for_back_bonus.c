/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:42:44 by mkhabou           #+#    #+#             */
/*   Updated: 2022/04/11 23:06:02 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/cub3d_bonus.h"

void	move_forward(t_vars *v)
{
	if (check_limit(v, v->check.ipy, v->check.ipxa))
		v->px += v->pdx * 12;
	if (check_limit(v, v->check.ipya, v->check.ipx))
		v->py += v->pdy * 12;
}

void	move_backword(t_vars *v)
{
	if (check_limit(v, v->check.ipy, v->check.ipxs))
		v->px -= v->pdx * 12;
	if (check_limit(v, v->check.ipys, v->check.ipx))
		v->py -= v->pdy * 12;
}
