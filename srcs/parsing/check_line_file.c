/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:18:02 by mkhabou           #+#    #+#             */
/*   Updated: 2022/03/07 16:18:04 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	print_error(char *error_msg, char *element, char **rgb, int ret)
{
	free(element);
	ft_free_tab(rgb);
	if (error_msg)
		ft_putendl_fd(error_msg, STDERR_FILENO);
	return (ret);
}

int	search_3(char *element, char **rgb, t_vars *vars)
{
	if (!ft_strncmp(element, "F", 1))
	{
		if (vars->floor)
			return (print_error(INV_FC, element, rgb, 0));
		rgb = ft_split(&element[1], ',');
		if (!check_rgb('f', vars, rgb))
			return (print_error(NULL, element, rgb, 0));
	}
	else if (!ft_strncmp(element, "C", 1))
	{
		if (vars->ceiling)
			return (print_error(INV_CC, element, rgb, 0));
		rgb = ft_split(&element[1], ',');
		if (!check_rgb('c', vars, rgb))
			return (print_error(NULL, element, rgb, 0));
	}
	else if (ft_check_chars(element, "01NSEW "))
		return (print_error(NULL, element, rgb, 1));
	else
		return (-1);
	return (2);
}

int	search_2(char *element, char **rgb, t_vars *vars)
{
	if (!ft_strncmp(element, "EA", 2))
	{
		if (vars->east)
			return (print_error(INV_EA, element, rgb, 0));
		vars->east = ft_strtrim(&element[2], " ");
		if (!*vars->east)
			return (print_error(NO_EA, element, rgb, 0));
	}
	else if (!ft_strncmp(element, "WE", 2)
		&& !ft_check_chars(element, "01NSEW "))
	{
		if (vars->west)
			return (print_error(INV_WE, element, rgb, 0));
		vars->west = ft_strtrim(&element[2], " ");
		if (!*vars->west)
			return (print_error(NO_WE, element, rgb, 0));
	}
	else
		return (search_3(element, rgb, vars));
	return (2);
}

int	search_element(char *element, char **rgb, t_vars *vars)
{
	if (!ft_strncmp(element, "NO", 2))
	{
		if (vars->north)
			return (print_error(INV_NO, element, rgb, 0));
		vars->north = ft_strtrim(&element[2], " ");
		if (!*vars->north)
			return (print_error(NO_NO, element, rgb, 0));
	}
	else if (!ft_strncmp(element, "SO", 2))
	{
		if (vars->south)
			return (print_error(INV_SO, element, rgb, 0));
		vars->south = ft_strtrim(&element[2], " ");
		if (!*vars->south)
			return (print_error(NO_SO, element, rgb, 0));
	}
	else
		return (search_2(element, rgb, vars));
	return (2);
}

int	check_line_file(char *line, t_vars *vars)
{
	int		ret;
	char	*element;
	char	**rgb;

	rgb = NULL;
	element = ft_strtrim(line, " ");
	if (!*element)
		return (print_error(NULL, element, rgb, 2));
	ret = search_element(element, rgb, vars);
	if (!ret || ret == 1)
		return (ret);
	if (ret == -1)
		return (print_error(INV_F4, element, rgb, 0));
	free(element);
	ft_free_tab(rgb);
	return (2);
}
