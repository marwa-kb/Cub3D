/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:31:27 by mkhabou           #+#    #+#             */
/*   Updated: 2022/04/02 15:31:29 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_values(t_vars *vars, int i, int j)
{
	vars->px = j * 64 + 32;
	vars->py = i * 64 + 32;
	if (vars->map[i][j] == 'N')
		vars->pa = 90;
	else if (vars->map[i][j] == 'S')
		vars->pa = 270;
	else if (vars->map[i][j] == 'E')
		vars->pa = 0;
	else if (vars->map[i][j] == 'W')
		vars->pa = 180;
	vars->pdx = cos(deg_to_rad(vars->pa));
	vars->pdy = -sin(deg_to_rad(vars->pa));
	return ;
}

void	position_player(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'N' || vars->map[i][j] == 'S'
				|| vars->map[i][j] == 'W' || vars->map[i][j] == 'E')
			{
				set_values(vars, i, j);
				return ;
			}
			j++;
		}
		i++;
	}
}
