/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:57:20 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/08/28 12:44:31 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	*choose_img(void *mlx, char c)
{
	int	x;

	if (c == '1')
		return (mlx_xpm_file_to_image(mlx, "asset/tile01.xpm", &x, &x));
	else if (c == 'E')
		return (mlx_xpm_file_to_image(mlx, "asset/stone.xpm", &x, &x));
	else if (c == 'C')
		return (mlx_xpm_file_to_image(mlx, "asset/ball.xpm", &x, &x));
	else if (c == 'L')
		return (mlx_xpm_file_to_image(mlx, "asset/ladder.xpm", &x, &x));
	else
		return (mlx_xpm_file_to_image(mlx, "asset/tile00.xpm", &x, &x));
}

char	*choose_filename(t_mlx *mlx, char c)
{
	if (c == '1')
		return (WALL);
	else if (c == 'E')
		return (STONE);
	else if (c == 'C')
		return (mlx->ball.file);
	else if (c == 'L')
		return (LADDER);
	else if (c == 'S')
		return (mlx->sta_enemie.file);
	else
		return (FLOOR);
}

void	draw_map_util(t_mlx *mlx, t_coord coords)
{
	put_and_destroy(mlx, choose_filename(mlx, '0'), coords);
	if (mlx->map[coords.y][coords.x] == 'P')
	{
		mlx->player.x = coords.x;
		mlx->player.y = coords.y - 1;
	}
	if (mlx->map[coords.y][coords.x] == 'E')
	{
		mlx->exit.x = coords.x;
		mlx->exit.y = coords.y;
	}
	if (mlx->map[coords.y][coords.x] == 'S')
	{
		mlx->sta_enemie.x = coords.x;
		mlx->sta_enemie.y = coords.y;
	}
	if (mlx->map[coords.y][coords.x] != 'P')
		put_and_destroy(mlx,
			choose_filename(mlx, mlx->map[coords.y][coords.x]), coords);
}

void	draw_map(t_mlx *mlx)
{
	t_coord	coords;

	coords.x = -1;
	while (++coords.x < mlx->coord.x)
	{
		coords.y = -1;
		while (++coords.y < mlx->coord.y)
			draw_map_util(mlx, coords);
	}
	mlx->map[mlx->player.y + 1][mlx->player.x] = '0';
	map_clean(mlx, mlx->player.x, mlx->player.y + 1);
	player_move(mlx);
}
