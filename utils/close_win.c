/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 05:33:01 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/23 23:03:59 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/so_long.h"

int	close_win(t_all *all)
{
	int	i;

	i = 0;
	mlx_destroy_window(all->mlx, all->window);
	while (all->map[i])
		free(all->map[i++]);
	free(all->map);
	exit(0);
}
