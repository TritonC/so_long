/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:25:09 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/08/20 17:24:37 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	key_hook_esc(int key, t_mlx *mlx)
{
	if (mlx->map[mlx->player.y + 1][mlx->player.x] == 'P')
		mlx->map[mlx->player.y + 1][mlx->player.x] = '0';
	map_clean(mlx, mlx->player.x, mlx->player.y);
	map_clean(mlx, mlx->player.x, mlx->player.y + 1);
	if (key == KEY_ESC)
		exit(EXIT_SUCCESS);
	if (key == KEY_D && mlx->map[mlx->player.y + 1][mlx->player.x + 1] != '1')
	{
		img_name(mlx, 'E', 13);
		mlx->player.x += 1;
	}
	if (key == KEY_A && mlx->map[mlx->player.y + 1][mlx->player.x - 1] != '1')
	{
		img_name(mlx, 'W', 13);
		mlx->player.x -= 1;
	}
	if (key == KEY_S && mlx->map[mlx->player.y + 2][mlx->player.x] != '1')
	{
		img_name(mlx, 'S', 13);
		mlx->player.y += 1;
	}
	if (key == KEY_W && mlx->map[mlx->player.y][mlx->player.x] != '1')
	{
		img_name(mlx, 'N', 13);
		mlx->player.y -= 1;
	}
	if (mlx->map[mlx->player.y + 1][mlx->player.x] == 'C')
	{
		mlx->map[mlx->player.y + 1][mlx->player.x] = '0';
		map_clean(mlx, mlx->player.x, mlx->player.y + 1);
	}
	player_move(mlx);
	if (!exit_check(mlx->map))
		printf("done");
	//map_clean(mlx, mlx->player.x - 1, mlx->player.y);
	return (0);
}
