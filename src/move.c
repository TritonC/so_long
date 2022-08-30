/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:09:58 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/08/30 20:48:02 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	player_north(t_mlx *mlx, int key)
{
	t_coord	p;

	p.x = mlx->coord.x * PI / 2 - 160;
	p.y = mlx->coord.y * PI / 2 - 160;
	if (key == KEY_W && mlx->map[mlx->player.y - 1][mlx->player.x] != '1'
		&& mlx->map[mlx->player.y][mlx->player.x] != 'E')
	{
		img_name(mlx, 'N', 13, 2);
		mlx->player.y -= 1;
		mlx->move += 1;
	}
	if (key == KEY_W && mlx->map[mlx->player.y][mlx->player.x] == 'S')
	{
		ft_printf("You lose!!!!!\n");
		exit(EXIT_SUCCESS);
	}
}

void	player_south(t_mlx *mlx, int key)
{
	if (key == KEY_S && mlx->map[mlx->player.y + 1][mlx->player.x] != '1'
		&& mlx->map[mlx->player.y + 2][mlx->player.x] != 'E')
	{
		img_name(mlx, 'S', 13, 2);
		mlx->player.y += 1;
		mlx->move += 1;
	}
	if (key == KEY_S && mlx->map[mlx->player.y][mlx->player.x] == 'S')
	{
		ft_printf("You lose!!!!!\n");
		exit(EXIT_SUCCESS);
	}
}

void	player_east(t_mlx *mlx, int key)
{
	if (key == KEY_A && mlx->map[mlx->player.y][mlx->player.x - 1] != '1'
		&& mlx->map[mlx->player.y][mlx->player.x - 1] != 'E')
	{
		img_name(mlx, 'W', 13, 2);
		mlx->player.x -= 1;
		mlx->move += 1;
	}
	if (key == KEY_A
		&& ft_strchr("S", mlx->map[mlx->player.y][mlx->player.x]))
	{
		ft_printf("You lose!!!!!\n");
		exit(EXIT_SUCCESS);
	}
}

void	player_west(t_mlx *mlx, int key)
{
	if (key == KEY_D && (mlx->map[mlx->player.y][mlx->player.x + 1] != '1'
		&& mlx->map[mlx->player.y][mlx->player.x + 1] != 'E'))
	{
		img_name(mlx, 'E', 13, 2);
		mlx->player.x += 1;
		mlx->move += 1;
	}
	if (key == KEY_D && mlx->map[mlx->player.y][mlx->player.x] == 'S')
	{
		ft_printf("You lose!!!!!\n");
		exit(EXIT_SUCCESS);
	}
}
