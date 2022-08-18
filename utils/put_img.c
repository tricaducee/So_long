/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 03:10:42 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/18 18:51:50 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/so_long.h"

int	put_img(t_all *all, char c, int x, int y)
{
	void	*img;
	int i[2];

	if (c == '1')
		img = mlx_xpm_file_to_image(all->mlx, "./assets/wall.xpm", i, i + 1);
	else if (c == '0')
		img = mlx_xpm_file_to_image(all->mlx, "./assets/floor.xpm", i, i + 1);
	else if (c == 'C')
		img = mlx_xpm_file_to_image(all->mlx, "./assets/coin.xpm", i, i + 1);
	else if (c == 'P')
		img = mlx_xpm_file_to_image(all->mlx, "./assets/player.xpm", i, i + 1);
	else if (c == 'E')
		img = mlx_xpm_file_to_image(all->mlx, "./assets/exit.xpm", i, i + 1);
	else if (c == 'X')
		img = mlx_xpm_file_to_image(all->mlx, "./assets/enemy.xpm", i, i + 1);
	else
		return (1);
	if (!img)
		return (1);
	mlx_put_image_to_window(all->mlx, all->window, img, x, y);
	mlx_destroy_image(all->mlx, img);
	return (0);
}
