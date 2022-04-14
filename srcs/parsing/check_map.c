/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:34:19 by mkhabou           #+#    #+#             */
/*   Updated: 2022/03/07 12:34:22 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	surr(char c)
{
	if (c == ' ' || c == '1' || !c)
		return (1);
	return (0);
}

void	check_rest(int i, int j, t_vars *vars)
{
	if (!surr(vars->map[i][j - 1]) || !surr(vars->map[i][j + 1])
	|| ((int)ft_strlen(vars->map[i - 1]) > j && (!surr(vars->map[i - 1][j - 1])
	|| !surr(vars->map[i - 1][j]) || !surr(vars->map[i - 1][j + 1])))
	|| ((int)ft_strlen(vars->map[i + 1]) > j && (!surr(vars->map[i + 1][j - 1])
	|| !surr(vars->map[i + 1][j]) || !surr(vars->map[i + 1][j + 1]))))
		ft_error(vars, INV_SP, 0);
}

void	check_space(int i, int j, t_vars *vars)
{
	if (!i && !j)
	{
		if (((int)ft_strlen(vars->map[i + 1]) > j && (!surr(vars->map[i + 1][j])
				|| !surr(vars->map[i + 1][j + 1])))
				|| !surr(vars->map[i][j + 1]))
			ft_error(vars, INV_SP, 0);
	}
	else if (!i)
	{
		if (!surr(vars->map[i][j - 1]) || !surr(vars->map[i][j + 1])
		|| ((int)ft_strlen(vars->map[i + 1]) > j
		&& (!surr(vars->map[i + 1][j - 1]) || !surr(vars->map[i + 1][j])
		|| !surr(vars->map[i + 1][j + 1]))))
			ft_error(vars, INV_SP, 0);
	}
	else if (!j)
	{
		if (!surr(vars->map[i][j + 1]) || ((int)ft_strlen(vars->map[i - 1]) > j
		&& (!surr(vars->map[i - 1][j]) || !surr(vars->map[i - 1][j + 1])))
		|| ((int)ft_strlen(vars->map[i + 1]) > j && (!surr(vars->map[i + 1][j])
		|| !surr(vars->map[i + 1][j + 1]))))
			ft_error(vars, INV_SP, 0);
	}
	else
		check_rest(i, j, vars);
}

int	check_map_char(char c)
{
	int	ret;

	ret = 0;
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E'
		|| c == '0' || c == '1' || c == ' ')
	{	
		ret = 3;
		if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			ret = 1;
		else if (c == ' ')
			ret = 2;
	}
	return (ret);
}

void	check_map(t_vars *vars, int *pos)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	*pos = 0;
	ret = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			ret = check_map_char(vars->map[i][j]);
			if (!ret)
				ft_error(vars, INV_CH, 0);
			else if (ret == 1)
				*pos = *pos + 1;
			else if (ret == 2)
				check_space(i, j, vars);
			j++;
		}
		if (*pos > 1)
			ft_error(vars, POS_CH, 0);
		i++;
	}
}
