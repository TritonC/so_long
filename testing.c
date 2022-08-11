/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:06:37 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/08/11 11:43:53 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_mlx	mlx;

	mlx.init = mlx_init();
	mlx.win = mlx_new_window(mlx.init, 1920, 1080, "so_long");
	mlx.img = mlx_xpm_file_to_image(mlx.init, "visual/player_left.xpm",
			&mlx.coord.x, &mlx.coord.y);
	mlx_put_image_to_window(mlx.init, mlx.win, mlx.img, 50, 50);
	mlx_key_hook(mlx.win, key_hook_esc, mlx.init);
	mlx_loop(mlx.init);
}
