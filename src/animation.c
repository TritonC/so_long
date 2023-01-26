/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 00:30:14 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/01/26 11:23:11 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	images_load(t_mlx *mlx, t_data *images, char *file, int frames)
{
	int		x;
	int		i;
	int		len;

	images->max = frames;
	images->file = dinamic_copy(file);
	len = ft_strlen(file) + 1;
	images->images = malloc(sizeof(void *) * (frames + 1));
	i = -1;
	while (++i <= frames)
	{
		images->file[len - 6] = '0' + i % 10;
		images->file[len - 7] = '0' + i / 10;
		images->images[i] = mlx_xpm_file_to_image(&mlx->init,
				images->file, &x, &x);
	}
}

void	image_animate(t_mlx *mlx, t_data *images, int x, int y)
{
	if (images->frame < 0 || images->frame > images->max)
		images->frame = 0;
	mlx_put_image_to_window(mlx->init, mlx->win,
		images->images[images->frame], x, y);
	if (images->frame < images->max)
		images->frame++;
	else
		images->frame = 0;
}

void	check_char(t_mlx *mlx, t_data *image, t_coord coords)
{
	put_and_destroy(mlx, choose_filename(mlx, '0'), coords);
	image_animate(mlx, image, coords.x
		* 64, coords.y * 64);
	if (mlx->player.x == coords.x && mlx->player.y == coords.y)
		put_and_destroy(mlx, mlx->player.file, coords);
}

static void	an_utils(t_mlx *mlx, t_coord c, int *enemy)
{
	if (mlx->map[c.y][c.x] == 'C')
	{
		check_char(mlx, &mlx->ball, c);
		mlx->ball.frame--;
	}
	else if (mlx->map[c.y][c.x] == 'S' && !(mlx->time % 4000))
		check_char(mlx, &mlx->sta_enemy, c);
	else if (ft_strchr("HV", mlx->map[c.y][c.x])
		&& !(mlx->time % 3000))
		move_enemy(mlx, &mlx->enemies[enemy[0]++]);
}

int	animations(t_mlx *mlx)
{
	t_coord	c;
	int		enemy;

	c.x = 0;
	enemy = 0;
	if (!(mlx->time % 1000))
	{
		while (++c.x < mlx->coord.x)
		{
			c.y = -1;
			while (++c.y < mlx->coord.y)
				an_utils(mlx, c, &enemy);
		}
		mlx->h_enemy.frame++;
		mlx->r_enemy.frame++;
		mlx->ball.frame++;
	}
	mlx->time++;
	return (0);
}
