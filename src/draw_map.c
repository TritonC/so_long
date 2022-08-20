/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:57:20 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/08/20 17:27:30 by mluis-fu         ###   ########.fr       */
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
	else if (c == 'P')
		return (mlx_xpm_file_to_image(mlx, "asset/player_S00.xpm", &x, &x));
	else if (c == 'L')
		return (mlx_xpm_file_to_image(mlx, "asset/ladder.xpm", &x, &x));
	else
		return (mlx_xpm_file_to_image(mlx, "asset/tile00.xpm", &x, &x));
}

void	draw_map(t_mlx *mlx)
{
	t_coord	coords;

	coords.x = -1;
	while (++coords.x < mlx->coord.x)
	{
		coords.y = -1;
		while (++coords.y < mlx->coord.y)
		{
			if (mlx->map[coords.y][coords.x] == 'P')
			{
				mlx->player.x = coords.x;
				mlx->player.y = coords.y - 1;
			}
			if (mlx->map[coords.y][coords.x] != 'P')
			{
				mlx->img = choose_img(mlx->init, mlx->map[coords.y][coords.x]);
				mlx_put_image_to_window(mlx->init, mlx->win,
					mlx->img, coords.x * PI, coords.y * PI);
			}
		}
	}
	mlx->map[mlx->player.y + 1][mlx->player.x] = '0';
	map_clean(mlx, mlx->player.x, mlx->player.y + 1);
	player_move(mlx);
}
