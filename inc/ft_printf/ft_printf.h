/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:46:18 by mmonpeat          #+#    #+#             */
/*   Updated: 2024/08/05 13:14:25 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(char const *str, ...);
int	print_percent(char *str, va_list ptr);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putvoid(unsigned long v);
int	ft_putnum(int n);
int	ft_putaux(int n, int i);
int	ft_putusnum(unsigned int u);
int	ft_puthex(unsigned int s, char *base);

#endif
