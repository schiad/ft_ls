/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 21:15:47 by schiad            #+#    #+#             */
/*   Updated: 2015/11/29 05:01:03 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	retour;
	int i;

	i = 0;
	retour = 0;
	while ((*(unsigned char *)(s2 + i) ||
			(*(unsigned char *)(s1 + i))) && (retour == 0))
	{
		retour = *(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i);
		i++;
	}
	return (retour);
}
