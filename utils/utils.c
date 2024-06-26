/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinella <grinella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:06:57 by grinella          #+#    #+#             */
/*   Updated: 2024/05/24 15:06:58 by grinella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (*matrix == NULL)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	matrix = NULL;
	return ;
}

//conteggio linee
int	ft_count_line(char *str, char c)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			r++;
		i++;
	}
	r++;
	return (r);
}

//unione stringhe con free integrato
char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (!(s1 && s2))
		return (NULL);
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}

//funzione di print delle matrici
void	print_matrix(char **mtr)
{
	int	i;

	i = 0;
	while (mtr[i])
	{
		printf("%s", mtr[i]);
		printf("\n");
		i++;
	}
	printf("\n");
	return ;
}

//funzione che lascia solo uno spazio sulle linnee delle texture
char	*ft_one_space(char	*str, int s, int f)
{
	char	*fine;

	fine = (char *)malloc(21);
	while (str[s] == ' ' || str[s] == '\t' || str[s] == '\v')
		s++;
	while (str[s] != '\0')
	{
		if (str[s] == ' ' || str[s] == '\t' || str[s] == '\v')
		{
			fine[f] = ' ';
			s++;
			f++;
			while (str[s] == ' ' || str[s] == '\t' || str[s] == '\v')
				s++;
		}
		else
		{
			fine[f] = str[s];
			s++;
			f++;
		}
	}
	fine[f] = '\0';
	return (fine);
}
