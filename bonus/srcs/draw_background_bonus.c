/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:37:02 by mkhabou           #+#    #+#             */
/*   Updated: 2022/03/10 11:37:03 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	draw_rectangle(t_vars *vars, t_rect *rect)
{
	int	i;
	int	j;

	i = rect->posy;
	while (i >= 0 && i < rect->posy + rect->height && i < vars->height)
	{
		j = rect->posx;
		while (j >= 0 && j < rect->posx + rect->width && j < vars->width)
		{
			my_mlx_pixel_put(vars, j, i, rect->color);
			j++;
		}
		i++;
	}
}

void	draw_background(t_vars *vars)
{
	t_rect	floor;
	t_rect	ceiling;

	ceiling.posx = 0;
	ceiling.posy = 0;
	ceiling.width = vars->width;
	ceiling.height = vars->height / 2;
	ceiling.color = get_rgb(vars->ceiling[0],
			vars->ceiling[1], vars->ceiling[2]);
	floor.posx = 0;
	floor.posy = vars->height / 2;
	floor.width = vars->width;
	floor.height = vars->height;
	floor.color = get_rgb(vars->floor[0], vars->floor[1], vars->floor[2]);
	draw_rectangle(vars, &ceiling);
	draw_rectangle(vars, &floor);
}
