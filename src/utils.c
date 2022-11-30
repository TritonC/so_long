/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:47:47 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/11/30 16:15:27 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

// this function is the more usefull one, this function just free the pointer 
// send as parameter and print the message send it by parameter too

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

// just a quick access to make a dinamic copy from sprite names
// checking the errors at the same time

char	*dinamic_copy(char *file)
{
	char	*temp;
	int		count;

	count = -1;
	temp = ft_calloc(ft_strlen(file) + 1, 1);
	if (!temp)
		free_write_exit("sprite error", NULL, temp, 1);
	while (file[++count])
		temp[count] = file[count];
	return (temp);
}

void	player_move(t_mlx *mlx)
{
	int	x;

	mlx->img = mlx_xpm_file_to_image(mlx->init, mlx->player.file, &x, &x);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, mlx->player.x * PI,
		mlx->player.y * PI);
}

// the more spammable function the game, this clean the pixel
// using coords, clean (destroy the image, and put another one to replace it

void	map_clean(t_mlx *mlx, int x, int y)
{
	t_coord	coords;

	coords.x = x;
	coords.y = y;
	put_and_destroy(mlx, choose_filename(mlx, '0'), coords);
	if (mlx->map[y][x] != 'C')
		put_and_destroy(mlx, choose_filename(mlx, mlx->map[y][x]), coords);
	else
		image_animate(mlx, &mlx->ball, x * 64, y * 64);
}

// with this one, if there's no more collectibles, so the player can now
// walk through the door and leave

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
