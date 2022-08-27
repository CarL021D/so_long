/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 23:31:38 by caboudar          #+#    #+#             */
/*   Updated: 2022/08/27 13:24:23 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"	

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_swap(char *a, char *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_putnbr(int nb)
{
	long int	l;

	l = nb;
	if (l >= 10)
	{
		ft_putnbr(l / 10);
		ft_putnbr(l % 10);
	}
	else
	{
		l += 48;
		write(1, &l, 1);
	}
}

char	*ft_fill_arr(unsigned int value, int i, int neg)
{
	char	*res;

	res = malloc(sizeof(char) * (i + neg + 1));
	if (!res)
		return (NULL);
	res[i + neg] = '\0';
	if (!neg)
		i--;
	while (i >= 0)
	{
		res[i] = (value % 10) + 48;
		i--;
		value /= 10;
	}
	if (neg)
		res[0] = '-';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		value;
	int		neg_s;

	i = 1;
	value = n;
	neg_s = 0;
	if (n < 0)
	{
		value = -n;
		neg_s = 1;
	}
	while (n >= 10 || n <= -10)
	{
		i++;
		n /= 10;
	}
	res = ft_fill_arr(value, i, neg_s);
	return (res);
}
