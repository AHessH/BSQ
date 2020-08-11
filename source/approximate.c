/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   approximate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sronni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:49:25 by sronni            #+#    #+#             */
/*   Updated: 2020/02/25 15:01:51 by sronni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evaluate.h"

int			valid_lines(int begin, int square, int *head)
{
	int		flag;
	int		i;

	i = begin;
	flag = 1;
	while (i < begin + square && flag)
	{
		if (head[i] < square)
			flag = 0;
		i++;
	}
	return (flag);
}

int			check_polygon(int i, int j, char **field, t_bsq bsq)
{
	int		x;
	int		y;
	int		flag;

	x = i;
	flag = 1;
	while (x < i + bsq.square && flag)
	{
		y = j;
		while (y < j + bsq.square && flag)
		{
			if (field[x][y] == bsq.noize)
				flag = 0;
			y++;
		}
		x++;
	}
	return (flag);
}

int			paint_square(int i, int j, char **field, t_bsq bsq)
{
	int		x;
	int		y;

	x = i;
	while (x < i + bsq.square)
	{
		y = j;
		while (y < j + bsq.square)
		{
			field[x][y] = bsq.target;
			y++;
		}
		x++;
	}
	return (1);
}

int			scan_map(char **field, int square, int **head, t_bsq bsq)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	flag = 0;
	while (i + square <= bsq.y_hei && flag == 0)
	{
		if (valid_lines(i, square, head[1]))
		{
			j = 0;
			while (j + square <= bsq.x_len && flag == 0)
			{
				if (valid_lines(j, square, head[0]))
					flag = check_polygon(i, j, field, bsq);
				if (flag)
				{
					flag = paint_square(i, j, field, bsq);
				}
				j++;
			}
		}
		i++;
	}
	return (flag);
}

int			search_square(char **field, int **head, t_bsq bsq)
{
	int		flag;

	flag = 0;
	while (bsq.square > 0 && flag == 0)
	{
		flag = scan_map(field, bsq.square, head, bsq);
		if (flag == 0)
			bsq.square--;
	}
	return (bsq.square);
}
