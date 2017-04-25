/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 19:29:44 by schiad            #+#    #+#             */
/*   Updated: 2017/04/25 19:04:02 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		len;
	char				*ptr;

	ptr = NULL;
	if (f && s)
	{
		len = ft_strlen(s);
		if (!(ptr = (char *)ft_memalloc(sizeof(char) * (len + 1))))
			return (NULL);
		len = 0;
		while (s[len])
		{
			ptr[len] = f(len, s[len]);
			len++;
		}
	}
	return (ptr);
}
