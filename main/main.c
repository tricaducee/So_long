/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:58:50 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/16 14:34:10 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/so_long.h"

void	print_tabs(char **strs)
{
	while (*strs)
		printf("%s", *(strs++));
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
	mlx_loop(all.mlx);
	//mlx_loop_hook(all.mlx, &animation);
	return (0);
}