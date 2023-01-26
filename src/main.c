/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:24:58 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/01/26 11:06:04 by mluis-fu         ###   ########.fr       */
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
	mlx->enemies = enemy_init(mlx->map);
	images_load(mlx, &mlx->u_enemy, "asset/snorlaxN00.xpm", 2);
	images_load(mlx, &mlx->d_enemy, "asset/snorlaxS00.xpm", 2);
	images_load(mlx, &mlx->player, "playe/player_N00.xpm", 2);
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
	t_coord		coord;
	char		**new_map;

	if (argc != 2)
		return (ft_printf("Error: argument number invalid\n"));
	create_map(argv[1], &mlx);
	coord.x = 0;
	coord.y = 0;
	coord = find_player(mlx.map, coord);
	new_map = map_checker(map_cpy(mlx.map), coord.y, coord.x);
	if (map_evaluator(new_map))
	{
		init_game(&mlx);
		mlx_hook(mlx.win, 02, 1L << 0, key_hook_esc, &mlx);
		mlx_loop_hook(mlx.init, animations, &mlx);
		mlx_hook(mlx.win, 17, 0, ft_exit, &mlx);
		mlx_loop(mlx.init);
	}
	else
		ft_printf("error: invalid map\n");
	return (0);
}
