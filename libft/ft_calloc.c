/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtursuna <mtursuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:20:19 by mtursuna          #+#    #+#             */
/*   Updated: 2024/03/15 14:34:20 by mtursuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (!count || !size)
	{
		count = 1;
		size = 1;
	}
	if (count > 2147483647 / size)
		return (NULL);
	tmp = (char *)malloc(count * size);
	if (!tmp)
		return (NULL);
	while (i < (count * size))
		tmp[i++] = 0;
	return (tmp);
}
