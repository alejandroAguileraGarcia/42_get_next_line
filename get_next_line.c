/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:04:38 by aaguiler          #+#    #+#             */
/*   Updated: 2022/05/03 10:30:19 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_calloc(int count, int size)
{
	char	*r;
	int		i;

	r = malloc(count * size);
	if (!r)
		return (0);
	i = 0;
	while (i < count * size)
		r[i++] = 0;
	return (r);
}

char	*ft_cut_line(char *memom)
{
	char	*r;
	int		len;
	int		i;

	len = ft_strlen(memom) - ft_line_len(memom);
	if (len == 0)
	{
		free (memom);
		return (NULL);
	}
	r = ft_calloc(len + 1, sizeof(char));
	if (!r)
	{
		free (memom);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		r[i] = memom[ft_line_len(memom) + i];
		i++;
	}
	free(memom);
	return (r);
}

char	*get_next_line(int fd)
{
	static char	*memom = NULL;
	char		buff[BUFFER_SIZE + 1];
	char		*nl;
	int			n;

	nl = NULL;
	n = BUFFER_SIZE;
	buff[n] = '\0';
	while (!ft_is_line(memom, n))
	{
		n = read (fd, buff, BUFFER_SIZE);
		if (n == -1)
			return (NULL);
		if (n == 0 && !memom)
		{
			free (memom);
			if (nl)
				free (nl);
			return (NULL);
		}
		memom = ft_strjoin (memom, buff, n);
	}
	nl = ft_get_line(memom);
	memom = ft_cut_line(memom);
	return (nl);
}
