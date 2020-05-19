/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtristan <gtristan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 13:35:25 by gtristan          #+#    #+#             */
/*   Updated: 2019/10/09 14:47:22 by gtristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct		s_map
{
	int				x[4];
	int				y[4];
	int				i;
	int				f;
	struct s_map	*next_lev;
	struct s_map	*next_fig;
}					t_map;

void				ft_putchar(char c);
t_map				*remove_figs(t_map *shape, t_map *sh_move);
void				remove_figs1(t_map *shape, t_map *sh_move);
t_map				*select_positions(t_map *shape);
void				ft_restore_index(t_map *shape, t_map *sh_mov);
void				ft_restore_index1(t_map *shape);
t_map				*ft_dupl(t_map *shape0, t_map *shape, int pole_size);
void				finish_dupl(t_map *sh_mv, t_map *shape);
void				free_dupl(t_map *shape);
int					ft_find_max(int a, int b, int c, int d);
int					fill_square(t_map *shape, int pole_size);
void				print_figs(t_map *shape, int pole_size);
void				print_figs1(int pole_size, int **map);
int					min_square(t_map *sh);
int					check_same_figs(t_map *shape, t_map *sh_move);
int					ft_find_min(int a, int b, int c, int d);
int					check_connections(int arr[4][4]);
int					validate_input(char *str);
int					read_text(char *str);
char				*read_buf(char *str);
t_map				*get_map_root(void);
t_map				*new_map_fig(void);
int					include_value_into_map(int arr[][4]);
void				align_figs(t_map *sh);

#endif
