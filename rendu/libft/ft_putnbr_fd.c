/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 19:58:49 by schiad            #+#    #+#             */
/*   Updated: 2016/03/21 10:27:21 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
		long long ncp;

		ncp = (long long)n;
		if (ncp < 0)
		{
				ft_putchar_fd('-', fd);
				ncp = -ncp;
		}
		ft_putdigit_fd(ncp, fd);
}
