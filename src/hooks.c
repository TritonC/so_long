/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:25:09 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/08/19 15:41:58 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	key_hook_esc(int key, t_mlx *mlx)
{
	int	x;
	if (mlx->map[mlx->player.y + 1][mlx->player.x] == 'P')
		mlx->map[mlx->player.y + 1][mlx->player.x] = '0';
	if (mlx->map[mlx->player.y + 1][mlx->player.x] == 'C')
		mlx->map[mlx->player.y + 1][mlx->player.x] = '0';
	mlx->img = choose_img(mlx->init, mlx->map[mlx->player.y][mlx->player.x]);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, mlx->player.x * PI,
		mlx->player.y * PI);
	mlx->img = choose_img(mlx->init, mlx->map[mlx->player.y + 1][mlx->player.x]);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, mlx->player.x * PI,
		(mlx->player.y + 1) * PI);
	
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == KEY_D)
	{
		img_name(mlx, 'E', 13);
		mlx->player.x += 1;
	}
	if (key == KEY_A)
	{
		img_name(mlx, 'W', 13);
		mlx->player.x -= 1;
	}
	if (key == KEY_S)
	{
		img_name(mlx, 'S', 13);
		mlx->player.y += 1;
	}
	if (key == KEY_W)
	{
		img_name(mlx, 'N', 13);
		mlx->player.y -= 1;
	}
	mlx->img = mlx_xpm_file_to_image(mlx->init, mlx->name.player, &x, &x);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, mlx->player.x * PI,
		mlx->player.y * PI);
	return (0);
}
