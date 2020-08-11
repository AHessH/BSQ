/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froxanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:27:35 by froxanne          #+#    #+#             */
/*   Updated: 2020/02/24 14:27:40 by froxanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_func.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str++);
	}
}

int		ft_atoi(char *str)
{
	int number;
	int is_negative;

	number = 0;
	is_negative = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		str++;
		is_negative = 1;
	}
	if (*str == '+')
		str++;
	while (*str)
		if (*str >= '0' && *str <= '9')
		{
			number *= 10;
			number += *str++ - '0';
		}
		else
			break ;
	if (is_negative)
		number *= -1;
	return (number);
}

int		ft_read(int file, void *data, int size)
{
	if ((read(file, data, size)) == -1)
		return (-1);
	return (1);
}

void	fast_print(char *array, t_bsq *bsq)
{
	write(1, array, bsq->x_len);
}
