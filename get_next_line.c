/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:04:38 by aaguiler          #+#    #+#             */
/*   Updated: 2022/05/02 19:32:10 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_cut_line(char *memom)
{
	char	*r;
	int		len;
	int		i;
	int		linelen;

	linelen = ft_line_len(memom);
	len = ft_strlen(memom) - linelen;
	if (len == 0)
	{
		free (memom);
		memom = NULL;
		return (NULL);
	}
	r = (char *)malloc(len + 1 * sizeof(char));
	if (!r)
	{
		free (memom);
		return (NULL);
		return (NULL);
	}
	r[len] = '\0';
	i = 0;
	while (i < len)
	{
		r[i] = memom[linelen + i];
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
			memom = NULL;
			return (NULL);
		}
		memom = ft_strjoin (memom, buff, n);
	}
	nl = ft_get_line(memom);
	memom = ft_cut_line(memom);
	return (nl);
}

int	main(void)
{
	int fd;

	fd = open ("ejemplo2", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
}
