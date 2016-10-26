/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 20:09:41 by schiad            #+#    #+#             */
/*   Updated: 2015/12/04 16:10:32 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*joined;

	joined = NULL;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if (!(joined = (char *)ft_memalloc(len + 1)))
			return (NULL);
		ft_strcpy(joined, s1);
		ft_strcat(joined, s2);
	}
	return (joined);
}
