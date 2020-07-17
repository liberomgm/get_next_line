/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loscar <loscar@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 09:17:48 by student           #+#    #+#             */
/*   Updated: 2020/07/17 21:46:15 by loscar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

char *ft_strnew(size_t size)
{
	char *str;
	
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

void ft_strclr(char *s)
{
	if (s)
		while (*s)
			*s++ = '\0';
}

char *check_remainder(char *remainder, char **line)
{
	char *p_n;
	
	p_n = NULL;
	if (remainder)
	{
		if ((p_n = ft_strchr(remainder, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup(remainder);
			remainder = ft_strdup(++p_n);
		}
		else
		{
			*line = ft_strdup(remainder);
			ft_strclr(remainder);
		}
	}
	else
		*line = ft_strdup("");
	return (p_n);
}

int get_next_line(int fd, char **line)
{
	static char *remainder;
	char buf[BUFFER_SIZE + 1];
	int byte_was_read;
	char *p_n;
	char *tmp;
	
	p_n = check_remainder(remainder, line);
	while (!p_n && (byte_was_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[byte_was_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			remainder = ft_strdup(++p_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line, (char*)buf);
		free(tmp);
	}
	return ((remainder == NULL) ? 0 : 1);
}

int main(void)
{
char *line;
int fd;

fd = open("text.txt", O_RDONLY);
get_next_line(fd, &line);
printf("%s\n", line);
get_next_line(fd, &line);
printf("%s\n", line);
get_next_line(fd, &line);
printf("%s\n", line);
get_next_line(fd, &line);
printf("%s\n", line);
get_next_line(fd, &line);
printf("%s\n", line);
return (0);
}