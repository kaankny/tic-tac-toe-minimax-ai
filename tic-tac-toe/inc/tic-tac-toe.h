/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tic-tac-toe.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:09:03 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/12/27 16:56:28 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIC_TAC_TOE_H
# define TIC_TAC_TOE_H

# define WIDTH 600
# define HEIGHT 600

typedef struct s_board
{
	char	board[3][3];
}	t_board;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_board	board;
	int		game_over;
	void	*image;
	void	*x_image;
	void	*o_image;
	char	*addr;
	int		mouse_x;
	int		mouse_y;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_board(t_data *data);
int		close_program(t_data *data);
void	player_try_put(t_data *data);
void	draw_xox(t_data *data);
int		check_win(t_data *data);
int		get_random(int min, int max);
int		map_full(t_data *data);
int 	minimax(t_data *data, int depth, int isMaximizingPlayer);
void	print_winner(t_data *data);

#endif