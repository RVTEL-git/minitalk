/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:32:23 by barmarti          #+#    #+#             */
/*   Updated: 2025/06/29 18:21:03 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <string.h>

void	*ft_memset(void *p, int value, size_t len)
{
	unsigned char	*u;

	u = (unsigned char *)p;
	while (len > 0)
	{
		*u = (unsigned char)value;
		u++;
		len--;
	}
	return (p);
}
