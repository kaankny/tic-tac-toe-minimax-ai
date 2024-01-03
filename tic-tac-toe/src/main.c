/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:57:28 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/12/27 18:15:19 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/tic-tac-toe.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	close_program(t_data *data)
{
	printf("[\x1b[35mkAAn\x1b[0m] \x1b[33mExiting program\x1b[0m.. BYE!\n");
	mlx_destroy_image(data->mlx_ptr, data->image);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}

int	key_hook(int keycode, void *param)
{

	t_data	*data;

	data = (t_data *)param;
	if (data->game_over)
		return (0);
	if (keycode == 53)
		close_program(data);
	else if(keycode == 49)
	{
		mlx_mouse_get_pos(data->win_ptr, &data->mouse_x, &data->mouse_y);
		player_try_put(data);
	}
	printf("[\x1b[35mkAAn\x1b[0m] \x1b[33mKey pressed: %d\x1b[0m\n", keycode);
	return (0);
}

int	main()
{
	t_data	data;	
	int		x;
	int		y;

	x = 200;
	y = 200;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Hello World!");
	data.x_image = mlx_xpm_file_to_image(data.mlx_ptr, "images/x.xpm", &x, &y);
	data.o_image = mlx_xpm_file_to_image(data.mlx_ptr, "images/o.xpm", &x, &y);
	data.mouse_x = 0;
	data.game_over = 0;
	data.mouse_y = 0;
	data.board = (t_board){.board = {{' ', ' ', ' '}, {' ', ' ', ' '},
		{' ', ' ', ' '}}};
	draw_board(&data);
	mlx_key_hook(data.win_ptr, key_hook, &data);
	mlx_hook(data.win_ptr, 17, 0, close_program, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
