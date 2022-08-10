/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:27:06 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/07/10 00:15:50 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*img_choose(void *mlx, char c)
{
	int	x;

	if (c == '1')
		return (mlx_xpm_file_to_image(mlx, "visual/wall.xpm", &x, &x));
	else if (c == 'E')
		return (mlx_xpm_file_to_image(mlx, "visual/exit.xpm", &x, &x));
	else if (c == 'C')
		return (mlx_xpm_file_to_image(mlx, "visual/collectible.xpm", &x, &x));
	else if (c == 'P')
		return (mlx_xpm_file_to_image(mlx, "visual/player_for.xpm", &x, &x));
	else if (c == 'L')
		return (mlx_xpm_file_to_image(mlx, "visual/player_left.xpm", &x, &x));
	else if (c == 'R')
		return (mlx_xpm_file_to_image(mlx, "visual/player_right.xpm", &x, &x));
	else if (c == 'B')
		return (mlx_xpm_file_to_image(mlx, "visual/player_back.xpm", &x, &x));
	return (mlx_xpm_file_to_image(mlx, "visual/suelo.xpm", &x, &x));
}

void	draw_map(t_mlx mlx)
{
	t_coor	cnt;
	void	*img;

	cnt.y = -1;
	while (++cnt.y < mlx.dim.y)
	{
		cnt.x = -1;
		while (++cnt.x < mlx.dim.x)
		{
			img = img_choose(mlx.init, mlx.map[cnt.y][cnt.x]);
			if (!img)
				free_write_exit("Error: image not found\n", mlx.map, NULL, 1);
			mlx_put_image_to_window(mlx.init, mlx.win,
				img, cnt.x * 20, cnt.y * 20);
		}
	}
}
