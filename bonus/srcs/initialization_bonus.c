/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:35:26 by mkhabou           #+#    #+#             */
/*   Updated: 2022/04/11 13:35:28 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	save_wid(t_vars *vars)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	vars->wid_min = malloc(sizeof(int) * vars->map_x);
	ft_memset(vars->wid_min, 0, sizeof(vars->wid_min));
	vars->wid_max = malloc(sizeof(int) * vars->map_x);
	if (!vars->wid_min || !vars->wid_max)
		ft_error(vars, MALL_F, 1);
	while (vars->map[vars->pos_max][j])
	{
		i = 0;
		k = vars->map_y1;
		while (!vars->map[i][j])
			i++;
		vars->wid_min[j] = i;
		while (!vars->map[k][j])
			k--;
		vars->wid_max[j] = k;
		j++;
	}
}

void	save_len(t_vars *vars)
{
	int	i;

	i = 0;
	vars->len = malloc(sizeof(int) * (vars->map_y));
	if (!vars->len)
		ft_error(vars, MALL_F, 1);
	while (i < vars->map_y)
	{
		vars->len[i] = ft_strlen(vars->map[i]) - 1;
		i++;
	}
}

void	init_vars2(t_vars *vars)
{
	vars->len = NULL;
	vars->wid_min = NULL;
	vars->wid_max = NULL;
	vars->keys.a = 0;
	vars->keys.d = 0;
	vars->keys.w = 0;
	vars->keys.s = 0;
	vars->keys.left = 0;
	vars->keys.right = 0;
	vars->n.img = NULL;
	vars->s.img = NULL;
	vars->e.img = NULL;
	vars->w.img = NULL;
}

void	init_vars(t_vars *vars)
{
	ft_memset(vars, 0, sizeof(t_vars));
	vars->height = W_HEIGHT;
	vars->height2 = vars->height / 2;
	vars->width = W_WIDTH;
	vars->rays = vars->width;
	vars->view = 64.0 / vars->rays;
	if (!((int)vars->view % 2))
		vars->view = 64.0 / (vars->rays + 1);
	vars->mlx = NULL;
	vars->win = NULL;
	vars->img = NULL;
	vars->north = NULL;
	vars->south = NULL;
	vars->east = NULL;
	vars->west = NULL;
	vars->floor = NULL;
	vars->ceiling = NULL;
	vars->map = NULL;
	vars->map_x = 0;
	vars->map_y = 0;
	vars->map_y1 = 0;
	init_vars2(vars);
}

void	initialization(t_vars *vars, int argc, char *argv[])
{
	init_vars(vars);
	parsing(vars, argc, argv);
	vars->c_ceiling = get_rgb(vars->ceiling[0],
			vars->ceiling[1], vars->ceiling[2]);
	vars->c_floor = get_rgb(vars->floor[0], vars->floor[1], vars->floor[2]);
	position_player(vars);
	save_len(vars);
	save_wid(vars);
}
