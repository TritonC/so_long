/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:31:29 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/08/30 20:03:23 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	enemy_count(char **map)
{
	t_coord		pos;
	int			count;

	count = 0;
	pos.x = -1;
	while (map[++pos.x])
	{
		pos.y = -1;
		while (map[pos.x][++pos.y])
		{
			if (ft_strchr("HV", map[pos.x][pos.y]))
				count++;
		}
	}
	return (count);
}

void	move_util(t_mlx *mlx, t_enemy *enemy, int dx, int dy)
{
	t_data	data;

	data = choose_data(mlx, dx, dy);
	if (!(enemy->pos.x - dx == mlx->player.x
			&& enemy->pos.y - dy == mlx->player.y))
		map_clean(mlx, enemy->pos.x - dx, enemy->pos.y - dy);
	if (!(enemy->pos.x + dx == mlx->player.x
			&& enemy->pos.y + dy == mlx->player.y))
		map_clean(mlx, enemy->pos.x + dx, enemy->pos.y + dy);
	if (ft_strchr("1ECLS", mlx->map[enemy->pos.y + dy][enemy->pos.x + dx]))
		enemy->addr = !enemy->addr;
	data.frame = enemy->frame % 3;
	image_animate(mlx, &data, enemy->pos.x * 64
		+ dx * (data.frame - 1) * 21, enemy->pos.y * 64
		+ dy * (data.frame - 1) * 21);
	enemy->frame++;
}

void	move_enemy(t_mlx *mlx, t_enemy *enemy)
{
	put_and_destroy(mlx, choose_filename(mlx, '0'), enemy->pos);
	if (mlx->player.x == enemy->pos.x && mlx->player.y == enemy->pos.y)
		put_and_destroy(mlx, mlx->player.file, enemy->pos);
	if (!enemy->addr && enemy->dir == 0)
		move_util(mlx, enemy, -1, 0);
	else if (enemy->addr && enemy->dir == 0)
		move_util(mlx, enemy, 1, 0);
	else if (!enemy->addr && enemy->dir == 1)
		move_util(mlx, enemy, 0, -1);
	else if (enemy->addr && enemy->dir == 1)
		move_util(mlx, enemy, 0, 1);
	if (enemy->pos.x == mlx->player.x && enemy->pos.y == mlx->player.y)
	{
		printf("you die");
		exit(EXIT_SUCCESS);
	}
	if (enemy->frame % 3 == 0 && !enemy->addr && enemy->dir == 0)
		enemy->pos.x--;
	if (enemy->frame % 3 == 0 && enemy->addr && enemy->dir == 0)
		enemy->pos.x++;
	if (enemy->frame % 3 == 0 && !enemy->addr && enemy->dir == 1)
		enemy->pos.y--;
	if (enemy->frame % 3 == 0 && enemy->addr && enemy->dir == 1)
		enemy->pos.y++;
	if (enemy->pos.x == mlx->player.x && enemy->pos.y == mlx->player.y)
	{
		printf("you die");
		exit(EXIT_SUCCESS);
	}
}

void	enemy_data(t_enemy *enemy, int dir, t_coord pos)
{
	enemy->frame = 0;
	enemy->pos.x = pos.y;
	enemy->pos.y = pos.x;
	enemy->dir = dir;
	enemy->addr = 1;
}

t_enemy	*enemy_init(char **map)
{
	t_enemy	*enemies;
	t_coord	pos;
	int		count;

	count = 0;
	enemies = malloc(sizeof(t_enemy) * enemy_count(map));
	pos.x = -1;
	while (map[++pos.x])
	{
		pos.y = -1;
		while (map[pos.x][++pos.y])
		{
			if (ft_strchr("H", map[pos.x][pos.y]))
				enemy_data(&enemies[count++], 0, pos);
			else if (ft_strchr("V", map[pos.x][pos.y]))
				enemy_data(&enemies[count++], 1, pos);
		}
	}
	return (enemies);
}
