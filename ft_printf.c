/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 13:34:38 by nolivier          #+#    #+#             */
/*   Updated: 2017/03/01 16:20:58 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libftprintf.h"

static void		ft_treat_zero(char *buf)
{
	while (*buf)
	{
		if ((unsigned char)*buf == 255)
			*buf = '\0';
		buf++;
	}
}

static int		ft_link_printf(char *str, char **buf, int *len)
{
	int				i;
	char			*tmp;
	char			*s;

	if ((tmp = ft_strchr(str, '%')) == 0)
	{
		s = *buf;
		*buf = ft_strjoin(*buf, str);
		free(s);
		i = ft_strlen(str);
		*len += i;
	}
	else
	{
		i = tmp - str;
		tmp = ft_strsub(str, 0, i);
		s = *buf;
		*buf = ft_strjoin(*buf, tmp);
		free(s);
		free(tmp);
		*len += i;
	}
	return (i);
}

static int		ft_manage_printf(va_list params, char *str,
		char **buf, int *len)
{
	char			*tmp;
	int				i;
	int				ret;

	while (*str)
	{
		if (*str == '%')
		{
			str++;
			str += ft_read_flag(params, str, &tmp);
			i = 0;
			while (g_tab[i].convers != *str && g_tab[i].convers != -1)
				i++;
			*len += (g_tab[i].convers == *str) ?
				g_tab[i].ptr(params, tmp, buf, &ret) :
				flag_none(str, tmp, buf, &ret);
			if (*str != '\0')
				str++;
			if (ret < 0)
				return (-1);
		}
		else
			str += ft_link_printf(str, buf, len);
	}
	return (ret);
}

int				ft_printf(const char *restrict format, ...)
{
	char			*buf;
	va_list			params;
	int				len;

	len = 0;
	buf = ft_strdup("\0");
	va_start(params, format);
	if (ft_manage_printf(params, (char*)format, &buf, &len) < 0)
	{
		free(buf);
		return (-1);
	}
	va_end(params);
	ft_treat_zero(buf);
	write(1, buf, len);
	free(buf);
	return (len);
}
