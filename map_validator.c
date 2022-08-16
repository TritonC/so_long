/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:12:17 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/08/16 16:54:33 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**realloc_double(char **map, char *lane)
{
	int		count;
	char	**ret;

	count = 0;
	while (map && map[count])
		count++;
	ret = malloc(sizeof(char *) * (count + 2));
	if (!ret)
		free_write_exit("Error: malloc failed", map, lane, 1);
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

static int	check_first_last(char *lane)
{
	int	count;

	count = 0;
	while (lane && *lane)
	{
		if (*lane != '1')
			return (0);
		lane++;
		count++;
	}
	if (count > 128)
		return (0);
	return (1);
}

//ret 0 if wrong line
static int	check_line(char *lane, int len, int *log)
{
	int	count;

	count = 0;
	if (*lane != '1')
		return (0);
	while (*lane)
	{
		if (*lane != '0' && *lane != '1' && *lane != 'C'
			&& *lane != 'E' && *lane != 'P')
			return (0);
		if (*lane == 'E')
			*log += 1;
		else if (*lane == 'P')
			*log += 4;
		else if (*lane == 'C' && *log < 20)
			*log += 20;
		if (*log != 0 && *log != 1 && *log != 4 && *log != 5
			&& *log != 20 && *log != 21 && *log != 24 && *log != 25)
			return (0);
		lane++;
		count++;
	}
	if (count != len || *(lane - 1) != '1')
		return (0);
	return (42);
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

//if fd wrong, gnl takes care :)
void	check_create_map(char *file, t_mlx *mlx)
{
	int		fd;
	char	*lane;
	int		log_error;

	check_file_name(file);
	fd = open(file, O_RDONLY);
	lane = get_next_line(fd);
	if (!check_first_last(lane))
		free_write_exit("Error: map error\n", NULL, lane, 1);
	mlx->dim.x = ft_strlen(lane);
	mlx->dim.y = 0;
	mlx->map = NULL;
	log_error = 0;
	while (lane)
	{
		mlx->map = realloc_double(mlx->map, lane);
		if (!check_line(lane, mlx->dim.x, &log_error))
			free_write_exit("Error: map error\n", mlx->map, NULL, 1);
		lane = get_next_line(fd);
		(mlx->dim.y)++;
	}
	if (mlx->dim.y > 70 || log_error != 25
		|| !check_first_last((mlx->map)[mlx->dim.y - 1]))
		free_write_exit("Error: map error\n", mlx->map, NULL, 1);
	close(fd);
}
