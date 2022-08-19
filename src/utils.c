/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:47:47 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/08/19 13:13:21 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	free_write_exit(const char *str, char **map, char *lane, int e)
{
	int	count;

	count = 0;
	while (map[count])
	{
		free(map[count]);
		count++;
	}
	free(lane);
	if (lane)
		free(lane);
	if (map)
		free(map);
	write (2, str, ft_strlen(str));
	exit (e);
}

int	close_win(t_mlx *mlx)
{
	mlx_clear_window(mlx->init, mlx->win);
	mlx_destroy_window(mlx->init, mlx->win);
	free_write_exit(NULL, mlx->map, NULL, 1);
	return (0);
}
