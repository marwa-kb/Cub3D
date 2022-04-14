/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:05:21 by mkhabou           #+#    #+#             */
/*   Updated: 2022/04/12 20:09:13 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_vars *v, int x, int y, int color)
{
	char	*dst;

	dst = v->addr + (y * v->line_length + x * (v->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put2(t_vars *v, int x, int y, int color)
{
	char	*dst;
	int		i;

	i = 0;
	while (i < 1)
	{
		dst = v->addr
			+ (y * v->line_length + (x + i) * (v->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
		i++;
	}
}

int	get_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}
