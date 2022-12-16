/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_option.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:22:22 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/12/16 19:14:49 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

// function to find the enemy position
t_data	choose_data(t_mlx *mlx, int x, int y)
{
	if (x == -1 && y == 0)
		return (mlx->h_enemy);
	else if (x == 1 && y == 0)
		return (mlx->r_enemy);
	else if (y == 1 && x == 0)
		return (mlx->d_enemy);
	else
		return (mlx->u_enemy);
}

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
