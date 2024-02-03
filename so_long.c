/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdemiray <rdemiray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:04:07 by mogullar          #+#    #+#             */
/*   Updated: 2023/08/17 12:40:24 by rdemiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_xpm_cont(t_data *data)
{
	int	fd;

	fd = open(PL_XPM, O_RDONLY);
	if (fd < 0)
		ft_error("CAN'T OPEN XPM", data);
	close(fd);
	fd = open(EX_XPM, O_RDONLY);
	if (fd < 0)
		ft_error("CAN'T OPEN XPM", data);
	close(fd);
	fd = open(C_XPM, O_RDONLY);
	if (fd < 0)
		ft_error("CAN'T OPEN XPM", data);
	close(fd);
	fd = open(WALL_XPM, O_RDONLY);
	if (fd < 0)
		ft_error("CAN'T OPEN XPM", data);
	close(fd);
	fd = open(G_XPM, O_RDONLY);
	if (fd < 0)
		ft_error("CAN'T OPEN XPM", data);
	close(fd);
}

void	ft_map(t_data *data, char *map)
{
	char	*str;

	str = NULL;
	data->p_len = 0;
	data->e_len = 0;
	get_map(data, map, str);
	free(str);
	invalid_mapname(map, data);
	element_check(data);
	is_rectangular(data);
	wall_okk(data);
	another_coin(data);
	ft_xpm_cont(data);
}

void	ft_win_and_hook(t_data *data)
{
	data->mlx = mlx_init();
	find_player(data, 'P');
	if (data->map_y > 20)
		ft_error("Map doesn't fit to screen", data);
	if (data->map_x > 40)
		ft_error("Map doesn't fit to screen", data);
	data->mlx_win = mlx_new_window(data->mlx, (data->map_x) * 64, \
	(data->map_y) * 64, "so_long");
	image_initilize(data);
	image_to_screen(data);
	mlx_hook(data->mlx_win, 17, 0L, &ft_close_window, data);
	mlx_hook(data->mlx_win, 2, 0, handle_key_press, data);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		data = malloc(sizeof(t_data));
		data->player_step = 0;
		data->collectable_count_copy = 0;
		data->col_count = 0;
		data->player_collected = 0;
		data->map_y_control = 0;
		ft_map(data, av[1]);
		ft_win_and_hook(data);
	}
	else
		ft_exit("Invalid argument count");
}
