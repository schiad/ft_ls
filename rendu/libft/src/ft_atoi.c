/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 21:22:19 by schiad            #+#    #+#             */
/*   Updated: 2017/04/25 19:02:43 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	unsigned int	retour;
	int				minus;

	i = 0;
	minus = 0;
	retour = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\v' || str[i] == '\r' || str[i] == ' ' ||
			str[i] == '\f')
		str++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		retour = retour * 10;
		retour = retour + (str[i] - '0');
		i++;
	}
	return ((minus == 1) ? -retour : retour);
}
