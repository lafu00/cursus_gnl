/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehlich <rehlich@student.42malaga.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 10:46:00 by rehlich           #+#    #+#             */
/*   Updated: 2026/10/23 10:55:43 by rehlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	if ((char) c == '\0')
		return ((char *) s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	i;
	size_t	j;
	char	*dst;

	len1 = ft_strlen(s1);
	dst = (char *) malloc(sizeof(char) * (len1 + ft_strlen(s2) + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		dst[len1 + j] = s2[j];
		j++;
	}
	dst[len1 + j] = '\0';
	return (dst);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	char	*s2;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	s2 = (char *) malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
