/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 03:20:13 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/19 17:23:53 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct S_coor
{
	unsigned int	x;
	unsigned int	y; 
}					t_coor;

typedef struct S_all
{
	unsigned int	coin;
	unsigned int	total_coin;
	unsigned int	exit;
	unsigned int	life;
	unsigned int	move;
	unsigned int	frame;
	unsigned int	aleatory;
	int				fd;
	t_coor			*enemy;
	char			**map;
	void			*mlx;
	void			*window;
	t_coor			map_size;
	t_coor			player;
}					t_all;

int		read_map(t_all *all);
int		set_all(t_all *all);
int		map_gen(t_all *all);
int		put_img(t_all *all, char c, int x, int y);
int		player_position(t_all *all);
int		key_event(int keycode, t_all *all);
int		close_win(t_all *all);
void	check_map(t_all *all);
char	*itostr_base(unsigned int n, char *str, unsigned int base);
void	exit_error(t_all *all, char *str, int errnum);

#endif