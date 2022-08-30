/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:25:09 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/08/30 17:42:53 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	player_movement_count(t_mlx *mlx, int key)
{
	char	*move_count;

	if (key == KEY_ESC)
		exit(EXIT_SUCCESS);
	player_north(mlx, key);
	player_south(mlx, key);
	player_east(mlx, key);
	player_west(mlx, key);
	move_count = ft_itoa(mlx->move);
	map_clean(mlx, 0, 0);
	mlx_string_put(mlx->init, mlx->win, 19, 18, 0, move_count);
}

int	key_hook_esc(int key, t_mlx *mlx)
{
	if (mlx->map[mlx->player.y][mlx->player.x] == 'P')
		mlx->map[mlx->player.y][mlx->player.x] = '0';
	map_clean(mlx, mlx->player.x, mlx->player.y);
	map_clean(mlx, mlx->player.x, mlx->player.y);
	player_movement_count(mlx, key);
	if (mlx->map[mlx->player.y][mlx->player.x] == 'C')
	{
		mlx->map[mlx->player.y][mlx->player.x] = '0';
		map_clean(mlx, mlx->player.x, mlx->player.y);
	}
	player_move(mlx);
	if (!exit_check(mlx->map))
	{
		mlx->map[mlx->exit.y][mlx->exit.x] = 'L';
		map_clean(mlx, mlx->exit.x, mlx->exit.y);
	}
	if (mlx->map[mlx->exit.y][mlx->exit.x] == 'L' && mlx->player.x
			== mlx->exit.x && mlx->player.y == mlx->exit.y)
	{
		ft_printf("%s", "Congratz, you win the game!!!!\n");
		exit(EXIT_SUCCESS);
	}
	return (0);
}
