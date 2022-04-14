/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:34:32 by mkhabou           #+#    #+#             */
/*   Updated: 2022/03/07 12:34:33 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	check_line(char *line, t_vars *vars, int *x, int *y)
{
	int	i;
	int	len;

	i = 0;
	if (line && !ft_check_chars(line, " 1"))
		ft_error(vars, WALL_1, 0);
	if (line)
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (x)
			*x = i;
		len = ft_strlen(line) - 1;
		while (line[len] && line[len] == ' ')
			len--;
		if (y)
			*y = len;
	}
}

void	check_walls(t_vars *vars)
{
	int	i;
	int	x;
	int	y;
	int	len;

	i = 1;
	check_line(vars->map[0], vars, &x, &y);
	while (vars->map[i])
	{
		len = ft_strlen(vars->map[i]) - 1;
		if (len == -1 && vars->map[i + 1] && *vars->map[i + 1])
			ft_error(vars, EMPT_L, 0);
		else if (len == -1)
			break ;
		check_first(vars, i, &x);
		check_last(vars, i, len, &y);
		i++;
	}
	check_line(vars->map[i - 1], vars, NULL, NULL);
}
