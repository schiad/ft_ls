/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 21:36:33 by schiad            #+#    #+#             */
/*   Updated: 2015/11/29 03:14:43 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		retour;
	size_t	i;

	i = 0;
	retour = 0;
	while ((s2[i] || s1[i]) && retour == 0 && i < n)
	{
		retour = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	return (retour);
}
