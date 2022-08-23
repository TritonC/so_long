/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 01:32:23 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/08/23 15:13:17 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <libft.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_name
{
	char	player[22];
}	t_name;

typedef struct s_data
{
	int		x;
	int		y;
	int		frame;
	char	*file;
}	t_data;
typedef struct s_mlx
{
	void		*init;
	void		*win;
	void		*img;
	char		**map;
	int			movements;
	t_data		player;
	t_coord		coord;
	t_name		name;
	t_coord		exit;
}				t_mlx;

void	check_create_map(char *file, t_mlx *mlx);
void	draw_map(t_mlx *mlx);
int		key_hook_esc(int key, t_mlx *mlx);
void	free_write_exit(const char *str, char **fr1, char *fr2, int e);
void	create_map(char *file, t_mlx *mlx);
void	img_name(t_mlx *mlx, char c, int pos);
void	*choose_img(void *mlx, char c);
void	put_img(t_mlx *mlx, t_data pos);
void	player_move(t_mlx *mlx);
void	map_clean(t_mlx *mlx, int x, int y);
int		exit_check(char **map);

# define PI 64
# ifdef OSX
#  define KEY_ESC 53
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_P 35
#  define KEY_PLUS 69
#  define KEY_C 8
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
# elif LINUX
#  define KEY_ESC 65307
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_P 112
#  define KEY_PLUS 43
#  define KEY_C 99
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
# else
#  define LINUX
#  define KEY_ESC 65307
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_P 112
#  define KEY_PLUS 61
#  define KEY_C 99
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100

# endif
#endif
