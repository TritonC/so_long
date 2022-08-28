/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_map_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:24:58 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/08/28 12:58:01 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	img_name(t_mlx *mlx, char c, int pos, int frame_max)
{
	mlx->player.file[pos] = c;
	mlx->player.file[15] = '0' + mlx->player.frame;
	if (mlx->player.frame < frame_max)
		mlx->player.frame++;
	else
		mlx->player.frame = 0;
}

void	init_game(t_mlx *mlx)
{
	mlx->time = 0;
	mlx->player.frame = 0;
	mlx->move = 0;
	mlx->init = mlx_init();
	mlx->sta_enemie.time = 0;
	mlx->sta_enemie.file = dinamic_copy("asset/sleep00.xpm");
	mlx->player.file = dinamic_copy("asset/player_N00.xpm");
	mlx->ball.file = dinamic_copy("asset/00.xpm");
	mlx->win = mlx_new_window(mlx->init, mlx->coord.x * PI, mlx->coord.y * PI,
			"so_long");
	draw_map(mlx);
}

int	main(int argc, char **argv)
{
	t_mlx		mlx;

	if (argc != 2)
		return (ft_printf("Error: argument number invalid\n"));
	create_map(argv[1], &mlx);
	init_game(&mlx);
	mlx_hook(mlx.win, 02, 1L << 0, key_hook_esc, &mlx);
	mlx_loop_hook(mlx.init, animations, &mlx);
	mlx_loop(mlx.init);
}
