/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:39:04 by mkhabou           #+#    #+#             */
/*   Updated: 2022/04/11 19:39:05 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	set_east(t_vars *v, float tx, float ty, float size)
{
	int	pixel;

	pixel = ((int)ty * (int)size + (int)tx) * 4;
	v->ray.red = (unsigned int)v->e.addr[pixel + 2];
	v->ray.green = (unsigned int)v->e.addr[pixel + 1];
	v->ray.blue = (unsigned int)v->e.addr[pixel + 0];
}

void	set_west(t_vars *v, float tx, float ty, float size)
{
	int	pixel;

	pixel = ((int)ty * (int)size + (int)tx) * 4;
	v->ray.red = (unsigned int)v->w.addr[pixel + 2];
	v->ray.green = (unsigned int)v->w.addr[pixel + 1];
	v->ray.blue = (unsigned int)v->w.addr[pixel + 0];
}

void	set_south(t_vars *v, float tx, float ty, float size)
{
	int	pixel;

	pixel = ((int)ty * (int)size + (int)tx) * 4;
	v->ray.red = (unsigned int)v->s.addr[pixel + 2];
	v->ray.green = (unsigned int)v->s.addr[pixel + 1];
	v->ray.blue = (unsigned int)v->s.addr[pixel + 0];
}

void	set_north(t_vars *v, float tx, float ty, float size)
{
	int	pixel;

	pixel = ((int)ty * (int)size + (int)tx) * 4;
	v->ray.red = (unsigned int)v->n.addr[pixel + 2];
	v->ray.green = (unsigned int)v->n.addr[pixel + 1];
	v->ray.blue = (unsigned int)v->n.addr[pixel + 0];
}
