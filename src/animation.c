/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 00:30:14 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/04/02 13:01:03 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * It loads a series of images
 * from a file with a number at the end of it
 * 
 * @param mlx the t_mlx structure
 * @param images a pointer to a t_data structure.
 * @param file the name of the file, without the number.
 * @param frames the number of frames in the animation
 */
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

/**
 * It takes a t_data struct,
 * which contains a list of images, and displays the current frame of the animation
 * at the given coordinates
 * 
 * @param mlx The mlx structure
 * @param images The t_data structure that holds the images.
 * @param x x position of the image
 * @param y y position of the image
 */
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

/**
 * It checks if the player is on the same tile as the character, and if so, it puts the character on
 * top of the player
 * 
 * @param mlx the main structure
 * @param image the image to animate
 * @param coords the coordinates of the current tile
 */
void	check_char(t_mlx *mlx, t_data *image, t_coord coords)
{
	put_and_destroy(mlx, choose_filename(mlx, '0'), coords);
	image_animate(mlx, image, coords.x
		* 64, coords.y * 64);
	if (mlx->player.x == coords.x && mlx->player.y == coords.y)
		put_and_destroy(mlx, mlx->player.file, coords);
}

/**
 * It checks for the presence of a character in the map, and if it finds one, it calls the appropriate
 * function to handle it
 * 
 * @param mlx the main structure
 * @param c a t_coord struct that holds the x and y coordinates of the current position
 * @param enemy an array of size 1 that holds the number of enemies that have been
 */
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

/**
 * It checks if it's time to change the frame of the animation, and if so, it does so
 * 
 * @param mlx the main structure
 * 
 * @return 0.
 */
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
