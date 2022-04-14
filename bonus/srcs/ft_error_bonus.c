/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:22:26 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/24 19:22:27 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	free_vars(t_vars *vars)
{
	free(vars->north);
	free(vars->south);
	free(vars->west);
	free(vars->east);
	free(vars->floor);
	free(vars->ceiling);
	free(vars->len);
	free(vars->wid_min);
	free(vars->wid_max);
	ft_free_tab(vars->map);
}

void	clean_vars(t_vars *vars)
{
	free_vars(vars);
	if (vars->mlx)
	{
		if (vars->n.img)
			mlx_destroy_image(vars->mlx, vars->n.img);
		if (vars->s.img)
			mlx_destroy_image(vars->mlx, vars->s.img);
		if (vars->e.img)
			mlx_destroy_image(vars->mlx, vars->e.img);
		if (vars->w.img)
			mlx_destroy_image(vars->mlx, vars->w.img);
		if (vars->img)
			mlx_destroy_image(vars->mlx, vars->img);
		if (vars->win)
			mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
}

void	ft_error(t_vars *vars, char *msg, int perr)
{
	if (vars)
		clean_vars(vars);
	if (msg)
	{
		if (perr)
			perror(msg);
		else
			ft_putendl_fd(msg, STDERR_FILENO);
	}
	exit(1);
}
