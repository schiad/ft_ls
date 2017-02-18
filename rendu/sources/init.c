/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 18:57:31 by schiad            #+#    #+#             */
/*   Updated: 2017/02/18 18:57:35 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	init_options(t_options *options)
{
	options->a = 0;
	options->l = 0;
	options->r = 0;
	options->s = 0;
	options->bigr = 0;
	options->t = 0;
}
