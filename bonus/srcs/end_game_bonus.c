/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:42:44 by mkhabou           #+#    #+#             */
/*   Updated: 2021/11/30 22:42:46 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	end_game(t_vars *vars, char *msg)
{
	printf("%s\n", msg);
	if (vars)
		clean_vars(vars);
	exit(0);
}
