/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:47:47 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/08/16 16:52:50 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_exit(const char *str, char **map, char *lane)
{
	int	count;

	count = 0;
	while (map[count])
	{
		free(map[count]);
		count++;
	}
	free(lane);
	write (1, &str, ft_strlen(str));
}
