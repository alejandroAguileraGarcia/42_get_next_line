/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:55:28 by aaguiler          #+#    #+#             */
/*   Updated: 2022/05/02 19:27:23 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_is_line(char *memom, int n)
{
	int i;

	if (n < BUFFER_SIZE)
		return (1);
	i = 0;
	if (!memom)
		return (0);
	while (memom[i])
	{
		if (memom[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *memom, char *buff, int n)
{
	char	*r;
	int		len;
	int		i;
	int		j;

	if (!memom)
	{
		memom = malloc(1);
		memom[0] = 0;
	}
	len = ft_strlen(memom) + n;
	r = (char *)malloc((len + 1) * sizeof(char));
	if (!r)
	{
		if (memom)
			free (memom);
		return (NULL);
	}
	r[len] = '\0';
	i = 0;
	while (memom[i])
	{
		r[i] = memom [i];
		i++;
	}
	j = 0;
	while (buff[j])
	{
		r[j + i] = buff[j];
		j++;
	}
	if (memom)
		free (memom);
	return (r);
}

int		ft_line_len(char *memom)
{
	int	i;

	i = 0;
	while (memom [i])
	{
		if (memom[i] == '\n')
			return (i + 1);
		i++;
	}
	return (ft_strlen (memom));
}

char	*ft_get_line(char *memom)
{
	int		i;
	int		len;
	char	*nl;

	len = ft_line_len(memom);
	nl = (char *)malloc((len + 1) * sizeof(char));
	if (!nl)
		return (NULL);
	nl[len] = '\0';
	i = 0;
	while (i < len)
	{
		nl[i] = memom[i];
		i++;
	}
	return (nl);
}
