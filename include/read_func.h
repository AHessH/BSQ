/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_func.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froxanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:32:04 by froxanne          #+#    #+#             */
/*   Updated: 2020/02/25 17:32:09 by froxanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_FUNC_H
# define READ_FUNC_H

# include <sys/stat.h>
# include <sys/errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_bsq
{
	int			x_len;
	int			y_hei;
	char		noize;
	char		space;
	char		target;
}				t_bsq;

void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_atoi(char *str);
char			**read_from_file(char *file_name, t_bsq *bsq, char **array);
int				ft_read(int file, void *data, int size);
int				feel_check_arr(char *array, int prev_j, t_bsq *bsq, int file);
char			**mem_allocation(int x, int y, char **str);
int				read_first_line(t_bsq *bsq);
char			*read_second_len(t_bsq *bsq);
char			**read_from_term(t_bsq *bsq, char **array);
void			fast_print(char *array, t_bsq *bsq);
#endif
