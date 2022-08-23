/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 20:28:48 by dsanchez          #+#    #+#             */
/*   Updated: 2022/08/23 19:55:50 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	num;
	size_t	counter;
	char	*mem;

	num = count * size;
	counter = 0;
	mem = NULL;
	if (num < size && num < count)
		return (NULL);
	mem = malloc(num);
	if (!mem)
		return (NULL);
	while (counter < num)
		mem[counter++] = 0;
	return ((void *)mem);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count])
	{
		count++;
	}
	return (count);
}

char	*ft_strchr(const char *str, int ch)
{
	int	len;

	len = ft_strlen(str);
	if (ch == 0)
		return ((char *)str + (char)len);
	while (*str)
	{
		if (*str == (char)ch)
			return ((char *)str);
		str++;
	}
	return (0);
}

char	*ft_strjoin(char const *dest, char const *src)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	res = ft_calloc(sizeof(char), (ft_strlen(dest) + ft_strlen(src) + 1));
	if (!res || (!dest && !src))
		return (NULL);
	if (dest)
	{
		while (dest[i])
		{
			res[i] = dest[i];
			i++;
		}
	}
	j = 0;
	while (src[j] != 0)
	{
		res[i] = src[j];
		i++;
		j++;
	}
	return (res);
}
