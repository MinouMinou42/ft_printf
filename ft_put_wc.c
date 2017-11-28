/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_wc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:13:02 by nolivier          #+#    #+#             */
/*   Updated: 2017/02/23 16:04:00 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdlib.h>
#include "libftprintf.h"

static void			ft_put_unicode(wchar_t *wc, int len, char *tmp, int *i)
{
	while (*i < len)
	{
		if (*wc < 128 && *i + 1 <= len)
			tmp[(*i)++] = (char)*wc;
		else if (*wc < 2048 && *i + 2 <= len)
			*i += ft_unicode_two(*wc, tmp + *i);
		else if (*wc < 65536 && *i + 3 <= len)
			*i += ft_unicode_three(*wc, tmp + *i);
		else if (*wc < 1114112 && *i + 4 <= len)
			*i += ft_unicode_four(*wc, tmp + *i);
		wc++;
	}
}

static int			ft_len_wc(wchar_t *wc, int preci)
{
	int			len;
	int			tmp;

	if (wc == NULL && preci >= 0)
		return ((preci > 6) ? 6 : preci);
	else if (wc == NULL)
		return (6);
	len = 0;
	while (*wc)
	{
		if (*wc < 128)
			tmp = 1;
		else if (*wc < 2048)
			tmp = 2;
		else if (*wc < 65536)
			tmp = 3;
		else if (*wc < 1114112)
			tmp = 4;
		if (preci >= 0 && preci <= len + tmp)
			return (len);
		len += tmp;
		wc++;
	}
	return (len);
}

static char			*ft_set_wc(wchar_t *wc, int len, int len_wc, int fl)
{
	char		*tmp;
	int			i;
	char		*empty;

	empty = "(null)";
	tmp = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len - len_wc)
		tmp[i++] = (fl & FLAG_0) ? '0' : ' ';
	if (wc == NULL)
	{
		while (i < len)
			tmp[i++] = *empty++;
	}
	else
		ft_put_unicode(wc, len, tmp, &i);
	tmp[i] = '\0';
	return (tmp);
}

static char			*ft_set_wc_left(wchar_t *wc, int len, int len_wc)
{
	char		*tmp;
	int			i;
	char		*empty;

	empty = "(null)";
	tmp = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (wc == NULL)
	{
		while (i < len_wc)
			tmp[i++] = *empty++;
	}
	else
		ft_put_unicode(wc, len_wc, tmp, &i);
	while (i < len)
		tmp[i++] = ' ';
	tmp[i] = '\0';
	return (tmp);
}

char				*ft_put_wc(wchar_t *wc, char *flag)
{
	int			len;
	int			len_wc;
	int			fl;

	len = ft_read_preci(flag);
	len_wc = ft_len_wc(wc, len);
	fl = ft_convert_flag(flag);
	len = ft_read_width(flag);
	if (len_wc > len)
		len = len_wc;
	if ((fl & FLAG_MINUS))
		return (ft_set_wc_left(wc, len, len_wc));
	return (ft_set_wc(wc, len, len_wc, fl));
}
