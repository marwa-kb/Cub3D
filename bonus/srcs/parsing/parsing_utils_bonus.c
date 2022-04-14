/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:57:34 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/28 16:57:37 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static int	count_lines_from_txt(char *txt)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!txt)
		return (0);
	while (txt[i])
	{
		if (txt[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

static int	init(int fd, int *count, int *nb, char buffer[])
{
	*count = 0;
	*nb = read(fd, buffer, BUFFER_SIZE);
	return (*nb);
}

int	ft_count_lines(int fd)
{
	int		nb;
	int		count;
	char	*txt;
	char	*tmp;
	char	buffer[BUFFER_SIZE + 1];

	txt = NULL;
	if (init(fd, &count, &nb, buffer) == -1)
		return (-1);
	while (nb > 0)
	{
		buffer[nb] = '\0';
		if (!txt)
			txt = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(txt, buffer);
			free(txt);
			txt = tmp;
		}
		nb = read(fd, buffer, BUFFER_SIZE);
	}
	count = count_lines_from_txt(txt);
	free(txt);
	return (count);
}

int	ft_tab_len(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			i++;
	}
	return (i);
}
