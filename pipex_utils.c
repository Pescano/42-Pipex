/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:02:46 by paescano          #+#    #+#             */
/*   Updated: 2022/12/03 12:32:15 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	char	*odest;
	char	*osrc;
	size_t	i;

	i = 0;
	odest = (char *)dest;
	osrc = (char *)src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		*(odest + i) = *(osrc + i);
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
		i = 0;
	else
		i = ft_strlen(s1);
	if (!s2)
		j = 0;
	else
		j = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (j + i + 2));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, i);
	str[i] = '/';
	ft_memcpy(str + i + 1, s2, j);
	str[j + i + 1] = '\0';
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	x;

	x = 0;
	while (x < n)
	{
		if (s1[x] == s2[x] && (s1[x] || s2[x]))
			x++;
		else
			return ((unsigned char)s1[x] - (unsigned char)s2[x]);
	}
	return (0);
}

char	**ft_path_from_envp(char **envp)
{
	char	**paths;

	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	paths = ft_split(*envp + 5, ':');
	if (!paths)
		ft_error_exit("ERROR no path");
	return (paths);
}
