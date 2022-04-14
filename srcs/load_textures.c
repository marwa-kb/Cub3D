/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:34:49 by mkhabou           #+#    #+#             */
/*   Updated: 2022/04/06 16:34:50 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_texture_size(t_vars *v)
{
	if (v->n.w > 1000 || v->n.h > 1000 || v->e.w > 1000 || v->e.h > 1000
		|| v->s.w > 1000 || v->s.h > 1000 || v->w.w > 1000 || v->w.h > 1000)
		ft_error(v, "Error\nTexture size too big", 0);
	v->ray.wall[0].size = v->n.w;
	v->ray.wall[1].size = v->s.w;
	v->ray.wall[2].size = v->w.w;
	v->ray.wall[3].size = v->e.w;
}

void	load_textures(t_vars *v)
{
	v->n.img = mlx_xpm_file_to_image(v->mlx, v->north, &v->n.w, &v->n.h);
	if (!v->n.img)
		ft_error(v, OPEN_N, 1);
	v->n.addr = mlx_get_data_addr(v->n.img, &v->n.bpp, &v->n.line_l, &v->n.end);
	v->s.img = mlx_xpm_file_to_image(v->mlx, v->south, &v->s.w, &v->s.h);
	if (!v->s.img)
		ft_error(v, OPEN_S, 1);
	v->s.addr = mlx_get_data_addr(v->s.img, &v->s.bpp, &v->s.line_l, &v->s.end);
	v->e.img = mlx_xpm_file_to_image(v->mlx, v->east, &v->e.w, &v->e.h);
	if (!v->e.img)
		ft_error(v, OPEN_E, 1);
	v->e.addr = mlx_get_data_addr(v->e.img, &v->e.bpp, &v->e.line_l, &v->e.end);
	v->w.img = mlx_xpm_file_to_image(v->mlx, v->west, &v->w.w, &v->w.h);
	if (!v->w.img)
		ft_error(v, OPEN_W, 1);
	v->w.addr = mlx_get_data_addr(v->w.img, &v->w.bpp, &v->w.line_l, &v->w.end);
	check_texture_size(v);
}
