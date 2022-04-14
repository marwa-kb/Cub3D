/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_limit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:50:41 by mkhabou           #+#    #+#             */
/*   Updated: 2022/04/12 17:50:43 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_strfill(char c, int size)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)malloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	while (i < size)
	{
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return (s);
}

void	change_str(char *dst, char *src)
{
	int	i;

	if (!src || !dst)
		return ;
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
}

void	create_limit(t_vars *vars)
{
	int		i;
	char	**new;

	new = malloc(sizeof(char *) * (vars->map_y + 2));
	if (!new)
		ft_error(vars, MALL_F, 1);
	ft_memset(new, 0, sizeof(new));
	i = 0;
	while (i < vars->map_y + 1)
	{
		new[i] = ft_strfill('\0', vars->map_x + 1);
		if (!new[i])
			ft_error(vars, MALL_F, 1);
		i++;
	}
	new[i] = NULL;
	i = 0;
	while (vars->map[i])
	{
		change_str(new[i], vars->map[i]);
		i++;
	}
	ft_free_tab(vars->map);
	vars->map = new;
}
