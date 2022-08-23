// 		// modulo = (all->enemy[i].x + all->enemy[i].y) % 5;
// 		// if (modulo == 0)
// 		// 	enemy_move_a(all, i);
// 		// else if (modulo == 1)
// 		// 	enemy_move_b(all, i);
// 		// else if (modulo == 2)
// 		// 	enemy_move_c(all, i);
// 		// else if (modulo == 3)
// 		// 	enemy_move_d(all, i);
// 		// else if (modulo == 4)
// 		// 	enemy_move_e(all, i);

// void	enemy_move_a(t_all *all, unsigned int i)
// {
// 		if (all->enemy[i].x < all->map_size.x && (all->map[all->enemy[i].y][all->enemy[i].x + 1] == '0' || all->map[all->enemy[i].y][all->enemy[i].x + 1] == 'P'))
// 			right_enemy(all, i);
// 		else if (all->enemy[i].y < all->map_size.y && (all->map[all->enemy[i].y + 1][all->enemy[i].x] == '0' || all->map[all->enemy[i].y + 1][all->enemy[i].x] == 'P'))
// 			down_enemy(all, i);		
// 		else if (all->enemy[i].y && (all->map[all->enemy[i].y - 1][all->enemy[i].x] == '0' || all->map[all->enemy[i].y - 1][all->enemy[i].x] == 'P'))
// 			up_enemy(all, i);
// 		else if (all->enemy[i].x && (all->map[all->enemy[i].y][all->enemy[i].x - 1] == '0' || all->map[all->enemy[i].y][all->enemy[i].x - 1] == 'P'))
// 			left_enemy(all, i);
// }

// void	enemy_move_b(t_all *all, unsigned int i)
// {
// 		if (all->enemy[i].y < all->map_size.y && (all->map[all->enemy[i].y + 1][all->enemy[i].x] == '0' || all->map[all->enemy[i].y + 1][all->enemy[i].x] == 'P'))
// 			down_enemy(all, i);		
// 		else if (all->enemy[i].y && (all->map[all->enemy[i].y - 1][all->enemy[i].x] == '0' || all->map[all->enemy[i].y - 1][all->enemy[i].x] == 'P'))
// 			up_enemy(all, i);
// 		else if (all->enemy[i].x && (all->map[all->enemy[i].y][all->enemy[i].x - 1] == '0' || all->map[all->enemy[i].y][all->enemy[i].x - 1] == 'P'))
// 			left_enemy(all, i);
// 		else if (all->enemy[i].x < all->map_size.x && (all->map[all->enemy[i].y][all->enemy[i].x + 1] == '0' || all->map[all->enemy[i].y][all->enemy[i].x + 1] == 'P'))
// 			right_enemy(all, i);
// }

// void	enemy_move_c(t_all *all, unsigned int i)
// {	
// 		if (all->enemy[i].y && (all->map[all->enemy[i].y - 1][all->enemy[i].x] == '0' || all->map[all->enemy[i].y - 1][all->enemy[i].x] == 'P'))
// 			up_enemy(all, i);
// 		else if (all->enemy[i].x && (all->map[all->enemy[i].y][all->enemy[i].x - 1] == '0' || all->map[all->enemy[i].y][all->enemy[i].x - 1] == 'P'))
// 			left_enemy(all, i);
// 		else if (all->enemy[i].x < all->map_size.x && (all->map[all->enemy[i].y][all->enemy[i].x + 1] == '0' || all->map[all->enemy[i].y][all->enemy[i].x + 1] == 'P'))
// 			right_enemy(all, i);
// 		else if (all->enemy[i].y < all->map_size.y && (all->map[all->enemy[i].y + 1][all->enemy[i].x] == '0' || all->map[all->enemy[i].y + 1][all->enemy[i].x] == 'P'))
// 			down_enemy(all, i);	
// }

// void	enemy_move_d(t_all *all, unsigned int i)
// {
// 		if (all->enemy[i].x && (all->map[all->enemy[i].y][all->enemy[i].x - 1] == '0' || all->map[all->enemy[i].y][all->enemy[i].x - 1] == 'P'))
// 			left_enemy(all, i);
// 		else if (all->enemy[i].x < all->map_size.x && (all->map[all->enemy[i].y][all->enemy[i].x + 1] == '0' || all->map[all->enemy[i].y][all->enemy[i].x + 1] == 'P'))
// 			right_enemy(all, i);
// 		else if (all->enemy[i].y < all->map_size.y && (all->map[all->enemy[i].y + 1][all->enemy[i].x] == '0' || all->map[all->enemy[i].y + 1][all->enemy[i].x] == 'P'))
// 			down_enemy(all, i);		
// 		else if (all->enemy[i].y && (all->map[all->enemy[i].y - 1][all->enemy[i].x] == '0' || all->map[all->enemy[i].y - 1][all->enemy[i].x] == 'P'))
// 			up_enemy(all, i);
// }

// void	enemy_move_e(t_all *all, unsigned int i)
// {
// 		if (all->enemy[i].x < all->map_size.x && (all->map[all->enemy[i].y][all->enemy[i].x + 1] == '0' || all->map[all->enemy[i].y][all->enemy[i].x + 1] == 'P'))
// 			right_enemy(all, i);
// 		else if (all->enemy[i].y < all->map_size.y && (all->map[all->enemy[i].y + 1][all->enemy[i].x] == '0' || all->map[all->enemy[i].y + 1][all->enemy[i].x] == 'P'))
// 			down_enemy(all, i);
// 		else if (all->enemy[i].x && (all->map[all->enemy[i].y][all->enemy[i].x - 1] == '0' || all->map[all->enemy[i].y][all->enemy[i].x - 1] == 'P'))
// 			left_enemy(all, i);	
// 		else if (all->enemy[i].y && (all->map[all->enemy[i].y - 1][all->enemy[i].x] == '0' || all->map[all->enemy[i].y - 1][all->enemy[i].x] == 'P'))
// 			up_enemy(all, i);
// }