/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_term.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froxanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:37:16 by froxanne          #+#    #+#             */
/*   Updated: 2020/02/25 20:37:18 by froxanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_func.h"

char	*copy_for_ar(char *temp, char buf, int temp_size)
{
	int		j;
	char	*array;

	j = 0;
	if (!(array = (char *)malloc(sizeof(char) * (temp_size + 1))))
		return (0);
	while (j < temp_size)
	{
		array[j] = temp[j];
		j++;
	}
	free(temp);
	array[j] = buf;
	return (array);
}

char	*read_second_len(t_bsq *bsq)
{
	int		i;
	int		sum;
	char	buf;
	char	*temp;

	temp = 0;
	sum = 0;
	buf = '1';
	while (buf != '\n')
	{
		i = read(0, &buf, 1);
		if (i == 0)
			return (0);
		if (!(temp = copy_for_ar(temp, buf, sum)))
			return (0);
		sum++;
	}
	temp[sum - 1] = '\0';
	bsq->x_len = sum - 1;
	return (temp);
}

int		read_first_line(t_bsq *bsq)
{
	char	num[20];
	int		i;
	int		num_size;

	i = 0;
	while ((read(0, &num[i], 1)) && num[i] != '\n')
		i++;
	num_size = i - 3;
	bsq->space = num[num_size];
	bsq->noize = num[num_size + 1];
	bsq->target = num[num_size + 2];
	i = 0;
	num[num_size] = '\0';
	if ((bsq->y_hei = ft_atoi(num)) < 1)
		return (-21);
	return (1);
}

char	**read_from_term(t_bsq *bsq, char **array)
{
	char	*arr;
	char	c;
	int		i;
	int		prev_j;

	i = -1;
	arr = 0;
	if (read_first_line(bsq) == -21)
		return (0);
	if (!(arr = read_second_len(bsq)))
		return (0);
	if (!(array = mem_allocation(bsq->x_len, bsq->y_hei, array)))
		return (0);
	while (++i <= bsq->x_len)
		array[0][i] = arr[i];
	i = 0;
	prev_j = bsq->x_len + 1;
	while (++i < bsq->y_hei)
		if (!(prev_j = feel_check_arr(array[i], prev_j, bsq, 0)))
			return (0);
	read(0, &c, 1);
	if (c != '\n' && c != '\0')
		return (0);
	return (array);
}
