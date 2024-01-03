/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:30:15 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/12/27 17:48:42 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tic-tac-toe.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../mlx/mlx.h"

void	place(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image);
	data->image = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	draw_board(data);

}

void	player_place(t_data *data)
{
	int	x;
	int	y;

	x = data->mouse_x / (WIDTH / 3);
	y = data->mouse_y / (HEIGHT / 3);
	data->board.board[(int)x][(int)y] = 'X';
	place(data);
	if (check_win(data))
	{
		data->game_over = 1;
		print_winner(data);
	}
}

void	ai_place(t_data *data)
{
	int	bestMove;

	bestMove = minimax(data, 0, 1);
	data->board.board[bestMove / 3][bestMove % 3] = 'O';
	place(data);
	if (check_win(data))
	{
		data->game_over = 2;
		print_winner(data);
	}

}

int	check_valid_place(t_data *data)
{
	int	x;
	int	y;

	x = data->mouse_x / (WIDTH / 3);
	y = data->mouse_y / (HEIGHT / 3);
	if (data->board.board[(int)x][(int)y] == ' ')
		return (1);
	return (0);
}

void	player_try_put(t_data *data)
{
	if (data->game_over)
		return ;
	if (map_full(data))
	{
		data->game_over = 3;
		return ;
	}
	if (!check_valid_place(data))
		return ;
	player_place(data);
	if (data->game_over)
		return ;
	if (!map_full(data))
		ai_place(data);
}
