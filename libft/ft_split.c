/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtursuna <mtursuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:46:03 by mtursuna          #+#    #+#             */
/*   Updated: 2024/03/14 20:57:01 by mtursuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	result;

	if (!s)
		return (0);
	i = 0;
	result = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			result++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (result);
}

static char	**ft_free_allocated_memory(char **result, size_t i)
{
	while (i > 0)
		free(result[--i]);
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;
	char	**result;

	i = 0;
	j = 0;
	result = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (i < ft_count_words(s, c))
	{
		while (s[j] && s[j] == c)
			j++;
		start = j;
		while (s[j] && s[j] != c)
			j++;
		result[i] = ft_substr(s, start, j - start);
		if (!result[i])
			return (ft_free_allocated_memory(result, i));
		i++;
	}
	result[i] = NULL;
	return (result);
}
