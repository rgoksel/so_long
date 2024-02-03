/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdemiray <rdemiray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:10:28 by mogullar          #+#    #+#             */
/*   Updated: 2023/08/17 12:40:47 by rdemiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_right(t_data *data, int y, int x)
{
	data->map[y][x] = '0';
	data->map[y][x + 1] = 'P';
	data->player_x = x + 1;
	step_counter(data);
}

void	ft_left(t_data *data, int y, int x)
{
	data->map[y][x] = '0';
	data->map[y][x - 1] = 'P';
	data->player_x = x - 1;
	step_counter(data);
}

void	ft_up(t_data *data, int y, int x)
{
	data->map[y][x] = '0';
	data->map[y + 1][x] = 'P';
	data->player_y = y + 1;
	step_counter(data);
}

void	ft_down(t_data *data, int y, int x)
{
	data->map[y][x] = '0';
	data->map[y - 1][x] = 'P';
	data->player_y = y - 1;
	step_counter(data);
}

int	handle_key_press(int keycode, t_data *data)
{
	int	x;
	int	y;

	x = data->player_x;
	y = data->player_y;
	if (keycode == 53)
		ft_close_window(data);
	if (keycode == 2 && ft_coordinat(x + 1, y, data))
		ft_right(data, y, x);
	else if (keycode == 0 && ft_coordinat(x - 1, y, data))
		ft_left(data, y, x);
	else if (keycode == 1 && ft_coordinat(x, y + 1, data))
		ft_up(data, y, x);
	else if (keycode == 13 && ft_coordinat(x, y - 1, data))
		ft_down(data, y, x);
	image_to_screen(data);
	return (0);
}
