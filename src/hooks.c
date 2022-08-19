/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:25:09 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/08/19 14:51:54 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	key_hook_esc(int key, t_mlx *mlx)
{
	int	x;

	mlx->img = choose_img(mlx->init, '0');
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, mlx->coord.x * 60,
		mlx->coord.y * 60);
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == KEY_D)
	{
		img_name(mlx, 'E', 13);
		mlx->coord.x += 1;
	}
	if (key == KEY_A)
	{
		img_name(mlx, 'W', 13);
		mlx->coord.x -= 1;
	}
	if (key == KEY_S)
	{
		img_name(mlx, 'S', 13);
		mlx->coord.y += 1;
	}
	if (key == KEY_W)
	{
		img_name(mlx, 'N', 13);
		mlx->coord.y -= 1;
	}
	mlx->img = mlx_xpm_file_to_image(mlx->init, mlx->name.player, &x, &x);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, mlx->coord.x * 60,
		mlx->coord.y * 60);
	return (0);
}
