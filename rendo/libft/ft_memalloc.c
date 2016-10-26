/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 15:25:44 by schiad            #+#    #+#             */
/*   Updated: 2015/12/01 20:53:24 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}
