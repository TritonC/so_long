/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:26:48 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/08/11 11:51:53 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_coord {
	int	x;
	int	y;
}				t_coord;

typedef struct s_data {
	void		*win;
	void		*init;
	void		*img;
	char		**map;
	int			movements;
	t_coord		coord;
}				t_mlx;

int	key_hook_esc(int key, t_mlx mlx);

#endif