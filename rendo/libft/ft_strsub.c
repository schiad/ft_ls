/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 19:21:34 by schiad            #+#    #+#             */
/*   Updated: 2015/12/04 01:40:17 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*newptr;
	size_t		i;

	if (s)
	{
		if (!(newptr = ft_strnew(len)))
			return (NULL);
		i = 0;
		while (i < len)
		{
			newptr[i] = s[i + start];
			i++;
		}
		newptr[i] = '\0';
		return (newptr);
	}
	return (NULL);
}
