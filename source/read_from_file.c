/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froxanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:16:29 by froxanne          #+#    #+#             */
/*   Updated: 2020/02/24 12:16:30 by froxanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_func.h"

char	**mem_allocation(int x, int y, char **str)
{
	int i;

	i = 0;
	if (!(str = (char **)malloc(sizeof(char *) * y)))
		return (0);
	while (i < y)
	{
		if (!(str[i] = (char *)malloc(sizeof(char) * (x + 1))))
			return (0);
		i++;
	}
	return (str);
}

int		feel_check_arr(char *array, int prev_j, t_bsq *bsq, int file)
{
	int		j;
	int		i;

	j = 0;
	j = read(file, array, bsq->x_len + 1);
	i = 0;
	while (i < j)
	{
		if (array[i] != bsq->noize && array[i] != bsq->space
			&& array[i] != '\n')
		{
			return (0);
		}
		i++;
	}
	array[j - 1] = '\0';
	if (prev_j != j)
		return (0);
	return (j);
}

char	**feeling_array(char **array, t_bsq *bsq, int file)
{
	int		i;
	char	buf;
	int		prev_j;

	i = -1;
	prev_j = bsq->x_len + 1;
	while (read(file, &buf, 1) && buf != '\n' && buf != '\r')
		;
	while (++i < bsq->y_hei)
	{
		prev_j = feel_check_arr(array[i], prev_j, bsq, file);
		if (prev_j == 0)
			return (0);
	}
	read(file, &buf, 1);
	if (buf != '\n' && buf != '\0')
		return (0);
	return (array);
}

int		create_bsq(t_bsq *bsq, int file, char *file_name)
{
	int		i;
	int		size_of_num;
	char	num[12];

	size_of_num = 0;
	i = 0;
	if (file == -1)
		return (0);
	while ((read(file, &num[i], 1)) && num[i] != '\n')
		i++;
	size_of_num = i - 3;
	i = 0;
	close(file);
	file = open(file_name, O_RDONLY);
	while ((read(file, &num[i], 1)) && i < size_of_num)
		i++;
	bsq->space = num[i];
	num[i] = '\0';
	if ((bsq->y_hei = ft_atoi(num)) <= 0)
		return (0);
	if ((ft_read(file, &(bsq->noize), sizeof(char))) == -1)
		return (0);
	if (ft_read(file, &(bsq->target), sizeof(char)) == -1)
		return (0);
	return (1);
}

char	**read_from_file(char *file_name, t_bsq *bsq, char **array)
{
	int		file;
	int		i;
	char	symbol;

	i = 0;
	if ((file = open(file_name, O_RDONLY)) == -1)
		return (0);
	if (!(create_bsq(bsq, file, file_name)))
		return (0);
	while (read(file, &symbol, 1) && (i == 0 || symbol != '\n'))
		bsq->x_len = i++;
	if (!(array = mem_allocation(bsq->x_len, bsq->y_hei, array)))
		return (0);
	close(file);
	file = open(file_name, O_RDONLY);
	if (!(array = feeling_array(array, bsq, file)))
		return (0);
	close(file);
	return (array);
}
