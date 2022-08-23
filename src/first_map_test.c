/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_map_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:24:58 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/08/23 19:41:52 by mluis-fu         ###   ########.fr       */
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
	int	x;

	x = -1;
	mlx->player.frame = 0;
	mlx->init = mlx_init();
	mlx->player.file = malloc(21);
	ft_strlcpy(mlx->player.file, "asset/player_N00.xpm", 21);
	mlx->win = mlx_new_window(mlx->init, mlx->coord.x * PI, mlx->coord.y * PI,
			"so_long_failure");
	draw_map(mlx);
	mlx->img = mlx_xpm_file_to_image(mlx->init, mlx->player.file, &x, &x);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, mlx->coord.x,
		mlx->coord.y);
}

int	main(int argc, char **argv)
{
	t_mlx		mlx;

	if (argc != 2)
		return (ft_printf("Error: argument number invalid\n"));
	create_map(argv[1], &mlx);
	init_game(&mlx);
	mlx_key_hook(mlx.win, key_hook_esc, &mlx);
	mlx_loop(mlx.init);
}
