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

char	fill_line(int fd, char *line)
{
	int		buffer;
	char	*temp;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	buffer = 1;
	while (line != '\n' && buffer < 0)
	{
		temp = read(fd, buffer, BUFFER_SIZE)
		if (!temp)
			return (NULL);
	}
	char	*get_next_line(int fd)
	{
		static char	*line;
		char		*out;

		if ((fd < 0) && (BUFFER_SIZE <= 0))
			return (NULL);
		line = fill_line(fd, line)
		if (!line)
			return (NULL);
		out = to_print(line);
		line = rest(line);
		return (out);
	}
	int	main(void)
	{
		int		fd;
		char	*line;

		fd = open(archivo.txt, O_RDONLY);
		if (fd > 0)
		{
			get_next_line(fd);
		}
		printf("%s", line);
		close(fd);
		return (0);
	}
