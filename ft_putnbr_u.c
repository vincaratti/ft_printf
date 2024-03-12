/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:59:21 by vcaratti          #+#    #+#             */
/*   Updated: 2023/12/05 13:41:09 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_numbers_rec(unsigned int nb)
{
	unsigned int	res;
	int				ret;

	if (nb > 9)
	{
		res = nb % 10 + 48;
		nb = nb / 10;
		ret = print_numbers_rec(nb);
	}
	else
	{
		res = nb + 48;
		ret = 0;
	}
	write(1, &res, 1);
	return (ret + 1);
}

int	ft_putnbr_u(unsigned int nb)
{
	return (print_numbers_rec(nb));
}
