/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_map_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:24:58 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/08/11 12:42:04 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*print_img(t_mlx mlx, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (*line)
	{
		img_to_show(mlx.img, *line);
		line++;
	}
}

int	main(int agrc,char **agrv)
{
	t_mlx	mlx;

	mlx.init = mlx_init();
	mlx.win = mlx_new_window(mlx.init, 1920, 1080, "so_long_failure");
	mlx.img = print_img(mlx, agrv[0][2]);
	mlx_put_image_to_window(mlx.init, mlx.win, mlx.img, mlx.coord.x, mlx.coord.y);
	mlx_key_hook(mlx.win, key_hook_esc, mlx.init);
	mlx_loop(mlx.init);
	return (0);
}
