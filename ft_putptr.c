/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:35:48 by vcaratti          #+#    #+#             */
/*   Updated: 2024/01/08 11:47:40 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	base_rec(size_t nb, int base_l, char *base)
{
	size_t	rem;
	size_t	res;
	size_t	ret;

	ret = 0;
	res = nb / base_l;
	rem = nb % base_l;
	if (res > 0)
		ret = base_rec(res, base_l, base);
	write(1, &base[rem], 1);
	return (ret + 1);
}

int	get_base(char *base)
{
	int	counter;

	counter = 0;
	while (base[counter] != '\0')
		counter++;
	return (counter);
}

int	ft_putptr(void *ptr)
{
	int		base_l;
	size_t	lnbr;
	char	base[17];

	ft_strlcpy(base, "0123456789abcdef", 17);
	lnbr = (size_t)ptr;
	base_l = get_base(base);
	write(1, "0x", 2);
	return ((int)base_rec(lnbr, base_l, base) + 2);
}
