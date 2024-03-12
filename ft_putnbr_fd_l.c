/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:38:17 by vcaratti          #+#    #+#             */
/*   Updated: 2023/12/05 14:09:06 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd_l(int n, int fd)
{
	char	out;
	int		ret;

	ret = 0;
	if (n == -2147483648)
	{
		write(fd, "-", 1);
		write(fd, "2", 1);
		n += 2000000000;
		n = -n;
		ret += 2;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		ret += 1;
		n = -n;
	}
	if (n / 10)
		ret += ft_putnbr_fd_l(n / 10, fd);
	out = n % 10 + 48;
	write(fd, &out, 1);
	return (ret + 1);
}
