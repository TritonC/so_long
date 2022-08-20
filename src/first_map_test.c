/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_map_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:24:58 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/08/20 15:35:30 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	img_name(t_mlx *mlx, char c, int pos)
{
	mlx->name.player[pos] = c;
	mlx->name.player[15] = '0' + mlx->movements;
	if (mlx->movements < 2)
		mlx->movements++;
	else
		mlx->movements = 0;
}

void	put_name(char *name_replace, char *file)
{
	int	count;

	count = -1;
	while (file[++count])
	{
		name_replace[count] = file[count];
	}
	name_replace[count] = '\0';
}

void	init_game(t_mlx *mlx)
{
	int	x;

	x = -1;
	mlx->movements = 0;
	mlx->init = mlx_init();
	put_name(mlx->name.player, "asset/player_N00.xpm");
	mlx->win = mlx_new_window(mlx->init, mlx->coord.x * 64, mlx->coord.y * 64,
			"so_long_failure");
	draw_map(mlx);
	mlx->img = mlx_xpm_file_to_image(mlx->init, mlx->name.player, &x, &x);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, mlx->coord.x,
		mlx->coord.y);
}

int	main(int agrc, char **agrv)
{
	t_mlx		mlx;

	if (agrc != 2)
		return (ft_printf("argument number invalid\n"));
	create_map(agrv[1], &mlx);
	init_game(&mlx);
	mlx_key_hook(mlx.win, key_hook_esc, &mlx);
	mlx_loop(mlx.init);
}
