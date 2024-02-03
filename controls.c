/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdemiray <rdemiray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:03:52 by mogullar          #+#    #+#             */
/*   Updated: 2023/08/17 11:50:17 by rdemiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_rectangular(t_data *data)
{
	int	i;
	int	line1_len;
	int	lenght;

	lenght = 0;
	i = 1;
	line1_len = ft_strlen(data->map[0]);
	data->map_x = line1_len;
	while (data->map[i])
	{
		lenght = ft_strlen(data->map[i]);
		if (lenght != line1_len)
			ft_error("Map is not rectangular", data);
		i++;
	}
	if (i != data->map_y_control)
		ft_error("Map is not rectangular", data);
	data->map_y = i;
}

void	invalid_mapname(char *mapname, t_data *data)
{
	int	lenght;
	int	i;

	i = 0;
	lenght = ft_strlen(mapname);
	if (mapname[lenght - 1] != 'r' || mapname[lenght - 2] != 'e' \
			|| mapname[lenght - 3] != 'b' || mapname[lenght - 4] \
			!= '.' || lenght <= 5)
		ft_error("invalid mapname", data);
	while (mapname[lenght] != '/')
		lenght--;
	if (mapname[lenght + 1] == '.')
		ft_error("invalid mapname", data);
}

void	element_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->col_count++;
			if (data->map[i][j] == 'P')
				data->p_len++;
			if (data->map[i][j] == 'E')
				data->e_len++;
			if (data->map[i][j] != 'C' && data->map[i][j] != 'P' \
			&& data->map[i][j] != '0' && data->map[i][j] != '1' \
			&& data->map[i][j] != 'E')
				ft_error("Invalid char", data);
			j++;
		}
		i++;
	}
	if ((data->col_count < 1) || (data->p_len != 1) || (data->e_len != 1))
		ft_error("There must be 1P, 1E and atleast 1C", data);
}

void	wall_okk(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->map_x)
	{
		if (data->map[0][x] != '1' || data->map[data->map_y - 1][x] != '1')
			ft_error("map is not surrounded by walls", data);
		x++;
	}
	while (y < data->map_y)
	{
		if (data->map[y][0] != '1' || data->map[y][data->map_x - 1] != '1')
			ft_error("map is not surrounded by walls", data);
		y++;
	}
}
