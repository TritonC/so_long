/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 00:30:14 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/08/24 11:35:32 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	img_name_animation(t_data *data, int pos)
{
	data->file[pos] = '0' + data->frame;
	if (data->frame >= 10)
	{
		data->file[pos - 1] = '0' + data->frame / 10;
		data->file[pos] = '0' + data->frame % 10;
	}
	else
	{
		data->file[pos - 1] = '0';
		data->file[pos] = '0' + data->frame;
	}
}

void	put_and_destroy(t_mlx *mlx, char *file, t_coord coords)
{
	int	x;

	mlx->img = mlx_xpm_file_to_image(mlx, file, &x, &x);
	mlx_put_image_to_window(mlx->init, mlx->win,
		mlx->img, coords.x * PI, coords.y * PI);
	mlx_destroy_image(mlx->init, mlx->img);
}

int	animations(t_mlx *mlx)
{
	t_coord	coords;

	coords.x = -1;
	if (!(mlx->time++ % 1000))
	{
		while (++coords.x < mlx->coord.x)
		{
			coords.y = -1;
			while (++coords.y < mlx->coord.y)
			{
				if (mlx->map[coords.y][coords.x] == 'C')
				{
					put_and_destroy(mlx, choose_filename(mlx, '0'), coords);
					put_and_destroy(mlx, mlx->ball.file, coords);
					img_name_animation(&mlx->ball, 9);
					if (mlx->player.x == coords.x && mlx->player.y == coords.y)
						put_and_destroy(mlx, mlx->player.file, coords);
				}
			}
		}
		if (mlx->ball.frame < 19)
		mlx->ball.frame++;
		else
		mlx->ball.frame = 0;
	}
	return (0);
}
