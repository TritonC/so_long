/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:25:09 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/08/23 18:51:13 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	key_hook_esc(int key, t_mlx *mlx)
{
	t_coord check_E;

	check_E.x = 0;
	check_E.y = 0;
	if (mlx->map[mlx->player.y + 1][mlx->player.x] == 'P')
		mlx->map[mlx->player.y + 1][mlx->player.x] = '0';
	map_clean(mlx, mlx->player.x, mlx->player.y);
	map_clean(mlx, mlx->player.x, mlx->player.y + 1);
	if (key == KEY_ESC)
		exit(EXIT_SUCCESS);
	player_north(mlx, key);
	player_south(mlx, key);
	player_east(mlx, key);
	player_west(mlx, key);
	if (mlx->map[mlx->player.y + 1][mlx->player.x] == 'C')
	{
		mlx->map[mlx->player.y + 1][mlx->player.x] = '0';
		map_clean(mlx, mlx->player.x, mlx->player.y + 1);
	}
	player_move(mlx);
	if (!exit_check(mlx->map) && mlx->player.x == mlx->exit.x
		&& mlx->player.y == mlx->exit.y - 1)
		exit(EXIT_SUCCESS);
	return (0);
}
