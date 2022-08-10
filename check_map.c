/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:56:59 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/07/10 00:40:49 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**realloc_double(char **input, char *introduce)
{
	int		counter;
	char	**ret;

	counter = 0;
	while (input && input[counter])
		counter++;
	ret = malloc(sizeof(char *) * (counter + 2));
	if (!ret)
		free_write_exit("Error: malloc failed", input, introduce, 1);
	counter = 0;
	while (input && input[counter])
	{
		ret[counter] = input[counter];
		counter++;
	}
	if (input)
		free(input);
	ret[counter] = introduce;
	ret[counter + 1] = NULL;
	return (ret);
}

static int	check_f_l(char *str)
{
	int	counter;

	counter = 0;
	while (str && *str)
	{
		if (*str != '1')
			return (0);
		str++;
		counter++;
	}
	if (counter > 128)
		return (0);
	return (1);
}

//ret 0 if wrong line
static int	check_line(char *str, int len, int *sta)
{
	int	counter;

	counter = 0;
	if (*str != '1')
		return (0);
	while (*str)
	{
		if (*str != '0' && *str != '1' && *str != 'C'
			&& *str != 'E' && *str != 'P')
			return (0);
		if (*str == 'E')
			*sta += 1;
		else if (*str == 'P')
			*sta += 4;
		else if (*str == 'C' && *sta < 20)
			*sta += 20;
		if (*sta != 0 && *sta != 1 && *sta != 4 && *sta != 5
			&& *sta != 20 && *sta != 21 && *sta != 24 && *sta != 25)
			return (0);
		str++;
		counter++;
	}
	if (counter != len || *(str - 1) != '1')
		return (0);
	return (42);
}

//check file format *.ber
static void	check_file_name(char *file)
{
	int	counter;

	counter = 0;
	while (file[counter])
		counter++;
	if (counter < 4)
		free_write_exit("Error: incorrect extension\n", NULL, NULL, 1);
	counter -= 4;
	if (file[counter++] != '.')
		free_write_exit("Error: incorrect extension\n", NULL, NULL, 1);
	if (file[counter++] != 'b')
		free_write_exit("Error: incorrect extension\n", NULL, NULL, 1);
	if (file[counter++] != 'e')
		free_write_exit("Error: incorrect extension\n", NULL, NULL, 1);
	if (file[counter] != 'r')
		free_write_exit("Error: incorrect extension\n", NULL, NULL, 1);
}

//if fd wrong, gnl takes care :)
void	check_create_map(char *file, t_mlx *mlx)
{
	int		fd;
	char	*introduce;
	int		status;

	check_file_name(file);
	fd = open(file, O_RDONLY);
	introduce = get_next_line(fd);
	if (!check_f_l(introduce))
		free_write_exit("Error: map error\n", NULL, introduce, 1);
	mlx->dim.x = ft_strlen(introduce);
	mlx->dim.y = 0;
	mlx->map = NULL;
	status = 0;
	while (introduce)
	{
		mlx->map = realloc_double(mlx->map, introduce);
		if (!check_line(introduce, mlx->dim.x, &status))
			free_write_exit("Error: map error\n", mlx->map, NULL, 1);
		introduce = get_next_line(fd);
		(mlx->dim.y)++;
	}
	if (mlx->dim.y > 70 || status != 25
		|| !check_f_l((mlx->map)[mlx->dim.y - 1]))
		free_write_exit("Error: map error\n", mlx->map, NULL, 1);
	close(fd);
}
