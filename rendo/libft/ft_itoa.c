/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:00:16 by schiad            #+#    #+#             */
/*   Updated: 2015/12/05 16:56:31 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_lenint(long n)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n || i == 0)
	{
		n = n / 10;
		len++;
		i++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*number;
	int		i;
	int		len;
	long	num;

	num = (long)n;
	len = ft_lenint(num);
	i = 0;
	if (!(number = (char *)ft_memalloc(len + 1)))
		return (NULL);
	if (n < 0)
	{
		num = -num;
		i++;
		number[0] = '-';
	}
	number[len] = '\0';
	while (len-- > i)
	{
		number[len] = num % 10 + '0';
		num = num / 10;
	}
	return (number);
}
