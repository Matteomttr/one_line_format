/* =====================================================
 * File        : get_next_line.h
 * Author      : Matteomttr
 * Date        : 2026
 * Description : header for gnl
 *
 * Copyright (c) 2026 Matteomttr. All rights reserved.
 * ===================================================== */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* Buffer size used by read(). */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* Inclusion of necessary libraries */
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

/* Function utils resumption of libft */
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);

/* Main function */
char	*get_next_line(int fd);

#endif
