/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eureca.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sronni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:58:28 by sronni            #+#    #+#             */
/*   Updated: 2020/02/25 22:39:33 by sronni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluate.h"

int			is_target(char c, char tar)
{
	if (c == tar)
		return (0);
	return (1);
}

void		correct_field(char **field, t_max maxsize, t_bsq bsq)
{
	int		i;
	int		j;

	i = maxsize.y + 1 - maxsize.value;
	while (i <= maxsize.y)
	{
		j = maxsize.x + 1 - maxsize.value;
		while (j <= maxsize.x)
		{
			field[i][j] = bsq.target;
			j++;
		}
		i++;
	}
}

t_max		max_store(t_max maxsize, int val, int x, int y)
{
	if (maxsize.value < val)
	{
		maxsize.value = val;
		maxsize.x = x;
		maxsize.y = y;
	}
	return (maxsize);
}

t_max		create_matrix(t_bsq bsq, char **field, short int **shadow,
	t_max maxsize)
{
	short int	*line;
	int			i;
	int			j;

	i = 0;
	while (i < bsq.y_hei)
	{
		line = (short int *)malloc(sizeof(line) * bsq.x_len);
		j = 0;
		while (j < bsq.x_len)
		{
			if (j++ == 0 || i == 0)
				line[j - 1] = is_target(field[i][j - 1], bsq.noize);
			else if (is_target(field[i][j - 1], bsq.noize) == 0)
				line[j - 1] = 0;
			else
				line[j - 1] = min(line[j - 2], min(shadow[i - 1][j - 1],
					shadow[i - 1][j - 2])) + 1;
			maxsize = max_store(maxsize, line[j - 1], j - 1, i);
		}
		shadow[i++] = line;
	}
	return (maxsize);
}

int			find_square(t_bsq bsq, char **field)
{
	short int	**shadow;
	t_max		maxsize;

	maxsize.value = 0;
	shadow = (short int **)malloc(sizeof(shadow) * bsq.y_hei);
	maxsize = create_matrix(bsq, field, shadow, maxsize);
	correct_field(field, maxsize, bsq);
	free(shadow);
	return (maxsize.value);
}
