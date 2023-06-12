/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:49:41 by paescano          #+#    #+#             */
/*   Updated: 2022/12/03 11:11:22 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_num_words(char const *s, char c)
{
	size_t	nwords;

	nwords = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		nwords++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (nwords);
}

size_t	ft_length_word(char const *s, char c)
{
	size_t	length;

	length = 0;
	while (*s && *s != c)
	{
		s++;
		length++;
	}
	return (length);
}

char	*ft_strndup(const char *s, size_t x)
{
	size_t	i;
	char	*str;

	str = malloc(sizeof(char) * (x + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < x)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

void	ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	size_t	nwords;
	size_t	lwords;
	size_t	i;

	nwords = ft_num_words(s, c);
	strings = (char **)malloc(sizeof(char *) * (nwords + 1));
	if (!strings)
		return (NULL);
	i = 0;
	while (i < nwords)
	{
		while (*s && *s == c)
			s++;
		lwords = ft_length_word(s, c);
		strings[i] = ft_strndup(s, lwords);
		if (!strings[i])
			ft_free(strings);
		s += lwords;
		i++;
	}
	strings[nwords] = NULL;
	return (strings);
}
