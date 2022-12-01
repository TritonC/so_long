/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newtry.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:38:59 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/12/01 23:20:13 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	relaunch(t_mlx *mlx, int key, int fail)
{
	char	*win_choose;
	int		x;

	if (fail == 1)
		win_choose = dinamic_copy(INIT_SCREEN);
	if (fail == 2)
		win_choose = dinamic_copy(ENDING);
	if (fail == 3)
		win_choose = dinamic_copy(GAME_OVER);
	mlx_destroy_window(mlx->init, mlx->win);
	free(mlx->img);
	mlx->img = NULL;
	mlx->img = mlx_xpm_file_to_image(&mlx->init, win_choose, &x, &x);
	mlx->win = mlx_new_window(mlx->init, 1000, 1000, "game!");
	// mlx_hook(mlx->win, 02, 1L << 0, key_hook_esc, &mlx);
	mlx_loop(mlx->init);
	if (key == 82)
		init_game(mlx);
	if (key == KEY_ESC)
		exit(EXIT_SUCCESS);
}
