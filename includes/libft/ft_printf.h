/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:24:07 by sephilip          #+#    #+#             */
/*   Updated: 2024/01/04 14:24:45 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

void	ft_addcount(int	*p);
void	ft_printchar(char c, int *counter);
void	ft_printdec(unsigned int n, int *counter);
void	ft_printstr(char *s, int *counter);
void	ft_printnbr(int n, int *counter);
void	ft_printhex_s(unsigned long num, int *counter);
void	ft_printhex(unsigned long num, int *counter);
void	ft_printptr(void *addr, int *counter);
void	ft_separ(char c, va_list var, int *counter);
int		ft_printf(const char *p, ...);

#endif /*FT_PRINTF_H */
