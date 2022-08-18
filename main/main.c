/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:58:50 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/18 23:41:52 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/so_long.h"

// void	print_tabs(char **strs)
// {
// 	while (*strs)
// 		ft_printfd(1, "%s", *(strs++));
// }

void	right_enemy(t_all *all, int i)
{
	if (all->map[all->enemy[i].y][all->enemy[i].x + 1] == 'P')
		close_win(all);
	put_img(all, '0', all->enemy[i].x * 64, all->enemy[i].y * 64 + 40);
	all->map[all->enemy[i].y][all->enemy[i].x] = '0';
	all->enemy[i].x++;
	put_img(all, 'X', all->enemy[i].x * 64, all->enemy[i].y * 64 + 40);
	all->map[all->enemy[i].y][all->enemy[i].x] = 'X';
}

void	down_enemy(t_all *all, int i)
{
	if (all->map[all->enemy[i].y + 1][all->enemy[i].x] == 'P')
		close_win(all);
	put_img(all, '0', all->enemy[i].x * 64, all->enemy[i].y * 64 + 40);
	all->map[all->enemy[i].y][all->enemy[i].x] = '0';
	all->enemy[i].y++;
	put_img(all, 'X', all->enemy[i].x * 64, all->enemy[i].y * 64 + 40);
	all->map[all->enemy[i].y][all->enemy[i].x] = 'X';
}

void	left_enemy(t_all *all, int i)
{
	if (all->map[all->enemy[i].y][all->enemy[i].x - 1] == 'P')
		close_win(all);
	put_img(all, '0', all->enemy[i].x * 64, all->enemy[i].y * 64 + 40);
	all->map[all->enemy[i].y][all->enemy[i].x] = '0';
	all->enemy[i].x--;
	put_img(all, 'X', all->enemy[i].x * 64, all->enemy[i].y * 64 + 40);
	all->map[all->enemy[i].y][all->enemy[i].x] = 'X';
}

void	up_enemy(t_all *all, int i)
{
	if (all->map[all->enemy[i].y - 1][all->enemy[i].x] == 'P')
		close_win(all);
	put_img(all, '0', all->enemy[i].x * 64, all->enemy[i].y * 64 + 40);
	all->map[all->enemy[i].y][all->enemy[i].x] = '0';
	all->enemy[i].y--;
	put_img(all, 'X', all->enemy[i].x * 64, all->enemy[i].y * 64 + 40);
	all->map[all->enemy[i].y][all->enemy[i].x] = 'X';
}

int	animation(t_all *all)
{
	unsigned  int	i;

	i = 0;
	if (all->frame++ < 3000)
		return (0);
	while (all->enemy[i].x || all->enemy[i].y)
	{
		if (all->enemy[i].x < all->map_size.x && (all->map[all->enemy[i].y][all->enemy[i].x + 1] == '0' || all->map[all->enemy[i].y][all->enemy[i].x + 1] == 'P'))
			right_enemy(all, i);
		else if (all->enemy[i].y < all->map_size.y && (all->map[all->enemy[i].y + 1][all->enemy[i].x] == '0' || all->map[all->enemy[i].y + 1][all->enemy[i].x] == 'P'))
			down_enemy(all, i);
		else if (all->enemy[i].x && (all->map[all->enemy[i].y][all->enemy[i].x - 1] == '0' || all->map[all->enemy[i].y][all->enemy[i].x - 1] == 'P'))
			left_enemy(all, i);
		else if (all->enemy[i].y && (all->map[all->enemy[i].y - 1][all->enemy[i].x] == '0' || all->map[all->enemy[i].y - 1][all->enemy[i].x] == 'P'))
			up_enemy(all, i);
		i++;
	}
	all->frame = 0;
	return (0);
}

int	main(int ac, char **av)
{
	t_all	all;

	if (ac < 2)
		return (1);
	all.fd = open(av[1], O_RDONLY);
	if (!all.fd)
		return (1);
	if (set_all(&all))
		return (1);
	//print_tabs(all.map);
	mlx_key_hook(all.window, &key_event, &all);
	mlx_hook(all.window, 17, 0, &close_win, &all);
	mlx_loop_hook(all.mlx, &animation, &all);
	mlx_loop(all.mlx);
	return (0);
}