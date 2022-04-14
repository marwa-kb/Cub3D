/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:00:50 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/24 19:00:54 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	find_max(t_vars *vars)
{
	int	x;
	int	y;
	int	max_x;

	y = 0;
	max_x = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (max_x < x)
			{
				max_x = x;
				vars->pos_max = y;
			}
			x++;
		}
		y++;
	}
	vars->map_x = max_x + 1;
	vars->map_y = y;
	vars->map_y1 = y - 1;
}

void	replace_map_spaces(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == ' ')
				vars->map[i][j] = '1';
			j++;
		}
		i++;
	}
}

void	dup_map(char **file_map, char **file_content, t_vars *vars)
{
	int	i;

	i = 0;
	vars->map = malloc(sizeof(char *) * (ft_tab_len(file_map) + 1));
	if (!vars->map)
	{
		ft_free_tab(file_content);
		ft_error(vars, MALL_F, 1);
	}
	ft_memset((void *)vars->map, 0, sizeof(vars->map));
	while (file_map[i])
	{
		vars->map[i] = ft_strdup(file_map[i]);
		if (!vars->map[i])
		{
			ft_free_tab(file_content);
			ft_error(vars, MALL_F, 1);
		}
		i++;
	}
	vars->map[i] = NULL;
}

void	get_map(char **file_map, char **file_content, t_vars *vars)
{
	int	pos;

	if (!vars->north || !vars->south || !vars->east || !vars->west
		|| !vars->floor || !vars->ceiling)
	{
		ft_free_tab(file_content);
		ft_putstr_fd(INV_F3, STDERR_FILENO);
		ft_error(vars, " or map is not at the end of the file", 0);
	}
	dup_map(file_map, file_content, vars);
	ft_free_tab(file_content);
	check_walls(vars);
	check_map(vars, &pos);
	if (!pos)
		ft_error(vars, INV_PO, 0);
	replace_map_spaces(vars);
	find_max(vars);
	create_limit(vars);
}
