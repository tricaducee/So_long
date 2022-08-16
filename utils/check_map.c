/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 05:56:11 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/16 07:11:31 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/so_long.h"

int	format_check(t_all *all)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	i = 0;
	j = 0;
	while (all->map[i][j])
		j++;
	if (j < 5)
		return (1);
	len = j;
	i++;
	while (all->map[i])
	{
		j = 0;
		while (all->map[i][j])
			j++;
		if (j != len)
			return (1);
		i++;
	}
	if (i < 4)
		return (1);
	return (0);
}

void	check_map(t_all *all)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	player;

	i = 0;
	player = 0;
	all->exit = 0;
	while (all->map[i])
	{
		j = 0;
		while (all->map[i][j])
		{
			if (all->map[i][j] == 'C')
				all->total_coin++;
			if (all->map[i][j] == 'P')
				player++;
			if (all->map[i][j++] == 'E')
				all->exit++;
		}
		i++;
	}
	if (all->exit != 1 || player != 1 || all->total_coin < 1)
		exit_error(all, "Error\nIl ni a pas le bon nombres d'items\n", 1);
	if (format_check(all))
		exit_error(all, "Error\nMauvais format\n", 1);
}