/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_map_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:24:58 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/08/30 01:58:08 by mluis-fu         ###   ########.fr       */
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
	mlx->h_enemy.dir = 0;
	mlx->r_enemy.frame = 0;
	mlx->player.frame = 0;
	mlx->move = 0;
	mlx->init = mlx_init();
	mlx->sta_enemy.time = 0;
	mlx->h_enemy.time = 0;
//	mlx->h_enemy.file = dinamic_copy("asset/snorlaxW00.xpm");
//	mlx->sta_enemy.file = dinamic_copy("asset/sleep00.xpm");
	//mlx->ball.file = dinamic_copy("asset/00.xpm");
	images_load(mlx, &mlx->player, "asset/player_N00.xpm", 2);
	images_load(mlx, &mlx->sta_enemy, "asset/sleep00.xpm", 3);
	images_load(mlx, &mlx->ball, "asset/00.xpm", 20);
	images_load(mlx, &mlx->h_enemy, "asset/snorlaxW00.xpm", 2);
	images_load(mlx, &mlx->r_enemy, "asset/snorlaxE00.xpm", 2);
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
