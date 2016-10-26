/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:28:38 by schiad            #+#    #+#             */
/*   Updated: 2015/11/29 03:44:52 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *temp;

	temp = (char *)malloc(len * sizeof(char));
	ft_memcpy(temp, src, len);
	ft_memcpy(dst, temp, len);
	free(temp);
	return (dst);
}
