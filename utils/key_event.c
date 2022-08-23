/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 05:09:59 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/23 22:33:14 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/so_long.h"

void	print_move(t_all *all)
{
	char	*str;

	put_img_str(all, "./assets/wall_moves.xpm", (all->map_size.x - 1) * 64, 0);
	str = itostr_base(all->move, "0123456789", 10);
	mlx_string_put(all->mlx, all->window, (all->map_size.x - 1) * 64 + 25, 36, 0xFFFFFF, str);
	free(str);
}

void	exit_on(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->map[i])
	{
		j = 0;
		while (all->map[i][j])
		{
			if (all->map[i][j] == 'E')
			{
				put_img_str(all, "./assets/exit_on.xpm", j * 64, i * 64);
				all->exit = 1;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	up_move(t_all *all)
{
	if (all->player.y && all->map[all->player.y - 1][all->player.x] == 'X')
		life(all);
	else if (all->player.y && all->map[all->player.y - 1][all->player.x] != '1')
	{
		if (all->map[all->player.y - 1][all->player.x] == 'E' && !all->exit)
			return ;
		else if (all->map[all->player.y - 1][all->player.x] == 'E')
			close_win(all);
		put_img(all, '0', all->player.x, all->player.y);
		all->map[all->player.y][all->player.x] = '0';
		all->player.y--;
		if (all->map[all->player.y][all->player.x] == 'C')
			all->coin++;
		all->map[all->player.y][all->player.x] = 'P';
		if (all->coin == all->total_coin && !all->exit)
			exit_on(all);
		all->move++;
		print_move(all);
	}
	put_img_str(all, "./assets/player_up.xpm", all->player.x * 64, all->player.y * 64);
}

void	down_move(t_all *all)
{
	if (all->player.y < all->map_size.y
		&& all->map[all->player.y + 1][all->player.x] == 'X')
		life(all);
	else if (all->player.y < all->map_size.y
		&& all->map[all->player.y + 1][all->player.x] != '1')
	{
		if (all->map[all->player.y + 1][all->player.x] == 'E' && !all->exit)
			return ;
		else if (all->map[all->player.y + 1][all->player.x] == 'E')
			close_win(all);
		put_img(all, '0', all->player.x, all->player.y);
		all->map[all->player.y][all->player.x] = '0';
		all->player.y++;
		if (all->map[all->player.y][all->player.x] == 'C')
			all->coin++;
		all->map[all->player.y][all->player.x] = 'P';
		if (all->coin == all->total_coin && !all->exit)
			exit_on(all);
		all->move++;
		print_move(all);
	}
	put_img_str(all, "./assets/player.xpm", all->player.x * 64, all->player.y * 64);
}

void	left_move(t_all *all)
{
	if (all->player.x < all->map_size.x
		&& all->map[all->player.y][all->player.x - 1] == 'X')
		life(all);
	else if (all->player.x < all->map_size.x
		&& all->map[all->player.y][all->player.x - 1] != '1')
	{
		if (all->map[all->player.y][all->player.x - 1] == 'E' && !all->exit)
			return ;
		else if (all->map[all->player.y][all->player.x - 1] == 'E')
			close_win(all);
		put_img(all, '0', all->player.x, all->player.y);
		all->map[all->player.y][all->player.x] = '0';
		all->player.x--;
		if (all->map[all->player.y][all->player.x] == 'C')
			all->coin++;
		all->map[all->player.y][all->player.x] = 'P';
		if (all->coin == all->total_coin && !all->exit)
			exit_on(all);
		all->move++;
		print_move(all);
	}
	put_img_str(all, "./assets/player_left.xpm", all->player.x * 64, all->player.y * 64);
}

void	right_move(t_all *all)
{
	if (all->player.x && all->map[all->player.y][all->player.x + 1] == 'X')
		life(all);
	else if (all->player.x && all->map[all->player.y][all->player.x + 1] != '1')
	{
		if (all->map[all->player.y][all->player.x + 1] == 'E' && !all->exit)
			return ;
		else if (all->map[all->player.y][all->player.x + 1] == 'E')
			close_win(all);
		put_img(all, '0', all->player.x, all->player.y);
		all->map[all->player.y][all->player.x] = '0';
		all->player.x++;
		if (all->map[all->player.y][all->player.x] == 'C')
			all->coin++;
		all->map[all->player.y][all->player.x] = 'P';
		if (all->coin == all->total_coin && !all->exit)
			exit_on(all);
		all->move++;
		print_move(all);
	}
	put_img_str(all, "./assets/player_right.xpm", all->player.x * 64, all->player.y * 64);
}

int	key_event(int keycode, t_all *all)
{
	(void)all;
	if (keycode == 126 || keycode == 13)
		up_move(all);
	if (keycode == 125 || keycode == 1)
		down_move(all);
	if (keycode == 123 || keycode == 0)
		left_move(all);
	if (keycode == 124 || keycode == 2)
		right_move(all);
	if (keycode == 53)
		close_win(all);
	printf("%d\n", keycode);
	printf("move : %d\n", all->move);
	printf("coin : %d\n", all->coin);
	printf("total coin : %d\n", all->total_coin);
	printf("exit : %d\n", all->exit);
	return (0);
}
