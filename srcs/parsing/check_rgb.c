/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:00:50 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/24 19:00:54 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	print_error(char *msg, int ret)
{
	if (msg)
		ft_putendl_fd(msg, STDERR_FILENO);
	return (ret);
}

int	check_rgb_ceiling(t_vars *vars, char **rgb)
{
	int	i;

	i = 0;
	vars->ceiling = malloc(sizeof(int) * 3);
	if (!vars->ceiling)
		return (print_error(MALL_F, 0));
	while (i < 3)
	{
		vars->ceiling[i] = ft_atoi(rgb[i]);
		if (vars->ceiling[i] < 0 || vars->ceiling[i] > 255)
		{
			free(vars->ceiling);
			vars->ceiling = NULL;
			return (print_error(RAN_C, 0));
		}
		i++;
	}
	ft_free_tab(rgb);
	return (1);
}

int	check_rgb_floor(t_vars *vars, char **rgb)
{
	int	i;

	i = 0;
	vars->floor = malloc(sizeof(int) * 3);
	if (!vars->floor)
		return (print_error(MALL_F, 0));
	while (i < 3)
	{
		vars->floor[i] = ft_atoi(rgb[i]);
		if (vars->floor[i] < 0 || vars->floor[i] > 255)
		{
			free(vars->floor);
			vars->floor = NULL;
			return (print_error(RAN_F, 0));
		}
		i++;
	}
	ft_free_tab(rgb);
	return (1);
}

int	check_rgb(char type, t_vars *vars, char **rgb)
{
	if (!rgb)
		return (print_error(MALL_F, 0));
	if (ft_tab_len(rgb) != 3 && type == 'f')
		return (print_error(COL_F, 0));
	if (ft_tab_len(rgb) != 3 && type == 'c')
		return (print_error(COL_C, 0));
	if (type == 'f')
		return (check_rgb_floor(vars, rgb));
	else
		return (check_rgb_ceiling(vars, rgb));
}
