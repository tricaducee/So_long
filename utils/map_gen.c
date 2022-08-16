/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 03:23:14 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/16 08:53:07 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/so_long.h"

int	map_gen(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->map[i])
	{
		j = 0;
		while (all->map[i][j] && all->map[i][j] != '\n')
		{
			if (put_img(all, all->map[i][j], j * 64, i * 64 + 40))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}