/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtursuna <mtursuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:32:39 by mtursuna          #+#    #+#             */
/*   Updated: 2024/03/07 14:45:06 by mtursuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp_ptr;

	tmp_ptr = (unsigned char *)b;
	while (len > 0)
	{
		*(tmp_ptr++) = (unsigned char)c;
		len--;
	}
	return (b);
}
