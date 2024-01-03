/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimax.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:32:19 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/12/27 18:06:28 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tic-tac-toe.h"
#include <math.h>
#include <stdio.h>

int	isGameOver(t_data *data)
{
	if (check_win(data))
		return (1);
	if (map_full(data))
		return (1);
	return (0);
}

int eve(t_data *data) {
    int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		if (data->board.board[i][j] == data->board.board[i][j + 1] && data->board.board[i][j] == data->board.board[i][j + 2] && data->board.board[i][j] != ' ')
		{
            if (data->board.board[i][j] == 'X')
                return (-1);
            else
                return (1);
        }
		i++;
	}
	i = 0;
	j = 0;
	while (j < 3)
	{
		if (data->board.board[i][j] == data->board.board[i + 1][j] && data->board.board[i][j] == data->board.board[i + 2][j] && data->board.board[i][j] != ' ')
		{
            if (data->board.board[i][j] == 'X')
                return (-1);
            else
                return (1);
        }
		j++;
	}
	if (data->board.board[0][0] == data->board.board[1][1] && data->board.board[0][0] == data->board.board[2][2] && data->board.board[0][0] != ' ')
	{
        if (data->board.board[0][0] == 'X')
            return (-1);
        else
            return (1);
    }
	if (data->board.board[0][2] == data->board.board[1][1] && data->board.board[0][2] == data->board.board[2][0] && data->board.board[0][2] != ' ')
    {
        if (data->board.board[0][2] == 'X')
            return (-1);
        else
            return (1);
    }
    return (0);
}

int minimax(t_data *data, int depth, int isMaximizingPlayer)
{
	if (isGameOver(data))
		return (eve(data));
    if (isMaximizingPlayer) {
        int bestScore = -1000;
	    int bestMove = -1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (data->board.board[i][j] == ' ') {
                    data->board.board[i][j] = 'O';
                    int score = minimax(data, depth + 1, 0);
                    data->board.board[i][j] = ' ';
                    if (score > bestScore) {
                        bestScore = score;
						bestMove = i * 3 + j;
                    }
                }
            }
        }

        return bestMove;
    } else {
        int bestScore = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (data->board.board[i][j] == ' ') {
                    data->board.board[i][j] = 'X';
                    int score = minimax(data, depth + 1, 1);
                    data->board.board[i][j] = ' ';

                    if (score < bestScore) {
                        bestScore = score;
                    }
                }
            }
        }

        return bestScore;
    }
}

