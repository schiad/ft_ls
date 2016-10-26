/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 19:11:51 by schiad            #+#    #+#             */
/*   Updated: 2015/12/04 00:33:59 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int		len;
	char				*ptr;

	ptr = NULL;
	if (f && s)
	{
		len = ft_strlen(s);
		if (!(ptr = ft_strnew(len)))
			return (NULL);
		len = 0;
		while (s[len])
		{
			ptr[len] = f(s[len]);
			len++;
		}
	}
	return (ptr);
}
