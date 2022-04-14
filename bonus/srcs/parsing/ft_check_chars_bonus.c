/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:34:32 by mkhabou           #+#    #+#             */
/*   Updated: 2022/03/07 12:34:33 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	ft_check_chars(char *line, char *check)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		j = 0;
		while (check[j])
		{
			if (line[i] == check[j])
				break ;
			j++;
		}
		if (!check[j])
			return (0);
		i++;
	}
	return (1);
}
