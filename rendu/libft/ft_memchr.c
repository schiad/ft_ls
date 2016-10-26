/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:00:55 by schiad            #+#    #+#             */
/*   Updated: 2015/11/29 04:35:33 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *p;

	p = (unsigned char *)s;
	if (n)
	{
		while (n)
		{
			if (*p == (unsigned char)c)
				return ((void *)(p));
			n--;
			p++;
		}
	}
	else
		return (NULL);
	return (NULL);
}
