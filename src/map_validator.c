/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:12:17 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/08/23 23:56:56 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static int	check_first_last(char *lane)
{
	int	count;

	count = 0;
	while (lane && lane[count])
	{
		if (lane[count] != '1' && lane[count] != '\n')
			return (0);
		count++;
	}
	if (count > 128)
		return (0);
	return (1);
}

char	**realloc_double(char **map, char *lane)
{
	int		count;
	char	**ret;

	count = 0;
	while (map && map[count])
		count++;
	ret = malloc(sizeof(char *) * (count + 2));
	if (!ret)
		free_write_exit("Error: map error\n", NULL, lane, 1);
	count = 0;
	while (map && map[count])
	{
		ret[count] = map[count];
		count++;
	}
	if (map)
		free(map);
	ret[count] = lane;
	ret[count + 1] = NULL;
	return (ret);
}

static int	check_line(char *lane, int len_lane)
{
	int	i;

	i = 0;
	if (lane[i] != '1')
		return (0);
	while (lane[i] && lane[i] != '\n')
	{
		if (lane[i] != '1' && lane[i] != 'E' && lane[i] != 'P'
			&& lane[i] != 'C' && lane[i] != '0')
			return (0);
		i++;
	}
	if (i != len_lane || lane[i - 1] != '1')
		return (0);
	return (1);
}

//check file format *.ber
static void	check_file_name(char *file)
{
	int	count;

	count = 0;
	while (file[count])
		count++;
	if (count < 4)
		free_write_exit("Error: incorrect extension\n", NULL, NULL, 1);
	count -= 4;
	if (file[count++] != '.')
		free_write_exit("Error: incorrect extension\n", NULL, NULL, 1);
	if (file[count++] != 'b')
		free_write_exit("Error: incorrect extension\n", NULL, NULL, 1);
	if (file[count++] != 'e')
		free_write_exit("Error: incorrect extension\n", NULL, NULL, 1);
	if (file[count] != 'r')
		free_write_exit("Error: incorrect extension\n", NULL, NULL, 1);
}

void	create_map(char *file, t_mlx *mlx)
{
	int		fd;
	char	*lane;

	check_file_name(file);
	fd = open(file, O_RDONLY);
	lane = get_next_line(fd);
	if (!check_first_last(lane))
		free_write_exit("Error: invalid file\n", NULL, lane, 1);
	mlx->coord.x = ft_strlen(lane) - 1;
	mlx->coord.y = 0;
	mlx->map = NULL;
	while (lane)
	{
		mlx->map = realloc_double(mlx->map, lane);
		if (!check_line(lane, mlx->coord.x))
			free_write_exit("Error: map error\n", mlx->map, NULL, 1);
		lane = get_next_line(fd);
		mlx->coord.y++;
	}
	if (mlx->coord.y > 72 || !check_first_last((mlx->map)[mlx->coord.y - 1]))
		free_write_exit("Error: map error\n", mlx->map, NULL, 1);
	close(fd);
}
