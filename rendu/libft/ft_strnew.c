/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:59:05 by schiad            #+#    #+#             */
/*   Updated: 2017/02/28 18:20:45 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	size_t		i;
	char		*ptr;

	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (ptr)
	{
		i = 0;
		while (i < size)
		{
			ptr[i] = '\0';
			i++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	else
		exit(1);
	return (NULL);
}
