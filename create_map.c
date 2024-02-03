/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdemiray <rdemiray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:04:43 by mogullar          #+#    #+#             */
/*   Updated: 2023/08/16 21:11:43 by rdemiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_initilize(t_data *data)
{
	int	img_w;
	int	img_h;

	data->player = mlx_xpm_file_to_image(data->mlx, PL_XPM, &img_w, &img_h);
	data->exit = mlx_xpm_file_to_image(data->mlx, EX_XPM, &img_w, &img_h);
	data->wall = mlx_xpm_file_to_image(data->mlx, WALL_XPM, &img_w, &img_h);
	data->collectable = mlx_xpm_file_to_image(data->mlx, C_XPM, &img_w, &img_h);
	data->background = mlx_xpm_file_to_image(data->mlx, G_XPM, &img_w, &img_h);
}

void	image_to_screen2(t_data *data, int y, int x)
{
	if (data->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, x * 64,
			y * 64);
	if (data->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit, x * 64, y
			* 64);
	if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall, x * 64, y
			* 64);
	if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->background, x
			* 64, y * 64);
	if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->collectable, x
			* 64, y * 64);
}

void	image_to_screen(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= data->map_y - 1)
	{
		x = 0;
		while (x <= data->map_x - 1)
		{
			image_to_screen2(data, y, x);
			x++;
		}
		y++;
	}
}
