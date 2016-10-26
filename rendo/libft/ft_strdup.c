/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 22:26:34 by schiad            #+#    #+#             */
/*   Updated: 2015/11/28 23:42:57 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char *s2;

	if ((s2 = (char *)malloc(ft_strlen(s1) + 1)))
		ft_strcpy(s2, s1);
	return (s2);
}
