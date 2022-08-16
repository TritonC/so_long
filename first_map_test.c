/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_map_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:24:58 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/08/16 14:47:53 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*print_img(void *mlx)
{
	char	*line;

	line = "111111111111";
	while (*line)
	{
		img_to_show(mlx, *line);
		line++;
	}
	return (0);
}

int	main(int agrc, char **agrv)
{
	t_mlx	mlx;
	int		fd;
	int		lanes;
	char	*str;

	if (agrc > 2)
		return (0);
	fd = open(agrv[1], O_RDONLY);
	str = get_next_line(fd);
	lanes = 0;
	mlx.init = mlx_init();
	mlx.coord.x = 128;
	mlx.coord.y = 72;
	mlx.win = mlx_new_window(mlx.init, mlx.coord.x * 20, mlx.coord.y * 20,
			"so_long_failure");
	draw_map(mlx);
	mlx_key_hook(mlx.win, key_hook_esc, mlx.init);
	mlx_loop(mlx.init);
}
