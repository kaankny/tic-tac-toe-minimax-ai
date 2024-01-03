/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:18:53 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/12/27 16:50:35 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tic-tac-toe.h"
#include "../mlx/mlx.h"
#include <math.h>
#include <stdio.h>

void	draw_line(int x1, int x2, int y1, int y2, t_data *data)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;

	delta_x = x2 - x1;
	delta_y = y2 - y1;
	pixels = sqrt(((x2 - x1) * (x2 - x1))
			+ ((y2 - y1) * (y2 - y1)));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = x1;
	pixel_y = y1;
	while (pixels)
	{
		my_mlx_pixel_put(data, pixel_x, pixel_y, 0x00FFFFFF);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}

void draw_circle(int x, int y, int r, t_data *data)
{
      static const double PI = 3.1415926535;
      double i, angle, x1, y1;

      for(i = 0; i < 360; i += 0.1)
      {
            angle = i;
            x1 = r * cos(angle * PI / 180);
            y1 = r * sin(angle * PI / 180);
            my_mlx_pixel_put(data->mlx_ptr, x + x1, y + y1, 0x00FFFFFF);
      }
}	

void	draw_xox(t_data *data)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;
	while (x < 3)
	{
		y = 0;
		while (y < 3)
		{
			if (data->board.board[x][y] == 'X')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->x_image, x * 200, y * 200);
				// draw_line(x * 200, (x + 1) * 200, y * 200, (y + 1) * 200, data);
				// draw_line((x + 1) * 200, x * 200, y * 200, (y + 1) * 200, data);
			}
			else if (data->board.board[x][y] == 'O')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->o_image, x * 200, y * 200);
			++y;
		}
		++x;
	}
}

void	draw_board(t_data *data)
{
	data->image = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->image, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	draw_line(200, 200, 0, 600, data);
	draw_line(400, 400, 0, 600, data);
	draw_line(0, 600, 200, 200, data);
	draw_line(0, 600, 400, 400, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, 0, 0);
	draw_xox(data);
}
