/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtursuna <mtursuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:08:55 by mtursuna          #+#    #+#             */
/*   Updated: 2024/03/13 15:49:29 by mtursuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_set(char c, char const *set)
{
	while (*set)
	{
		if (*set++ == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*trimmed_str;
	int			trimmed_len;
	const char	*start;
	const char	*end;

	end = s1 + ft_strlen(s1) - 1;
	start = s1;
	if (!s1 || !set)
		return (NULL);
	while (*start && is_set(*start, set))
		start++;
	while (end > start && is_set(*end, set))
		end--;
	trimmed_len = end - start + 1;
	trimmed_str = (char *)malloc(sizeof(char) * (trimmed_len + 1));
	if (!trimmed_str)
		return (NULL);
	ft_strlcpy(trimmed_str, start, trimmed_len + 1);
	trimmed_str[trimmed_len] = '\0';
	return (trimmed_str);
}
