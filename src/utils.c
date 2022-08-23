/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:47:47 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/08/24 01:31:55 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	free_write_exit(const char *str, char **map, char *lane, int e)
{
	int	counter;

	if (map)
	{
		counter = 0;
		while (map[counter])
		{
			free(map[counter]);
			counter++;
		}
		free(map);
	}
	if (lane)
		free(lane);
	if (str)
		write(2, str, ft_strlen(str));
	if (e != -1)
		exit(e);
}

int	close_win(t_mlx *mlx)
{
	mlx_clear_window(mlx->init, mlx->win);
	mlx_destroy_window(mlx->init, mlx->win);
	free_write_exit(NULL, mlx->map, NULL, 1);
	return (0);
}

void	player_move(t_mlx *mlx)
{
	int	x;

/*	mlx->img = mlx_xpm_file_to_image(mlx->init, mlx->player.file, &x, &x);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, mlx->player.x * PI,
		mlx->player.y * PI);

	mlx->img = mlx_xpm_file_to_image(mlx->init, mlx->player.file, &x, &x);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, mlx->player.x * PI,
		mlx->player.y * PI);
*/
	mlx->img = mlx_xpm_file_to_image(mlx->init, mlx->player.file, &x, &x);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, mlx->player.x * PI,
		mlx->player.y * PI);
}

void	map_clean(t_mlx *mlx, int x, int y)
{
	mlx->img = choose_img(mlx->init, '0');
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, x * PI,
		y * PI);
	mlx->img = choose_img(mlx->init, mlx->map[y][x]);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, x * PI,
		y * PI);
}

int	exit_check(char **map)
{
	t_coord	pos;
	int		count;

	pos.x = -1;
	count = 0;
	while (map[++pos.x])
	{
		pos.y = -1;
		while (map[pos.x][++pos.y])
		{
			if (map[pos.x][pos.y] == 'C')
				count++;
		}
	}
	return (count);
}
