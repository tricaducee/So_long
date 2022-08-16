/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:58:46 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/16 08:51:47 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/so_long.h"
#include "../HEADER/get_next_line.h"

unsigned int	ft_strslen(char **ss)
{
	unsigned int	i;

 	i = 0;
	while (ss[i])
		i++;
	return (i);
}

int	set_all(t_all *all)
{
	if (read_map(all))
		return (1);
	all->total_coin = 0;
	check_map(all);
	all->coin = 0;
	all->exit = 0;
	all->move = 0;
	if (player_position(all))
		return (1);
	all->mlx = mlx_init();
	if (!all->mlx)
		return (1);
	all->map_size.x = ft_strlen(all->map[0]) - 1;
	all->map_size.y = ft_strslen(all->map);
	all->window = mlx_new_window(all->mlx, all->map_size.x * 64, all->map_size.y * 64 + 40, "so_long");
	if (!all->window)
		return (1);
	if (map_gen(all))
		return (1);
	return (0);
}