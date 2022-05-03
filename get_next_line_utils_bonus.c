/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:55:28 by aaguiler          #+#    #+#             */
/*   Updated: 2022/05/03 10:15:48 by aaguiler         ###   ########.fr       */
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
	int	i;

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

	if (!memom)
	{
		memom = ft_calloc(1, 1);
		if (!memom)
			return (NULL);
	}
	len = ft_strlen(memom) + n;
	r = ft_calloc(len + 1, sizeof(char));
	if (!r)
	{
		free (memom);
		return (NULL);
	}
	i = -1;
	while (memom[++i])
		r[i] = memom [i];
	len = -1;
	while (++len < n)
		r[len + i] = buff[len];
	free (memom);
	return (r);
}

int	ft_line_len(char *memom)
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
	nl = ft_calloc(len + 1, sizeof(char));
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
