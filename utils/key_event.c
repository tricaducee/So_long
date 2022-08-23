/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 05:09:59 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/19 17:45:22 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/so_long.h"

void	up_move(t_all *all)
{
	char	*str;

	if (all->player.y && all->map[all->player.y - 1][all->player.x] != '1')
	{
		if (all->map[all->player.y - 1][all->player.x] == 'E' && !all->exit)
			return ;
		else if (all->map[all->player.y - 1][all->player.x] == 'E')
			close_win(all);
		else if (all->map[all->player.y - 1][all->player.x] == 'X')
			close_win(all);
		put_img(all, '0', all->player.x * 64, all->player.y * 64 + 40);
		all->map[all->player.y][all->player.x] = '0';
		all->player.y--;
		if (all->map[all->player.y][all->player.x] == 'C')
			all->coin++;
		put_img(all, 'P', all->player.x * 64, all->player.y * 64 + 40);
		all->map[all->player.y][all->player.x] = 'P';
		if (all->coin == all->total_coin)
			all->exit = 1;
		str = itostr_base(all->move, "0123456789", 10);
		mlx_string_put(all->mlx, all->window, (all->map_size.x / 2) * 64, 30, 0x000000, str);
		free(str);
		all->move++;
		str = itostr_base(all->move, "0123456789", 10);
		mlx_string_put(all->mlx, all->window, (all->map_size.x / 2) * 64, 30, 0xFFFFFF, str);
		free(str);
	}
}

void	down_move(t_all *all)
{
	char	*str;

	if (all->player.y < all->map_size.y
		&& all->map[all->player.y + 1][all->player.x] != '1')
	{
		if (all->map[all->player.y + 1][all->player.x] == 'E' && !all->exit)
			return ;
		else if (all->map[all->player.y + 1][all->player.x] == 'E')
			close_win(all);
		else if (all->map[all->player.y + 1][all->player.x] == 'X')
			close_win(all);
		put_img(all, '0', all->player.x * 64, all->player.y * 64 + 40);
		all->map[all->player.y][all->player.x] = '0';
		all->player.y++;
		if (all->map[all->player.y][all->player.x] == 'C')
			all->coin++;
		put_img(all, 'P', all->player.x * 64, all->player.y * 64 + 40);
		all->map[all->player.y][all->player.x] = 'P';
		if (all->coin == all->total_coin)
			all->exit = 1;
		str = itostr_base(all->move, "0123456789", 10);
		mlx_string_put(all->mlx, all->window, (all->map_size.x / 2) * 64, 30, 0x000000, str);
		free(str);
		all->move++;
		str = itostr_base(all->move, "0123456789", 10);
		mlx_string_put(all->mlx, all->window, (all->map_size.x / 2) * 64, 30, 0xFFFFFF, str);
		free(str);
	}
}

void	left_move(t_all *all)
{
	char	*str;

	if (all->player.x < all->map_size.x
		&& all->map[all->player.y][all->player.x - 1] != '1')
	{
		if (all->map[all->player.y][all->player.x - 1] == 'E' && !all->exit)
			return ;
		else if (all->map[all->player.y][all->player.x - 1] == 'E')
			close_win(all);
		else if (all->map[all->player.y][all->player.x - 1] == 'X')
			close_win(all);
		put_img(all, '0', all->player.x * 64, all->player.y * 64 + 40);
		all->map[all->player.y][all->player.x] = '0';
		all->player.x--;
		if (all->map[all->player.y][all->player.x] == 'C')
			all->coin++;
		put_img(all, 'P', all->player.x * 64, all->player.y * 64 + 40);
		all->map[all->player.y][all->player.x] = 'P';
		if (all->coin == all->total_coin)
			all->exit = 1;
		str = itostr_base(all->move, "0123456789", 10);
		mlx_string_put(all->mlx, all->window, (all->map_size.x / 2) * 64, 30, 0x000000, str);
		free(str);
		all->move++;
		str = itostr_base(all->move, "0123456789", 10);
		mlx_string_put(all->mlx, all->window, (all->map_size.x / 2) * 64, 30, 0xFFFFFF, str);
		free(str);
	}
}

void	right_move(t_all *all)
{
	char	*str;

	if (all->player.x && all->map[all->player.y][all->player.x + 1] != '1')
	{
		if (all->map[all->player.y][all->player.x + 1] == 'E' && !all->exit)
			return ;
		else if (all->map[all->player.y][all->player.x + 1] == 'E')
			close_win(all);
		else if (all->map[all->player.y][all->player.x + 1] == 'X')
			close_win(all);
		put_img(all, '0', all->player.x * 64, all->player.y * 64 + 40);
		all->map[all->player.y][all->player.x] = '0';
		all->player.x++;
		if (all->map[all->player.y][all->player.x] == 'C')
			all->coin++;
		put_img(all, 'P', all->player.x * 64, all->player.y * 64 + 40);
		all->map[all->player.y][all->player.x] = 'P';
		if (all->coin == all->total_coin)
			all->exit = 1;
		str = itostr_base(all->move, "0123456789", 10);
		mlx_string_put(all->mlx, all->window, (all->map_size.x / 2) * 64, 30, 0x000000, str);
		free(str);
		all->move++;
		str = itostr_base(all->move, "0123456789", 10);
		mlx_string_put(all->mlx, all->window, (all->map_size.x / 2) * 64, 30, 0xFFFFFF, str);
		free(str);
	}
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
	//printf("move : %d\n", all->move);
	//printf("coin : %d\n", all->coin);
	//printf("total coin : %d\n", all->total_coin);
	//printf("exit : %d\n", all->exit);
	return (0);
}
