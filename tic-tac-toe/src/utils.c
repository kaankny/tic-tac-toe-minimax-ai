/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:21:57 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/12/27 17:46:38 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../inc/tic-tac-toe.h"
#include "../mlx/mlx.h"

int	get_random(int min, int max)
{
	int	random;

	random = (rand() % (max - min + 1)) + min;
	return (random);
}

void	print_player_win()
{
	printf("██████╗ ██╗      █████╗ ██╗   ██╗███████╗██████╗     ██╗    ██╗██╗███╗   ██╗\n");
	printf("██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗    ██║    ██║██║████╗  ██║\n");
	printf("██████╔╝██║     ███████║ ╚████╔╝ █████╗  ██████╔╝    ██║ █╗ ██║██║██╔██╗ ██║\n");
	printf("██╔═══╝ ██║     ██╔══██║  ╚██╔╝  ██╔══╝  ██╔══██╗    ██║███╗██║██║██║╚██╗██║\n");
	printf("██║     ███████╗██║  ██║   ██║   ███████╗██║  ██║    ╚███╔███╔╝██║██║ ╚████║\n");
	printf("╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝     ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝\n");
}

void	print_enemy_win()
{
	printf(" █████╗ ██╗    ██╗    ██╗██╗███╗   ██╗\n");
	printf("██╔══██╗██║    ██║    ██║██║████╗  ██║\n");
	printf("███████║██║    ██║ █╗ ██║██║██╔██╗ ██║\n");
	printf("██╔══██║██║    ██║███╗██║██║██║╚██╗██║\n");
	printf("██║  ██║██║    ╚███╔███╔╝██║██║ ╚████║\n");
	printf("╚═╝  ╚═╝╚═╝     ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝\n");
}

void	print_winner(t_data *data)
{
	if (data->game_over == 1)
	{
		print_player_win();
		mlx_string_put(data->mlx_ptr, data->win_ptr, 250, 300, 0x00FF0000, "X WINS!");
	}
	else if (data->game_over == 2)
	{
		print_enemy_win();
		mlx_string_put(data->mlx_ptr, data->win_ptr, 250, 300, 0x00FF0000, "O WINS!");
	}
	else if (data->game_over == 3)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, 250, 300, 0x00FF0000, "DRAW!");
	}
}