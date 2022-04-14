/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:00:50 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/24 19:00:54 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_opening(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(filename);
		ft_error(NULL, INV_F1, 1);
	}
	return (fd);
}

void	check_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
	{
		free(filename);
		ft_error(NULL, INV_F2, 0);
	}
	if (ft_strncmp(&filename[len - 4], ".cub\0", 5))
	{
		free(filename);
		ft_error(NULL, INV_F2, 0);
	}
}

void	parsing(t_vars *vars, int argc, char *argv[])
{
	int		fd_file;
	char	*filename;
	char	**file_content;

	filename = NULL;
	if (argc != 2)
		ft_error(NULL, NB_ARG, 0);
	filename = ft_strtrim(argv[1], " ");
	check_extension(filename);
	fd_file = check_opening(filename);
	file_content = get_content(fd_file, filename);
	free(filename);
	check_content(file_content, vars);
}
