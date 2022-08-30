/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 01:32:23 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/08/30 20:43:20 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <libft.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# define LADDER "./asset/ladder.xpm"
# define STONE "./asset/stone.xpm"
# define FLOOR "./asset/tile00.xpm"
# define WALL "./asset/tile01.xpm"

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_data
{
	void	**images;
	t_coord	pos;
	int		dir;
	int		x;
	int		y;
	int		max;
	int		frame;
	char	*file;
	int		time;
}	t_data;

typedef struct s_enemy
{
	t_coord	pos;
	int		dir;
	int		addr;
	int		frame;
}	t_enemy;

typedef struct s_mlx
{
	void		*init;
	void		*win;
	void		*img;
	char		**map;
	int			time;
	int			move;
	t_data		player;
	t_coord		coord;
	t_coord		exit;
	t_data		ball;
	t_data		sta_enemy;
	t_data		h_enemy;
	t_data		r_enemy;
	t_data		u_enemy;
	t_data		d_enemy;
	t_enemy		*enemies;
}				t_mlx;

void	check_create_map(char *file, t_mlx *mlx);
void	move_enemy(t_mlx *mlx, t_enemy *enemy);
void	draw_map(t_mlx *mlx);
int		key_hook_esc(int key, t_mlx *mlx);
int		enemy_count(char **map);
void	free_write_exit(const char *str, char **fr1, char *fr2, int e);
void	create_map(char *file, t_mlx *mlx);
void	img_name(t_mlx *mlx, char c, int pos, int frame_max);
void	*choose_img(void *mlx, char c);
void	put_img(t_mlx *mlx, t_data pos);
void	player_move(t_mlx *mlx);
t_data	choose_data(t_mlx *mlx, int x, int y);
void	map_clean(t_mlx *mlx, int x, int y);
int		exit_check(char **map);
void	player_west(t_mlx *mlx, int key);
void	player_south(t_mlx *mlx, int key);
void	player_north(t_mlx *mlx, int key);
void	player_east(t_mlx *mlx, int key);
int		animations(t_mlx *mlx);
void	put_and_destroy(t_mlx *mlx, char *file, t_coord coords);
char	*choose_filename(t_mlx *mlx, char c);
char	*dinamic_copy(char *file);
t_enemy	*enemy_init(char **map);
void	img_name_animation(t_data *data, int pos);
void	images_load(t_mlx *mlx, t_data *images, char *file, int frames);
void	image_animate(t_mlx *mlx, t_data *images, int x, int y);
void	img_name_animation(t_data *data, int pos);

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
