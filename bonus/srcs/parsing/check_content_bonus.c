/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:00:50 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/24 19:00:54 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	check_content(char **file_content, t_vars *vars)
{
	int	i;
	int	ret;

	i = 0;
	while (file_content[i])
	{
		if (*file_content[i])
		{
			ret = check_line_file(file_content[i], vars);
			if (!ret)
			{
				ft_free_tab(file_content);
				ft_error(vars, NULL, 0);
			}
			else if (ret == 1)
			{
				get_map(&file_content[i], file_content, vars);
				break ;
			}
		}
		i++;
	}
	if (!vars->north || !vars->south || !vars->east || !vars->west
		|| !vars->floor || !vars->ceiling || !vars->map)
		ft_error(vars, INV_F3, 0);
}
