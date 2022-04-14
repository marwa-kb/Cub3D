/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:21:26 by mkhabou           #+#    #+#             */
/*   Updated: 2022/04/11 13:21:29 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>
# include <stdint.h>
# include <time.h>
# include <errno.h>
# include <sys/time.h>
# include "../libft/libft.h"
# include "error_msgs_bonus.h"

# define BUFFER_SIZE 100
# define W_WIDTH 1920
# define W_HEIGHT 1080
# define MAP_S 64 // map cube size
# define DOF 1000

typedef struct s_check
{
	float	ipx;
	float	ipxa;
	float	ipxs;
	float	ipy;
	float	ipya;
	float	ipys;
}			t_check;

typedef struct s_coord
{
	int	x;
	int	y;
	int	color;
}		t_coord;

typedef struct s_wall
{
	float	size;
	float	tx;
	float	ty;
	float	ty_step;
}			t_wall;

typedef struct s_ray
{
	int		r;
	int		mx;
	int		my;
	int		mp;
	int		dof;
	int		side;
	float	vx;
	float	vy;
	float	rx;
	float	ry;
	float	ra;
	float	xo;
	float	yo;
	float	dis_v;
	float	dis_h;
	int		vmt;
	int		hmt;
	float	tang;
	float	shade;
	float	ca;
	int		line_h;
	int		line_off;
	t_wall	wall[4];
}			t_ray;

typedef struct s_keys
{
	int	w;
	int	a;
	int	d;
	int	s;
	int	left;
	int	right;
}		t_keys;

typedef struct s_img
{
	void	*img;
	int		w;
	int		h;
	char	*addr;
	int		bpp;
	int		line_l;
	int		end;
}			t_img;

typedef struct s_vars
{
	int		height;
	int		height2;
	int		width;
	float	rays;
	float	view;
	void	*mlx;
	void	*win;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		*floor;
	int		c_floor;
	int		*ceiling;
	int		c_ceiling;
	char	**map;
	int		map_x;
	int		pos_max;
	int		map_y;
	int		map_y1;
	int		*len;
	int		*wid_min;
	int		*wid_max;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	float	px;
	float	py;
	float	pdx;
	float	pdy;
	float	pa;
	int		color;
	t_ray	ray;
	t_keys	keys;
	t_check	check;
	t_img	n;
	t_img	s;
	t_img	e;
	t_img	w;
}		t_vars;

typedef struct s_rect
{
	int	posx;
	int	posy;
	int	height;
	int	width;
	int	color;
}		t_rect;

// Parsing
int		ft_tab_len(char **tab);
int		ft_count_lines(int fd);
int		get_next_line(int fd, char **line);
void	parsing(t_vars *vars, int argc, char *argv[]);
char	**get_content(int fd_file, char *filename);
int		ft_check_chars(char *line, char *check);
void	check_content(char **file_content, t_vars *vars);
int		check_line_file(char *line, t_vars *vars);
int		check_rgb(char type, t_vars *vars, char **rgb);
void	get_map(char **file_map, char **file_content, t_vars *vars);
void	check_walls(t_vars *vars);
void	check_first(t_vars *vars, int i, int *x);
void	check_last(t_vars *vars, int i, int len, int *y);
void	check_map(t_vars *vars, int *pos);
void	create_limit(t_vars *vars);
// Executing
int		mouse_hook(t_vars *vars);
void	initialization(t_vars *vars, int argc, char *argv[]);
void	load_textures(t_vars *v);
void	position_player(t_vars *vars);
int		get_rgb(uint8_t red, uint8_t green, uint8_t blue);
void	draw_background(t_vars *vars);
void	my_mlx_pixel_put(t_vars *v, int x, int y, int color);
void	my_mlx_pixel_put2(t_vars *v, int x, int y, int color);
int		get_rgb(uint8_t red, uint8_t green, uint8_t blue);
// Cleaning
void	ft_free_tab(char **tab);
void	clean_vars(t_vars *vars);
void	end_game(t_vars *vars, char *msg);
void	ft_error(t_vars *vars, char *msg, int perr);
//Raycast
float	fix_ang(float a);
float	deg_to_rad(float a);
void	draw_ceiling(t_vars *v);
void	draw_rays(t_vars *v);
int		key_press(int keycode, t_vars *v);
int		key_release(int keycode, t_vars *v);
int		render_frame(t_vars *v);
void	update_checks(t_vars *v, int xo, int yo);
float	fix(float a);
int		check_limit(t_vars *v, float x, float y);
void	move_forward(t_vars *v);
void	move_backword(t_vars *v);
void	move_right(t_vars *v);
void	move_left(t_vars *v);
void	move_r_090(float a1, float b1, t_vars *v);
void	move_l_090(float a1, float b1, t_vars *v);
void	move_r_90180(float a1, float b2, t_vars *v);
void	move_l_90180(float a1, float b2, t_vars *v);
void	move_r_18027(float a2, float b2, t_vars *v);
void	move_l_18027(float a2, float b2, t_vars *v);
void	move_r_27036(float a2, float b1, t_vars *v);
void	move_l_27036(float a2, float b1, t_vars *v);
float	find_a1(float pdelta, t_vars *v);
float	find_a2(float pdelta, t_vars *v);
float	find_b1(float pdelta, t_vars *v);
float	find_b2(float pdelta, t_vars *v);
void	draw_textures(t_vars *v, float rx, float ry, float ra);
void	draw_pixels(t_vars *v, int dir);
void	check_vertical(t_vars *v);
void	check_next_horiz_v(t_vars *v);
void	check_horiz(t_vars *v);
void	check_next_horiz_h(t_vars *v);

#endif
