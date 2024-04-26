/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinella <grinella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:29:06 by grinella          #+#    #+#             */
/*   Updated: 2024/04/16 10:28:27 by grinella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin1(char *s1, char const *s2)
{
	char	*string;
	size_t	i;
	size_t	x;

	if (!s1)
		s1 = ft_strdup("");
	string = malloc(sizeof(char) * (ft_strlen1(s1) + ft_strlen1(s2) + 1));
	if (!string)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	x = 0;
	while (s2[x])
		string[i++] = s2[x++];
	string[i] = 0;
	free(s1);
	return (string);
}

char	*ft_strdup1(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen1(s1) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

unsigned int	ft_strlen1(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putindex(const char *s, char c)
{
	unsigned int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}
