/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:39:05 by paescano          #+#    #+#             */
/*   Updated: 2022/11/26 19:44:09 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>

/**
 * @brief print an error and finish the program
 * 
 * @param str string to print in error exit
 */
void	ft_error_exit(char *str);
/**
 * @brief prints a custom error and finish the program
 * 
 * @param str string to print in error exit
 */
void	ft_error_exit_manual(char *str);
/**
 * @brief Split a pointer into pieces delimited by char returning all pieces
 * 
 * @param s string pointer
 * @param c character delimiter
 * @return char** 
 */
char	**ft_split(char const *s, char c);
/**
 * @brief free memory from a char **
 * 
 * @param strs char** we want to be free
 */
void	ft_free(char **strs);
/**
 * @brief Combine strings into one string
 * 
 * @param s1 path of the system
 * @param s2 comand
 * @return char* 
 */
char	*ft_strjoin(char *s1, char *s2);
/**
 * @brief 
 * extracts the path from the system and saves it in a char pointer pointer
 * 
 * @param envp 
system variables
 * @return char** paths
 */
char	**ft_path_from_envp(char **envp);
/**
 * @brief Compares the two strings s1 and s2. it only compares 
the first (at most) n bytes of s1 and s2.
 * 
 * @param s1 string 1
 * @param s2 string 2
 * @param n lengh
 * @return int result of the comparation
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
/**
 * @brief copies n bytes from memory area src to
memory area dest.  The memory areas may overlap: copying takes
place as though the bytes in src are first copied into a
temporary array that does not overlap src or dest, and the bytes
are then copied from the temporary array to dest.
 * 
 * @param dest 
 * @param src 
 * @param n 
 * @return void* 
 */
void	*ft_memcpy(void *dest, void *src, size_t n);
/**
 * @brief Return a size of any string
 * 
 * @param s string
 * @return size_t 
 */
size_t	ft_strlen(const char *s);

#endif