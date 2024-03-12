/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_uc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:35:48 by vcaratti          #+#    #+#             */
/*   Updated: 2023/12/05 14:04:58 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_base(char *base, int base_l)
{
	int		i;
	int		j;
	char	a;

	i = 0;
	while (i < base_l -1)
	{
		a = base[i];
		if (a == '\t' || a == '\n' || a == '\v' || a == '\f' || a == '\r'
			|| a == ' ' || a == '+' || a == '-')
			return (0);
		j = i + 1;
		while (j < base_l)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	base_rec(size_t nb, int base_l, char *base)
{
	size_t	rem;
	size_t	res;
	int		ret;

	res = nb / base_l;
	rem = nb % base_l;
	ret = 0;
	if (res > 0)
		ret += base_rec(res, base_l, base);
	write(1, &base[rem], 1);
	return (ret + 1);
}

static int	get_base(char *base)
{
	int	counter;

	counter = 0;
	while (base[counter] != '\0')
		counter++;
	return (counter);
}

int	ft_putnbr_base_uc(long lnbr)
{
	int		base_l;
	char	base[17];
	int		ret;

	ret = 0;
	ft_strlcpy(base, "0123456789ABCDEF", 17);
	base_l = get_base(base);
	if (base_l > 1 && check_base(base, base_l) == 1)
	{
		if (lnbr < 0)
		{
			lnbr = -lnbr;
			write(1, "-", 1);
			ret += 1;
		}
		ret += base_rec(lnbr, base_l, base);
	}
	return (ret);
}
