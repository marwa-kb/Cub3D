/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:23:41 by bbaatar           #+#    #+#             */
/*   Updated: 2022/04/11 22:25:03 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"
#include "keyboard_bonus.h"

int	key_press(int keycode, t_vars *v)
{
	if (keycode == ESC)
		end_game(v, "Game over!");
	if (keycode == LEFT)
		v->keys.a = 1;
	if (keycode == RIGHT)
		v->keys.d = 1;
	if (keycode == FORWARD)
		v->keys.w = 1;
	if (keycode == BACKFORD)
		v->keys.s = 1;
	if (keycode == LEFT_ARROW)
		v->keys.left = 1;
	if (keycode == RIGHT_ARROW)
		v->keys.right = 1;
	return (0);
}

int	key_release(int keycode, t_vars *v)
{
	if (keycode == LEFT)
		v->keys.a = 0;
	if (keycode == RIGHT)
		v->keys.d = 0;
	if (keycode == FORWARD)
		v->keys.w = 0;
	if (keycode == BACKFORD)
		v->keys.s = 0;
	if (keycode == LEFT_ARROW)
		v->keys.left = 0;
	if (keycode == RIGHT_ARROW)
		v->keys.right = 0;
	return (0);
}
