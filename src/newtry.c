/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newtry.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:38:59 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/12/02 13:49:03 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_coord	find_player(char **map, t_coord coord)
{
	coord.x = 0;
	while (map[coord.x])
	{
		coord.y = 0;
		while (map[coord.x][coord.y])
		{
			if (map[coord.x][coord.y] == 'P')
				return (coord);
			coord.y++;
		}
		coord.x++;
	}
	return (coord);
}

char	**map_cpy(char **map)
{
	char	**map_copy;
	int		j;
	int		i;

	j = 0;
	i = 0;
	while (map[i])
		i++;
	map_copy = (char **)malloc(sizeof(char *) * (i + 1) * 1);
	if (!map_copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		map_copy[i] = ft_calloc(sizeof(char), ft_strlen(map[i]) + 1);
		j = 0;
		while (map[i][j])
		{
			map_copy[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

char	**map_checker(char **map, int x, int y)
{
	if (map[y][x] == 'P')
	{
		if (map[y][x - 1] != '1' && map[y][x - 1] != 'P')
		{
			map[y][x - 1] = 'P';
			map_checker(map, x - 1, y);
		}
		if (map[y][x + 1] != '1' && map[y][x + 1] != 'P')
		{
			map[y][x + 1] = 'P';
			map_checker(map, x + 1, y);
		}
		if (map[y - 1][x] != '1' && map[y - 1][x] != 'P')
		{
			map[y - 1][x] = 'P';
			map_checker(map, x, y - 1);
		}
		if (map[y + 1][x] != '1' && map[y + 1][x] != 'P')
		{
			map[y + 1][x] = 'P';
			map_checker(map, x, y + 1);
		}
	}
	return (map);
}

int	map_evaluator(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	free_write_exit(NULL, map, NULL, -1);
	return (1);
}

// void	relaunch(t_mlx *mlx, int key, int fail)
// {
// 	char	*win_choose;
// 	int		x;

// 	if (fail == 1)
// 		win_choose = dinamic_copy(INIT_SCREEN);
// 	if (fail == 2)
// 		win_choose = dinamic_copy(ENDING);
// 	if (fail == 3)
// 		win_choose = dinamic_copy(GAME_OVER);
// 	mlx_destroy_window(mlx->init, mlx->win);
// 	free(mlx->img);
// 	mlx->img = NULL;
// 	mlx->img = mlx_xpm_file_to_image(&mlx->init, win_choose, &x, &x);
// 	mlx->win = mlx_new_window(mlx->init, 1000, 1000, "game!");
// 	// mlx_hook(mlx->win, 02, 1L << 0, key_hook_esc, &mlx);
// 	mlx_loop(mlx->init);
// 	if (key == 82)
// 		init_game(mlx);
// 	if (key == KEY_ESC)
// 		exit(EXIT_SUCCESS);
// }
