/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:00:50 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/24 19:00:54 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	nb_lines(char *file)
{
	int	fd;
	int	count;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		free(file);
		ft_error(NULL, INV_F1, 1);
	}
	count = ft_count_lines(fd);
	close(fd);
	return (count);
}

char	**alloc_file(char *file)
{
	int		count;
	char	**file_content;

	count = nb_lines(file);
	if (count < 1)
	{
		free(file);
		if (!count)
			ft_error(NULL, INV_F3, 0);
		if (count == -1)
			ft_error(NULL, INV_F1, 0);
	}
	file_content = malloc(sizeof(char *) * (count + 2));
	if (!file_content)
	{
		free(file);
		ft_error(NULL, MALL_F, 1);
	}
	file_content[count + 1] = NULL;
	return (file_content);
}

void	check_gnl(int ret_gnl, int fd_file, char *filename, char **file_content)
{
	if (ret_gnl == -1)
	{
		close(fd_file);
		free(filename);
		ft_free_tab(file_content);
		ft_error(NULL, INV_F1, 1);
	}
}

char	**get_content(int fd_file, char *filename)
{
	int		i;
	int		ret_gnl;
	char	*line;
	char	**file_content;

	i = 0;
	line = NULL;
	file_content = alloc_file(filename);
	ret_gnl = get_next_line(fd_file, &line);
	check_gnl(ret_gnl, fd_file, filename, file_content);
	while (ret_gnl)
	{
		file_content[i++] = ft_strdup(line);
		free(line);
		line = NULL;
		ret_gnl = get_next_line(fd_file, &line);
	}
	file_content[i] = ft_strdup(line);
	free(line);
	return (file_content);
}
