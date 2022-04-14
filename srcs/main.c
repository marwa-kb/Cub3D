/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:10:39 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/18 20:10:41 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char *argv[])
{
	t_vars	vars;

	initialization(&vars, argc, argv);
	vars.mlx = mlx_init();
	if (!vars.mlx)
		ft_error(&vars, MLX_IN, 1);
	load_textures(&vars);
	vars.win = mlx_new_window(vars.mlx,
			vars.width, vars.height, "Welcome to Cub3D!");
	if (!vars.win)
		ft_error(&vars, MLX_WI, 1);
	vars.img = mlx_new_image(vars.mlx, vars.width, vars.height);
	if (!vars.img)
		ft_error(&vars, MLX_IM, 1);
	vars.addr = mlx_get_data_addr(vars.img,
			&vars.bits_per_pixel, &vars.line_length, &vars.endian);
	mlx_hook(vars.win, 2, (1L << 0), &key_press, &vars);
	mlx_hook(vars.win, 3, (1L << 1), &key_release, &vars);
	mlx_hook(vars.win, 17, (1L << 5), &mouse_hook, &vars);
	mlx_loop_hook(vars.mlx, render_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
