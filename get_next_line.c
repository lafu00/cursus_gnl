/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehlich <rehlich@student.42malaga.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 11:04:18 by rehlich           #+#    #+#             */
/*   Updated: 2026/10/22 11:54:33 by rehlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	to_print(char *line)
{

}

char	to_free(char	*line)
{

}

char	fill_line(int fd, char *line)
{
	int		buffer;
	char	*temp;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	buffer = 1;
	while (!ft_strchr(line,'\n') && buffer > 0)
	{
		buffer = read(fd, temp, BUFFER_SIZE)
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
	line = fill_line(fd, line)
	if (!line)
		return (NULL);
	out = to_print(line);
	line = to_free(line);
	return (out);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open(archivo.txt, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	printf("%s", line);
	close(fd);
	return (0);
}
