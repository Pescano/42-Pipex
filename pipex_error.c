/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:39:07 by paescano          #+#    #+#             */
/*   Updated: 2022/11/19 18:40:28 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_exit(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_error_exit_manual(char *str)
{
	if (str)
	{
		while (*str)
			write(2, str++, 1);
	}
	write(2, "\n", 1);
}
