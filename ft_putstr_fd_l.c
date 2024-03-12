/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:57:00 by vcaratti          #+#    #+#             */
/*   Updated: 2024/01/08 11:41:47 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putnull_l(void)
{
	return (ft_putstr_fd_l("(null)", 1));
}

int	ft_putstr_fd_l(char *s, int fd)
{
	size_t	counter;

	counter = 0;
	if (!s)
		return (putnull_l());
	while (s[counter])
		write(fd, &s[counter++], 1);
	return ((int)counter);
}
