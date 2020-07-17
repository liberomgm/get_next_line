/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loscar <loscar@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 05:05:57 by loscar            #+#    #+#             */
/*   Updated: 2020/07/17 21:46:49 by loscar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_strchr(const char *s, int v);
char	*ft_strdup(const char *str);
char	*ft_strcpy(char *dest, char *src);
void	ft_strclr(char *s);
char	*ft_strnew(size_t size);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int     get_next_line(int fd, char **line);

#endif
