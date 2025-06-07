/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:49:52 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/07 08:28:44 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>

int		formathandle(va_list args, char c);
int		ft_printf(const char *s, ...);
int		fstring(char *s);
int		fnumber(int n);
int		funsignednumber(unsigned int n);
int		fhexnumber(unsigned int n, bool format);
int		fpoint(void *p, bool address);

#endif