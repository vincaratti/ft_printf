/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:46:43 by vcaratti          #+#    #+#             */
/*   Updated: 2024/01/09 14:27:43 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;

	counter = 0;
	if (dstsize == 0)
	{
		while (src[counter] != '\0')
			counter++;
		return (counter);
	}
	while (counter < dstsize - 1 && src[counter] != '\0')
	{
		dst[counter] = src[counter];
		counter++;
	}
	if (counter < dstsize)
		dst[counter] = '\0';
	while (src[counter] != '\0')
		counter++;
	return (counter);
}
