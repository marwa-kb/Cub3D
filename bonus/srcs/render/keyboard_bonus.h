/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:23:41 by bbaatar           #+#    #+#             */
/*   Updated: 2022/04/12 00:23:36 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_BONUS_H
# define KEYBOARD_BONUS_H

# ifndef __APPLE__
#  define ESC 0xFF1B 
#  define LEFT 0x0061
#  define RIGHT 0x064
#  define FORWARD 0x077
#  define BACKFORD 0x073
#  define LEFT_ARROW 0xFF51 
#  define RIGHT_ARROW 0xFF53

# else

#  define ESC 53
#  define LEFT 0
#  define RIGHT 2
#  define FORWARD 13 
#  define BACKFORD 1
#  define LEFT_ARROW 123 
#  define RIGHT_ARROW 124

# endif

#endif
