/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 10:56:07 by schiad            #+#    #+#             */
/*   Updated: 2015/11/29 15:20:38 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	int		stop;

	i = 0;
	stop = 0;
	while (i < n && !stop)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		if (*(char *)(src + i) == c)
			stop = 1;
		i++;
	}
	return (stop ? (dest + i) : NULL);
}
