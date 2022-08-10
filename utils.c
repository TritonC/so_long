/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:04:33 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/07/09 03:47:05 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//way prettier than my libft one
int	ft_strlen(const char *str)
{
	const char	*prev;

	prev = str;
	while (str && *str)
		str++;
	return (str - prev);
}

//e = -1 if dont wanna exit
void	free_write_exit(const char *str, char **fr1, char *fr2, int e)
{
	int	counter;

	if (fr1)
	{
		counter = 0;
		while (fr1[counter])
		{
			free(fr1[counter]);
			counter++;
		}
		free(fr1);
	}
	if (fr2)
		free(fr2);
	if (str)
		write(2, str, ft_strlen(str));
	if (e != -1)
		exit(e);
}

void	ft_putnbr(int n)
{
	long	long_n;
	int		div;
	char	c;	

	long_n = n;
	div = 1;
	if (long_n < 0)
	{
		write(1, "-", 1);
		long_n *= -1;
	}
	while (long_n / div > 9)
		div *= 10;
	while (div)
	{
		c = '0' + (long_n / div) % 10;
		write(1, &c, 1);
		div /= 10;
	}
}

int	close_win(t_mlx *mlx)
{
	mlx_clear_window(mlx->init, mlx->win);
	mlx_destroy_window(mlx->init, mlx->win);
	free_write_exit(NULL, mlx->map, NULL, 0);
	return (0);
}
