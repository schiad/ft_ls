/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 20:25:58 by schiad            #+#    #+#             */
/*   Updated: 2015/12/04 01:33:27 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*trimmed;

	i = 0;
	trimmed = NULL;
	if (s)
	{
		while (*s && (*s == '\n' || *s == '\t' || *s == ' '))
			s++;
		len = ft_strlen(s);
		while (len && ((s[len - 1] == '\n') ||
					(s[len - 1] == '\t') || (s[len - 1] == ' ')))
			len--;
		if (!(trimmed = (char *)ft_strnew(len)))
			return (NULL);
		while (i < len)
		{
			trimmed[i] = s[i];
			i++;
		}
		trimmed[i] = '\0';
	}
	return (trimmed);
}
