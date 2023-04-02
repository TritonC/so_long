/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_option.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:22:22 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/04/02 12:59:19 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/* A function that finds the enemy position. */
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


/**
 * It takes the name of the file and changes the last two digits to the current frame number
 * 
 * @param data the structure containing all the data
 * @param pos the position of the last digit in the file name
 */
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

/**
 * It puts an image to the window and destroys it
 * 
 * @param mlx the structure containing the mlx_init, mlx_win, and mlx_img
 * @param file the path to the image file
 * @param coords the coordinates of the image to be put on the window
 */
void	put_and_destroy(t_mlx *mlx, char *file, t_coord coords)
{
	int	x;

	mlx->img = mlx_xpm_file_to_image(mlx, file, &x, &x);
	mlx_put_image_to_window(mlx->init, mlx->win,
		mlx->img, coords.x * PI, coords.y * PI);
	mlx_destroy_image(mlx->init, mlx->img);
}
