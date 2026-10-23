/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_linebonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehlich <rehlich@student.42malaga.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 11:04:18 by rehlich           #+#    #+#             */
/*   Updated: 2026/10/23 11:02:51 by rehlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	to_print(char *line)
{
	char	*out;
	int		i;
	char	c;

	c = '\n';
	if (!line || !line[0])
		return (NULL);
	i = 0;
	while (line[i] && line[i] != c)
		i++;
	if (line[i] == c)
		out = malloc(sizeof(char) * (i + 2));
	else
		out = malloc(sizeof(char) * (i + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != c)
	{
		out[i] = line[i];
		i++;
	}
	if (line[i] == c)
	{
		out[i] = line[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

char	to_free(char *line)
{
	char	*new_line;
	int		i;
	int		j;
	char	c;

	c = '\n';
	i = 0;
	while (line[i] && line[i] != c)
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	/*	new_line = malloc(sizeof(char) * (ft_strlen(line) - i));
	if (!new_line)
	{
	free(line);
	return (NULL);
	}
	i++;
	j = 0;
	while(line[i + j])
	{
	new_line[j] = line[j + i];
	j++;
	}*/
	new_line = ft_substr(line, i, ft_strlen(line) - i);
	new_line[j] = '\0';
	free(line);
	return (new_line);
}

char	*ft_strjoin_free(char *line, char *temp)
{
	char	*new_line;

	if (!line)
	{
		line = (char *) malloc(sizeof(char) * 1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	if (!temp)
		return (NULL);
	new_line = ft_strjoin(line, temp);
	free(line);
	return (new_line);
}

char	fill_line(int fd, char *line)
{
	int		buffer;
	char	*temp;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	buffer = 1;
	while (!ft_strchr(line, '\n') && buffer > 0)
	{
		buffer = read(fd, temp, BUFFER_SIZE);
		if (buffer == -1)
		{
			free(temp);
			free(line);
			return (NULL);
		}
		temp[buffer] = '\0';
		line = ft_strjoin_free(line, temp);
	}
	free(temp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*out;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = fill_line(fd, line);
	if (!line)
		return (NULL);
	out = to_print(line);
	line = to_free(line);
	return (out);
}

int	main(void)
{
	int		fd1;
	int		fd2;
	int		*FD[MAX_SIZE];
	char	*line;

	fd1 = open("archivo.txt", O_RDONLY);
	fd2 = open("archivo2.txt", O_RDONLY);
	FD[0] = fd1;
	FD[1] = fd2;
	while (FD)
	{
		if (FD < 0)
			return (0);
		line = get_next_line(FD);
		printf("%s", line);
		FD++;
	}
	close(fd1);
	close(fd2);
	return (0);
}
