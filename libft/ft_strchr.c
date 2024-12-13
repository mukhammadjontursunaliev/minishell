/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtursuna <mtursuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:19:42 by mtursuna          #+#    #+#             */
/*   Updated: 2024/03/07 19:42:17 by mtursuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			ff;

	ff = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == ff)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == ff)
		return ((char *)&s[i]);
	return (NULL);
}
