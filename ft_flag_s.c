/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:48:09 by nolivier          #+#    #+#             */
/*   Updated: 2017/02/23 15:50:33 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libftprintf.h"

static int		ft_len_str(char *str, int preci)
{
	int		len;

	if (str == NULL && preci >= 0)
		return ((preci > 6) ? 6 : preci);
	else if (str == NULL)
		return (6);
	len = 0;
	while (*str)
	{
		len++;
		if (preci == 0)
			return (0);
		if (preci > 0 && preci <= len)
			return (len);
		str++;
	}
	return (len);
}

static char		*ft_set_str(char *str, int len, int len_str, int fl)
{
	char	*tmp;
	int		i;
	char	*empty;

	empty = "(null)";
	tmp = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len - len_str)
		tmp[i++] = (fl & FLAG_0) ? '0' : ' ';
	while (i < len)
		tmp[i++] = (str == NULL) ? *empty++ : *str++;
	tmp[i] = '\0';
	return (tmp);
}

static char		*ft_set_str_left(char *str, int len, int len_str)
{
	char	*tmp;
	int		i;
	char	*empty;

	empty = "(null)";
	tmp = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len_str)
		tmp[i++] = (str == NULL) ? *empty++ : *str++;
	while (i < len)
		tmp[i++] = ' ';
	tmp[i] = '\0';
	return (tmp);
}

static char		*ft_put_str(char *str, char *flag)
{
	int		len;
	int		len_str;
	int		fl;

	len = ft_read_preci(flag);
	len_str = ft_len_str(str, len);
	fl = ft_convert_flag(flag);
	len = ft_read_width(flag);
	if (len_str > len)
		len = len_str;
	if ((fl & FLAG_MINUS))
		return (ft_set_str_left(str, len, len_str));
	return (ft_set_str(str, len, len_str, fl));
}

int				flag_s(va_list params, char *flag, char **buf, int *ret)
{
	int		len;
	char	*str;
	char	*tmp;
	int		type;

	if ((type = ft_choose_type(flag)) == 4)
		return (flag_ups(params, flag, buf, ret));
	str = va_arg(params, char*);
	tmp = ft_put_str(str, flag);
	str = *buf;
	*buf = ft_strjoin(*buf, tmp);
	len = ft_strlen(tmp);
	free(str);
	free(flag);
	free(tmp);
	*ret = 1;
	return (len);
}
