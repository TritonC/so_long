/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:12:17 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/08/11 12:26:01 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*
void	*confirm_line(char *str)
{
	int	count;
	t_mlx mlx;

	count = 0;
	if (str[count] != '1' && str[count] != 'E' && str[count] != '0' &&
	str[count] != 'P' && str[count] != 'C')
		return ("wrong map");
	else
		{
			mlx.img = 
		}
}
*/

/*void	check_create_map(char *file, t_mlx *mlx)
{
	int		fd;
	char	*introduce;
	int		status;

	check_file_name(file);
	fd = open(file, O_RDONLY);
	introduce = get_next_line(fd);
	if (!check_f_l(introduce))
		free_write_exit("Error: map error\n", NULL, introduce, 1);
	mlx->coord.x = ft_strlen(introduce);
	mlx->coord.y = 0;
	mlx->map = NULL;
	status = 0;
	while (introduce)
	{
		mlx->map = realloc_double(mlx->map, introduce);
		if (!check_line(introduce, mlx->coord.x, &status))
			free_write_exit("Error: map error\n", mlx->map, NULL, 1);
		introduce = get_next_line(fd);
		(mlx->coord.y)++;
	}
	if (mlx->coord.y > 70 || status != 25
		|| !check_f_l((mlx->map)[mlx->dim.y - 1]))
		free_write_exit("Error: map error\n", mlx->map, NULL, 1);
	close(fd);
}
*/