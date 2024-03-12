/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:43:09 by vcaratti          #+#    #+#             */
/*   Updated: 2024/01/08 11:49:41 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_printf(const char *s, ...);
int		ft_putptr(void *ptr);
int		ft_putnbr_u(unsigned int nb);
int		ft_putnbr_base_lc(long lnbr);
int		ft_putnbr_base_uc(long lnbr);
int		ft_putchar_fd_l(char c, int fd);
int		ft_putstr_fd_l(char *s, int fd);
int		ft_putnbr_fd_l(int n, int fd);

#endif
