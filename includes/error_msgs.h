/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msgs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 22:18:50 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/25 22:18:51 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSGS_H
# define ERROR_MSGS_H

# define MALL_F "Error\nMalloc failure"
# define NB_ARG "Error\nInvalid number of arguments\nUsage: \"./cub3d *.cub\""
# define INV_F1 "Error\nInvalid file"
# define INV_F2 "Error\nInvalid file: Must be a \".cub\" file"
# define INV_F3 "Error\nInvalid file: Missing information"
# define INV_F4 "Error\nInvalid file: Unknown or additional information in file"
# define INV_NO	"Error\nInvalid file: North texture is specified more than once"
# define INV_SO	"Error\nInvalid file: South texture is specified more than once"
# define INV_EA	"Error\nInvalid file: East texture is specified more than once"
# define INV_WE "Error\nInvalid file: West texture is specified more than once"
# define INV_FC	"Error\nInvalid file: Floor color is specified more than once"
# define INV_CC	"Error\nInvalid file: Ceiling color is specified more than once"
# define NO_NO	"Error\nInvalid north texture: No path specified"
# define NO_SO	"Error\nInvalid south texture: No path specified"
# define NO_EA	"Error\nInvalid east texture: No path specified"
# define NO_WE	"Error\nInvalid west texture: No path specified"
# define COL_F	"Error\nInvalid floor color: Wrong format"
# define COL_C	"Error\nInvalid ceiling color: Wrong format"
# define RAN_F	"Error\nInvalid floor color: Invalid value or out of range"
# define RAN_C	"Error\nInvalid ceiling color: Invalid value or out of range"
# define WALL_1	"Error\nInvalid map: Must be surrounded by walls"
# define EMPT_L	"Error\nInvalid map: Empty line found in the map"
# define INV_CH	"Error\nInvalid map: Invalid character"
# define POS_CH	"Error\nInvalid map: Player must have only one starting position"
# define INV_PO	"Error\nInvalid map: Player's starting position not found"
# define INV_SP	"Error\nInvalid map: Invalid space"
# define OPEN_N	"Error\nInvalid north texture file"
# define OPEN_S	"Error\nInvalid south texture file"
# define OPEN_E	"Error\nInvalid east texture file"
# define OPEN_W	"Error\nInvalid west texture file"
# define MLX_IN "Error\nMlx_init failure"
# define MLX_WI "Error\nMlx_new_window failure"
# define MLX_IM "Error\nMlx_new_image failure"

#endif
