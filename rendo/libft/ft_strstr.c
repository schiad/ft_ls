/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:21:02 by schiad            #+#    #+#             */
/*   Updated: 2015/11/29 05:03:10 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		ok;
	char	*found;

	if (!s2[0])
		return ((char *)s1);
	i = 0;
	found = NULL;
	while (!found && s1[i])
	{
		j = 0;
		ok = 1;
		while (s2[j] && ok)
		{
			if (s1[i + j] != s2[j])
				ok = 0;
			j++;
		}
		if (ok)
			found = (char *)(s1 + i);
		i++;
	}
	return (found);
}
