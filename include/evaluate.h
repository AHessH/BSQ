/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sronni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:42:05 by sronni            #+#    #+#             */
/*   Updated: 2020/02/25 22:04:29 by sronni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVALUATE_H
# define EVALUATE_H

# include <stdlib.h>
# include <unistd.h>
# include "read_from_file.h"
# include "ft_put.h"

typedef struct	s_max
{
	int		value;
	int		x;
	int		y;
}				t_max;

int				max(int a, int b);
int				min(int a, int b);
int				find_square(t_bsq bsq, char **field);

#endif
