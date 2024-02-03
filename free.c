/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdemiray <rdemiray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:30:45 by rdemiray          #+#    #+#             */
/*   Updated: 2023/08/17 12:43:42 by rdemiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_exit(char *msg)
{
	write(1, "Error\n", 6);
	ft_putstr(msg);
	exit(1);
}

void	ft_error(char *msg, t_data *data)
{
	int	i;

	i = 0;
	write(1, "Error\n", 6);
	ft_putstr(msg);
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map[i]);
	exit(1);
}

int	ft_close_window(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map[i]);
	exit(0);
}
