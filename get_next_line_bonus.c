/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:52:23 by alfertah          #+#    #+#             */
/*   Updated: 2021/12/30 14:59:09 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(int fd, char *r)
{
	char	*buff;
	int		bytes_read;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytes_read = 1;
	while (!ft_strchr(r, '\n') && bytes_read)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buff);
			return (0);
		}
		buff[bytes_read] = '\0';
		r = ft_strjoin(r, buff);
	}
	free (buff);
	return (r);
}

char	*read_line(char *r)
{
	int		i;
	char	*line;

	i = 0;
	if (!r[i])
		return (0);
	while (r[i] != '\n' && r[i])
		i++;
	if (r[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (0);
	i = -1;
	while (r[++i] && r[i] != '\n')
		line[i] = r[i];
	if (r[i] == '\n')
	{
		line[i] = r[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_re(char *r)
{
	int		i;
	int		j;
	int		h;
	char	*p;

	i = 0;
	j = 0;
	while (r[i] != '\n' && r[i])
		i++;
	if (!r[i])
	{
		free (r);
		return (0);
	}
	h = (ft_strlen(r) - i);
	p = (char *)malloc(sizeof(char) * (h + 1));
	if (!p)
		return (0);
	i++;
	while (r[i])
		p[j++] = r[i++];
	p[j] = '\0';
	free (r);
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*r[1024];
	char		*line;

	if (fd < 0 && BUFFER_SIZE <= 0 && fd > 1024)
		return (0);
	r[fd] = ft_get_line(fd, r[fd]);
	if (!r[fd])
		return (NULL);
	line = read_line(r[fd]);
	r[fd] = ft_re(r[fd]);
	return (line);
}
/*int main()
{
	int a[4];
	a[0] = open("text.txt", O_CREAT | O_RDONLY, 777);
	a[1] = open("text.txt1", O_CREAT | O_RDONLY, 777);
	a[2] = open("text.txt2", O_CREAT | O_RDONLY, 777);
	a[3] = open("text.txt3", O_CREAT | O_RDONLY, 777);
	int i = 0;
	while(i < 4)
	{
		printf("%s",get_next_line(a[i]));
		printf("%s",get_next_line(a[i]));
		i++;
	}*/
