/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_wi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:09:01 by nolivier          #+#    #+#             */
/*   Updated: 2017/02/23 16:05:07 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdlib.h>
#include "libftprintf.h"

static void			ft_put_unicode(wint_t wc, int len, char *tmp, int *i)
{
	while (*i < len)
	{
		if (wc < 128 && *i + 1 <= len)
			tmp[(*i)++] = (wc) ? (char)wc : (char)255;
		else if (wc < 2048 && *i + 2 <= len)
			*i += ft_unicode_two(wc, tmp + *i);
		else if (wc < 65536 && *i + 3 <= len)
			*i += ft_unicode_three(wc, tmp + *i);
		else if (wc < 1114112 && *i + 4 <= len)
			*i += ft_unicode_four(wc, tmp + *i);
		wc++;
	}
}

static int			ft_len_wi(wint_t wi)
{
	int			len;

	if (wi < 128)
		len = 1;
	else if (wi < 2048)
		len = 2;
	else if (wi < 65536)
		len = 3;
	else if (wi < 1114112)
		len = 4;
	else
		len = 0;
	return (len);
}

static char			*ft_set_wi(wint_t wi, int len, int len_wi, int fl)
{
	char		*tmp;
	int			i;

	tmp = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (fl & FLAG_0)
	{
		while (i < len - len_wi)
			tmp[i++] = '0';
	}
	else
	{
		while (i < len - len_wi)
			tmp[i++] = ' ';
	}
	ft_put_unicode(wi, len, tmp, &i);
	tmp[i] = '\0';
	return (tmp);
}

static char			*ft_set_wi_left(wint_t wi, int len, int len_wi)
{
	char		*tmp;
	int			i;

	tmp = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	ft_put_unicode(wi, len_wi, tmp, &i);
	while (i < len)
		tmp[i++] = ' ';
	tmp[i] = '\0';
	return (tmp);
}

int					ft_put_wi(wint_t wi, char *flag, char **str)
{
	int			len;
	int			len_wi;
	int			fl;

	len_wi = ft_len_wi(wi);
	fl = ft_convert_flag(flag);
	len = ft_read_width(flag);
	if (len_wi > len)
		len = len_wi;
	*str = (fl & FLAG_MINUS) ? ft_set_wi_left(wi, len, len_wi) :
		ft_set_wi(wi, len, len_wi, fl);
	return (len);
}
