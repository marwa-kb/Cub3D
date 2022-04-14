/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_continuity.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 11:30:56 by mkhabou           #+#    #+#             */
/*   Updated: 2022/03/08 11:30:57 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	check_end(char *line1, char *line2, int y1, int y2)
{
	int	i;

	i = 0;
	if (y1 < y2)
	{
		i = y2 - 1;
		while (i && i >= y1)
		{
			if (line2[i] != '1' && line2[i] != ' ')
				return (0);
			i--;
		}
	}
	else
	{
		i = y1 - 1;
		while (i && i >= y2)
		{
			if (line1[i] != '1' && line1[i] != ' ')
				return (0);
			i--;
		}
	}
	return (1);
}

int	check_start(char *line1, char *line2, int x1, int x2)
{
	int	i;

	i = 0;
	if (x1 < x2)
	{
		i = x1 + 1;
		while (line1[i] && i <= x2)
		{
			if (line1[i] != '1' && line1[i] != ' ')
				return (0);
			i++;
		}
	}
	else
	{
		i = x2 + 1;
		while (line2[i] && i <= x1)
		{
			if (line2[i] != '1' && line2[i] != ' ')
				return (0);
			i++;
		}
	}
	return (1);
}

void	check_last(t_vars *vars, int i, int len, int *y)
{
	while (vars->map[i][len] && vars->map[i][len] == ' ')
		len--;
	if (vars->map[i][len] != '1')
		ft_error(vars, WALL_1, 0);
	else if (*y != len && !check_end(vars->map[i - 1], vars->map[i], *y, len))
		ft_error(vars, WALL_1, 0);
	*y = len;
}

void	check_first(t_vars *vars, int i, int *x)
{
	int	j;

	j = 0;
	while (vars->map[i][j] && vars->map[i][j] == ' ')
		j++;
	if (vars->map[i][j] != '1')
		ft_error(vars, WALL_1, 0);
	else if (*x != j && !check_start(vars->map[i - 1], vars->map[i], *x, j))
		ft_error(vars, WALL_1, 0);
	*x = j;
}
