/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:42:24 by vcaratti          #+#    #+#             */
/*   Updated: 2024/01/08 11:49:07 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	treat_param(const char c, va_list va_ptr)
{
	if (c == 'c')
		return (ft_putchar_fd_l((char)va_arg(va_ptr, int), 1));
	else if (c == 's')
		return (ft_putstr_fd_l(va_arg(va_ptr, char *), 1));
	else if (c == 'p')
		return (ft_putptr(va_arg(va_ptr, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd_l(va_arg(va_ptr, int), 1));
	else if (c == 'u')
		return (ft_putnbr_u(va_arg(va_ptr, unsigned int)));
	else if (c == 'x')
		return (ft_putnbr_base_lc(va_arg(va_ptr, unsigned int)));
	else if (c == 'X')
		return (ft_putnbr_base_uc(va_arg(va_ptr, unsigned int)));
	else if (c == '%')
		return (ft_putchar_fd_l('%', 1));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	va_ptr;
	int		counter;
	int		ret_len;

	va_start(va_ptr, s);
	counter = 0;
	ret_len = 0;
	while (s[counter] != '\0')
	{
		if (s[counter] == '%' && s[counter + 1])
			ret_len += treat_param(s[++counter], va_ptr);
		else
		{
			write(1, &s[counter], 1);
			ret_len++;
		}
		counter++;
	}
	return (ret_len);
}
