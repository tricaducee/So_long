/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:18:03 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/23 23:18:56 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/so_long.h"

void	right_enemy(t_all *all, int i)
{
	if (all->enemy[i].x < all->map_size.x
		&& all->map[all->enemy[i].y][all->enemy[i].x + 1] == '0')
	{
		put_img(all, '0', all->enemy[i].x, all->enemy[i].y);
		all->map[all->enemy[i].y][all->enemy[i].x] = '0';
		all->enemy[i].x++;
		all->map[all->enemy[i].y][all->enemy[i].x] = 'X';
	}
	put_img_str(all, "./assets/enemy_right.xpm",
		all->enemy[i].x * 64, all->enemy[i].y * 64);
	if (all->map[all->enemy[i].y][all->enemy[i].x + 1] == 'P')
		life(all);
}

void	down_enemy(t_all *all, int i)
{
	if (all->enemy[i].y < all->map_size.y
		&& all->map[all->enemy[i].y + 1][all->enemy[i].x] == '0')
	{
		put_img(all, '0', all->enemy[i].x, all->enemy[i].y);
		all->map[all->enemy[i].y][all->enemy[i].x] = '0';
		all->enemy[i].y++;
		all->map[all->enemy[i].y][all->enemy[i].x] = 'X';
	}
	put_img_str(all, "./assets/enemy.xpm",
		all->enemy[i].x * 64, all->enemy[i].y * 64);
	if (all->map[all->enemy[i].y + 1][all->enemy[i].x] == 'P')
		life(all);
}

void	left_enemy(t_all *all, int i)
{
	if (all->enemy[i].x
		&& all->map[all->enemy[i].y][all->enemy[i].x - 1] == '0')
	{
		put_img(all, '0', all->enemy[i].x, all->enemy[i].y);
		all->map[all->enemy[i].y][all->enemy[i].x] = '0';
		all->enemy[i].x--;
		all->map[all->enemy[i].y][all->enemy[i].x] = 'X';
	}
	put_img_str(all, "./assets/enemy_left.xpm",
		all->enemy[i].x * 64, all->enemy[i].y * 64);
	if (all->map[all->enemy[i].y][all->enemy[i].x - 1] == 'P')
		life(all);
}

void	up_enemy(t_all *all, int i)
{
	if (all->enemy[i].y
		&& all->map[all->enemy[i].y - 1][all->enemy[i].x] == '0')
	{
		put_img(all, '0', all->enemy[i].x, all->enemy[i].y);
		all->map[all->enemy[i].y][all->enemy[i].x] = '0';
		all->enemy[i].y--;
		all->map[all->enemy[i].y][all->enemy[i].x] = 'X';
	}
	put_img_str(all, "./assets/enemy_up.xpm",
		all->enemy[i].x * 64, all->enemy[i].y * 64);
	if (all->map[all->enemy[i].y - 1][all->enemy[i].x] == 'P')
		life(all);
}
