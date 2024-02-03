/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdemiray <rdemiray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:03:58 by mogullar          #+#    #+#             */
/*   Updated: 2023/08/17 12:42:33 by rdemiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PL_XPM "./textures/char.xpm"
# define EX_XPM "./textures/exit.xpm"
# define C_XPM "./textures/coin.xpm"
# define WALL_XPM "./textures/white.xpm"
# define G_XPM "./textures/ground.xpm"

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*player;
	void	*exit;
	void	*wall;
	void	*collectable;
	void	*background;
	int		map_x;
	int		map_y;
	char	**map;
	char	**c_map;
	int		col_count;
	int		collectable_count_copy;
	int		exit_valid;
	int		player_collected;
	int		img_x;
	int		img_y;
	int		p_len;
	int		e_len;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		player_step;
	int		map_y_control;
	char	*player_step_screen;
}			t_data;

void		image_to_screen(t_data *data);
int			handle_key_press(int keycode, t_data *data);
void		get_map(t_data *data, char *map_name, char *str);
char		*get_next_line(int fd);
void		step_counter(t_data *data);
int			ft_strlen(char *string);
char		*ft_strdup(char *s1);
char		**ft_split(const char *s, char c);
char		*ft_strjoin(char *s1, char *s2);
void		element_check(t_data *data);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			find_player(t_data *data, char find);
void		is_rectangular(t_data *data);
void		image_to_screen(t_data *data);
void		image_initilize(t_data *data);
void		ft_error(char *msg, t_data *data);
char		*ft_itoa(int n);
void		invalid_mapname(char *mapname, t_data *data);
void		wall_okk(t_data *data);
int			another_coin(t_data *data);
int			ft_close_window(t_data *data);
void		step_counter(t_data *data);
char		ft_coordinat(int x, int y, t_data *data);
void		ft_exit(char *msg);
void		ft_putstr(char *str);

#endif
