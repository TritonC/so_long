/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:20:11 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/08/10 16:10:57 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"
# include <string.h>

typedef struct s_coor
{
	int	x;
	int	y;
}	t_coor;

typedef struct s_mlx
{
	void	*init;
	void	*win;
	char	**map;
	int		movements;
	t_coor	dim;
}				t_mlx;

void	free_write_exit(const char *str, char **fr1, char *fr2, int e);
void	check_create_map(char *file, t_mlx *mlx);
int		ft_strlen(const char *str);
void	draw_map(t_mlx mlx);
void	ft_putnbr(int n);
int		close_win(t_mlx *mlx);

#endif