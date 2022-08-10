/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:19:40 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/07/10 00:56:36 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fish(t_mlx mlx)
{
	t_coor	cnt;

	cnt.y = 0;
	while (++cnt.y < mlx.dim.y)
	{
		cnt.x = 0;
		while (++cnt.x < mlx.dim.x)
			if (mlx.map[cnt.y][cnt.x] == 'C')
				return (42);
	}
	return (0);
}

//direction 0 up, 1 rigth, 2 down, 3 left
//return 3 if over
int	move(t_coor player_pos, int direction, t_mlx *mlx, char p)
{
	char	next;
	t_coor	new_player_pos;

	new_player_pos.x = player_pos.x;
	new_player_pos.y = player_pos.y;
	if (direction == 0)
		new_player_pos.y--;
	else if (direction == 1)
		new_player_pos.x++;
	else if (direction == 2)
		new_player_pos.y++;
	else
		new_player_pos.x--;
	next = (mlx->map)[new_player_pos.y][new_player_pos.x];
	if (next == '0' || next == 'C')
	{
		(mlx->map)[new_player_pos.y][new_player_pos.x] = p;
		(mlx->map)[player_pos.y][player_pos.x] = '0';
		draw_map(*mlx);
		return (1);
	}
	else if (next == 'E')
		if (!fish(*mlx))
			return (3);
	return (0);
}

t_coor	get_player_pos(t_mlx *mlx)
{
	t_coor	player;

	player.y = 0;
	while (++player.y < mlx->dim.y)
	{
		player.x = 0;
		while (++player.x < mlx->dim.x)
			if ((mlx->map)[player.y][player.x] == 'P'
				|| (mlx->map)[player.y][player.x] == 'R'
				|| (mlx->map)[player.y][player.x] == 'L'
				|| (mlx->map)[player.y][player.x] == 'B')
				return (player);
	}
	return (player);
}

int	keypress(int keycode, t_mlx *mlx)
{
	t_coor	player_pos;
	int		mov_pre;

	if (keycode == 53)
		close_win(mlx);
	player_pos = get_player_pos(mlx);
	mov_pre = mlx->movements;
	if (keycode == 13)
		mlx->movements += move(player_pos, 0, mlx, 'B');
	else if (keycode == 0)
		mlx->movements += move(player_pos, 3, mlx, 'L');
	else if (keycode == 1)
		mlx->movements += move(player_pos, 2, mlx, 'P');
	else if (keycode == 2)
		mlx->movements += move(player_pos, 1, mlx, 'R');
	if (mov_pre != mlx->movements)
	{
		write(1, "Number of movements = ", 22);
		ft_putnbr(mov_pre + 1);
		write(1, "\n", 1);
	}
	if (mov_pre + 3 == mlx->movements)
		close_win(mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
		free_write_exit("Error: incorrect number of arguments\n", NULL, NULL, 1);
	check_create_map(argv[1], &mlx);
	mlx.init = mlx_init();
	mlx.win = mlx_new_window(mlx.init,
			mlx.dim.x * 20, mlx.dim.y * 20, "so_long");
	draw_map(mlx);
	mlx_hook(mlx.win, 17, 0b100, close_win, &mlx);
	mlx_key_hook(mlx.win, keypress, &mlx);
	mlx_loop(mlx.init);
}
