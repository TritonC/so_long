/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:31:29 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/04/02 13:06:49 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * It counts the number of enemies on the map
 * 
 * @param map The map
 * 
 * @return The number of enemies on the map.
 */
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

/**
 * It moves the enemy in the
 * direction specified by the parameters, and animates the movement
 * 
 * @param mlx the main structure
 * @param enemy the enemy that is moving
 * @param dx the x-axis direction of the enemy's movement
 * @param dy the direction the enemy is moving in the y axis
 */
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

/**
 * It moves the enemy
 * 
 * @param mlx the main structure
 * @param enemy the enemy that is moving
 */
static void	move_asset(t_mlx *mlx, t_enemy *enemy)
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
}

/**
 * It moves the enemy
 * 
 * @param mlx the main structure
 * @param enemy the enemy to move
 */
void	move_enemy(t_mlx *mlx, t_enemy *enemy)
{
	move_asset(mlx, enemy);
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
		printf("you die\n");
		exit(EXIT_SUCCESS);
	}
	enemy++;
}

/**
 * It takes a map and returns an array of enemies
 * 
 * @param map The map that we're going to be using to find the enemies.
 * 
 * @return An array of t_enemy structs.
 */
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
