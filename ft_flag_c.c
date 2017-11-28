/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:48:35 by nolivier          #+#    #+#             */
/*   Updated: 2017/02/23 15:46:26 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libftprintf.h"

static char		*ft_set_c(char c, int len, int fl)
{
	char			*tmp;
	int				i;

	tmp = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len - 1)
		tmp[i++] = (fl & FLAG_0) ? '0' : ' ';
	tmp[i++] = (c) ? c : (char)255;
	tmp[i] = '\0';
	return (tmp);
}

static char		*ft_set_c_left(char c, int len)
{
	char			*tmp;
	int				i;

	tmp = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	tmp[i++] = (c) ? c : (char)255;
	while (i < len)
		tmp[i++] = ' ';
	tmp[i] = '\0';
	return (tmp);
}

static char		*ft_put_c(char c, char *flag)
{
	int				len;
	int				fl;

	fl = ft_convert_flag(flag);
	len = ft_read_width(flag);
	if (len < 1)
		len = 1;
	if (fl & FLAG_MINUS)
		return (ft_set_c_left(c, len));
	return (ft_set_c(c, len, fl));
}

int				flag_c(va_list params, char *flag, char **buf, int *ret)
{
	char			c;
	char			*tmp;
	char			*str;
	int				len;
	int				type;

	if ((type = ft_choose_type(flag)) == 4)
		return (flag_upc(params, flag, buf, ret));
	c = (char)va_arg(params, int);
	tmp = ft_put_c(c, flag);
	str = *buf;
	*buf = ft_strjoin(*buf, tmp);
	len = ft_strlen(tmp);
	free(flag);
	free(str);
	free(tmp);
	*ret = 1;
	return (len);
}
