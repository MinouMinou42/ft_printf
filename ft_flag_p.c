/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 12:37:20 by nolivier          #+#    #+#             */
/*   Updated: 2017/02/23 15:48:20 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>
#include <stdarg.h>
#include "libftprintf.h"

static int			ft_len_ad(unsigned long ad, int preci)
{
	int				i;

	if (ad == 0 && preci == 0)
		return (2);
	i = 0;
	if (ad == 0)
		i++;
	while (ad)
	{
		ad = ad / 16;
		i++;
	}
	i = (i > preci) ? i + 2 : preci + 2;
	return (i);
}

static char			*ft_set_ad(unsigned long ad, int len, int len_ad, int fl)
{
	char			*tmp;
	int				i;
	char			*base;

	base = "0123456789abcdef";
	tmp = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len - len_ad)
		tmp[i++] = (fl & FLAG_0) ? '0' : ' ';
	i = 0;
	while (i < len_ad)
	{
		tmp[len - i - 1] = base[ad % 16];
		ad = ad / 16;
		i++;
	}
	if ((fl & FLAG_0))
		tmp[1] = 'x';
	else
		tmp[len - i + 1] = 'x';
	tmp[len] = '\0';
	return (tmp);
}

static char			*ft_set_ad_left(unsigned long ad, int len, int len_ad)
{
	char			*tmp;
	int				i;
	char			*base;

	base = "0123456789abcdef";
	tmp = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len_ad)
	{
		tmp[len_ad - i - 1] = base[ad % 16];
		ad = ad / 16;
		i++;
	}
	while (i < len)
		tmp[i++] = ' ';
	tmp[1] = 'x';
	tmp[len] = '\0';
	return (tmp);
}

static char			*ft_put_addr(unsigned long ad, char *flag)
{
	int				len;
	int				len_ad;
	int				fl;

	len = ft_read_preci(flag);
	len_ad = ft_len_ad(ad, len);
	fl = ft_convert_flag(flag);
	if (len != -1)
		fl = fl & (~FLAG_0);
	len = ft_read_width(flag);
	if (len_ad > len)
		len = len_ad;
	if ((fl & FLAG_MINUS))
		return (ft_set_ad_left(ad, len, len_ad));
	return (ft_set_ad(ad, len, len_ad, fl));
}

int					flag_p(va_list params, char *flag, char **buf, int *ret)
{
	char			*str;
	char			*tmp;
	unsigned long	ad;
	int				len;

	ad = (unsigned long int)va_arg(params, void*);
	tmp = ft_put_addr(ad, flag);
	str = *buf;
	*buf = ft_strjoin(*buf, tmp);
	len = ft_strlen(tmp);
	free(str);
	free(tmp);
	free(flag);
	*ret = 1;
	return (len);
}
