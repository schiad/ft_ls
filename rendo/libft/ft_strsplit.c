/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 20:56:41 by schiad            #+#    #+#             */
/*   Updated: 2015/12/04 16:51:32 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

static int	ft_strclen(const char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static int	ft_countword(const char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != '\0'))
			word++;
		if (i == 0 && s[i] != c)
			word++;
		i++;
	}
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		word;
	int		i;

	i = 0;
	if (!s || !(void *)s)
		return (NULL);
	word = ft_countword(s, c);
	tab = (char **)ft_memalloc(sizeof(char *) * (word + 1));
	if (!tab)
		return (NULL);
	tab[word] = NULL;
	i = 0;
	while (i < word)
	{
		while (*s == c)
			s++;
		tab[i] = ft_strnew(ft_strclen(s, c));
		ft_strncpy(tab[i], s, ft_strclen(s, c));
		s += ft_strclen(s, c);
		i++;
	}
	return (tab);
}
