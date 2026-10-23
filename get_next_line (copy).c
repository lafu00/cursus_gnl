/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehlich <rehlich@student.42malaga.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 11:04:18 by rehlich           #+#    #+#             */
/*   Updated: 2026/10/23 13:09:14 by rehlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

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

char	*fill_line(int fd, char *line)
{
	int		buffer;
	char	*temp;

	if (!line)
	{
		line = malloc(sizeof(char) * 1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
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

char	*to_print(char *line)
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

char	*to_free(char *line)
{
	char	*new_line;
	size_t	i;
	size_t	j;
	char	c;

	c = '\n';
	i = 0;
	j = 0;
	while (line[i] && line[i] != c)
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	new_line = ft_substr(line, i + 1, ft_strlen(line) - (i + 1));
	free(line);
	return (new_line);
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
	if (!out)
	{
		free(out);
		line = NULL;
		return (NULL);
	}
	line = to_free(line);
	return (out);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("archivo2.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
