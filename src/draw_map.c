/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:57:20 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/04/02 13:07:41 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * It returns a pointer to an image based on the character passed to it
 * 
 * @param mlx the pointer to the mlx window
 * @param c the character that is being checked
 * 
 * @return a pointer to the image.
 */
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

// this function, choose the sprite to put in the image, based on the letter

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
		return (mlx->sta_enemy.file);
	else
		return (FLOOR);
}

/**
 * It draws the map
 * 
 * @param mlx the main structure
 * @param coords the coordinates of the current tile
 */
void	draw_map_util(t_mlx *mlx, t_coord coords)
{
	put_and_destroy(mlx, choose_filename(mlx, '0'), coords);
	if (mlx->map[coords.y][coords.x] == 'P')
	{
		mlx->player.x = coords.x;
		mlx->player.y = coords.y;
	}
	if (mlx->map[coords.y][coords.x] == 'E')
	{
		mlx->exit.x = coords.x;
		mlx->exit.y = coords.y;
	}
	if (mlx->map[coords.y][coords.x] == 'S')
	{
		mlx->sta_enemy.x = coords.x;
		mlx->sta_enemy.y = coords.y;
	}
	if (mlx->map[coords.y][coords.x] == 'H')
	{
		mlx->h_enemy.pos.x = coords.x;
		mlx->h_enemy.pos.y = coords.y;
	}
	if (mlx->map[coords.y][coords.x] != 'P')
		put_and_destroy(mlx,
			choose_filename(mlx, mlx->map[coords.y][coords.x]), coords);
}

/**
 * It draws the map
 * 
 * @param mlx the main structure that holds all the information about the map, the player, and the
 * image.
 */
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
	player_move(mlx);
}
