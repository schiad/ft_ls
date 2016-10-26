/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:10:40 by schiad            #+#    #+#             */
/*   Updated: 2015/11/29 04:46:29 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	int		ok;
	char	*found;

	i = 0;
	found = NULL;
	if (s2[0] == 0)
		return ((char *)s1);
	while (!found && s1[i] && i < n)
	{
		j = 0;
		ok = 1;
		while (s2[j] && ok)
		{
			if (s1[i + j] != s2[j] || ((j + i) >= n))
				ok = 0;
			j++;
		}
		if (ok)
			found = (char *)(s1 + i);
		i++;
	}
	return (found);
}
