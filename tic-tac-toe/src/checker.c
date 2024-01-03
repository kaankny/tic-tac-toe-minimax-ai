/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:18:17 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/12/27 18:01:38 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tic-tac-toe.h"

int	check_win(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		if (data->board.board[i][j] == data->board.board[i][j + 1] && data->board.board[i][j] == data->board.board[i][j + 2] && data->board.board[i][j] != ' ')
			return (1);
		i++;
	}
	i = 0;
	j = 0;
	while (j < 3)
	{
		if (data->board.board[i][j] == data->board.board[i + 1][j] && data->board.board[i][j] == data->board.board[i + 2][j] && data->board.board[i][j] != ' ')
			return (1);
		j++;
	}
	if (data->board.board[0][0] == data->board.board[1][1] && data->board.board[0][0] == data->board.board[2][2] && data->board.board[0][0] != ' ')
		return (1);
	if (data->board.board[0][2] == data->board.board[1][1] && data->board.board[0][2] == data->board.board[2][0] && data->board.board[0][2] != ' ')
		return (1);
	return (0);
}

int	map_full(t_data *data)
{
	return (0);
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		if (data->board.board[i][j] == ' ')
			return (0);
		i++;
	}
	i = 0;
	j = 0;
	while (j < 3)
	{
		if (data->board.board[i][j] == ' ')
			return (0);
		j++;
	}
	return (1);
}
