/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:42:44 by mkhabou           #+#    #+#             */
/*   Updated: 2022/04/11 23:54:43 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/cub3d.h"

float	find_a1(float pdelta, t_vars *v)
{
	if (pdelta < 0)
		return (v->check.ipxs);
	return (v->check.ipxa);
}

float	find_a2(float pdelta, t_vars *v)
{
	if (pdelta < 0)
		return (v->check.ipxa);
	return (v->check.ipxs);
}

float	find_b1(float pdelta, t_vars *v)
{
	if (pdelta < 0)
		return (v->check.ipys);
	return (v->check.ipya);
}

float	find_b2(float pdelta, t_vars *v)
{
	if (pdelta < 0)
		return (v->check.ipya);
	return (v->check.ipys);
}
