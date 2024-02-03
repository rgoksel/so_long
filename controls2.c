/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdemiray <rdemiray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:04:30 by mogullar          #+#    #+#             */
/*   Updated: 2023/08/16 21:11:39 by rdemiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	e_finder(t_data *data, int i, int j)
{
	data->exit_x = j;
	data->exit_y = i;
}

int	find_player(t_data *data, char find)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->player_x = j;
				data->player_y = i;
			}
			if (data->map[i][j] == 'E')
				e_finder(data, i, j);
			else if (data->c_map[i][j] == find || data->c_map[i][j] == find)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	unvalid_map(t_data *data, int x, int y)
{
	int		i;

	i = 0;
	if (data->c_map[y][x] == 'E')
	{
		data->exit_valid = 1;
		data->c_map[y][x] = '1';
	}
	if (data->c_map[y][x] == 'C')
	{
		data->collectable_count_copy++;
		data->c_map[y][x] = '0';
	}
	if (data->c_map[y][x] == '0' || data->c_map[y][x] == 'P')
	{
		data->c_map[y][x] = '.';
		unvalid_map(data, x, y + 1);
		unvalid_map(data, x, y - 1);
		unvalid_map(data, x + 1, y);
		unvalid_map(data, x - 1, y);
	}
	return ;
}

int	another_coin(t_data *data)
{
	find_player(data, 'P');
	unvalid_map(data, data->player_x, data->player_y);
	if (data->collectable_count_copy != data->col_count)
		ft_error("Can't access to coin", data);
	if (!data->exit_valid)
		ft_error("Can't access to exit", data);
	return (0);
}
