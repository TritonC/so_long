/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:57:20 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/08/11 12:35:34 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*img_to_show(void *mlx, char c)
{
	int	x;

	if (c == '1')
		return (mlx_xpm_file_to_image(mlx, "visual/wall.xpm", &x, &x));
	else if (c == 'E')
		return (mlx_xpm_file_to_image(mlx, "visual/player.xpm", &x, &x));
	else if (c == 'C')
		return (mlx_xpm_file_to_image(mlx, "visual/collectible.xpm", &x, &x));
	else if (c == 'P')
		return (mlx_xpm_file_to_image(mlx, "visual/player_for.xpm", &x, &x));
	else
		return (mlx_xpm_file_to_image(mlx, "floor/wall.xpm", &x, &x));
}

void	draw_map(t_mlx mlx)
{
	t_coord	coords;

	coords.y = -1;
	while (++coords.y > mlx.coord.y)
	{
		coords.x = -1;
		while (++coords.x > mlx.coord.x)
		{
			mlx.img = img_to_show(mlx.init, mlx.map[coords.y][coords.x]);
			mlx_put_image_to_window(mlx.init, mlx.win,
				mlx.img, coords.x * 20, coords.y * 20);
		}
	}
}
