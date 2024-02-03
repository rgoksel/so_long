/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdemiray <rdemiray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:03:36 by mogullar          #+#    #+#             */
/*   Updated: 2023/08/17 12:40:55 by rdemiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	ft_coordinat(int x, int y, t_data *data)
{
	if (data->map[y][x] == 'C')
	{
		data->player_collected++;
	}
	else if (data->map[y][x] == 'E')
	{
		if (data->player_collected == data->col_count)
		{
			step_counter(data);
			ft_close_window(data);
		}
		return (0);
	}
	else if (data->map[y][x] == '1')
		return (0);
	return (1);
}

void	step_counter(t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	data->player_step++;
	str = ft_itoa(data->player_step);
	write(1, "STEP: ", 7);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	free(str);
}
