/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 11:25:53 by nolivier          #+#    #+#             */
/*   Updated: 2017/02/23 11:26:54 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

static void			ft_put_flag(char *fl, int flag, int *i)
{
	if (flag & FLAG_HASH)
		fl[(*i)++] = '#';
	if (flag & FLAG_0)
		fl[(*i)++] = '0';
	if (flag & FLAG_MINUS)
		fl[(*i)++] = '-';
	if (flag & FLAG_PLUS)
		fl[(*i)++] = '+';
	if (flag & FLAG_SPACE)
		fl[(*i)++] = ' ';
	if (flag & FLAG_DOLLAR)
		fl[(*i)++] = '$';
	if (flag & FLAG_APOST)
		fl[(*i)++] = '\'';
}

static void			ft_put_int(char *fl, int n, int len, int *i)
{
	int			j;

	j = 0;
	while (j < len)
	{
		fl[*i + len - 1 - j] = '0' + n % 10;
		n = n / 10;
		j++;
	}
	*i += j;
}

static void			ft_put_type(char *fl, int type, int *i)
{
	if (type & TYPE_HH)
	{
		fl[(*i)++] = 'h';
		fl[(*i)++] = 'h';
	}
	else if (type & TYPE_H)
		fl[(*i)++] = 'h';
	else if (type & TYPE_J)
		fl[(*i)++] = 'j';
	else if (type & TYPE_L)
		fl[(*i)++] = 'l';
	else if (type & TYPE_LL)
	{
		fl[(*i)++] = 'l';
		fl[(*i)++] = 'l';
	}
	else if (type & TYPE_Z)
		fl[(*i)++] = 'z';
	else if (type & TYPE_UPPERL)
		fl[(*i)++] = 'L';
}

char				*ft_write_flag(int width, int preci, int flag, int type)
{
	char		*fl;
	int			len;
	int			len_w;
	int			len_p;
	int			i;

	len_w = ft_len_w(width);
	len_p = ft_len_p(preci);
	len = len_w + len_p + ft_len_flag(flag) + ft_len_type(type);
	if (len_p > 0)
		len++;
	fl = (char*)malloc(sizeof(char) * (len + 1));
	fl[len] = '\0';
	i = 0;
	ft_put_flag(fl, flag, &i);
	if (width >= 1)
		ft_put_int(fl, width, len_w, &i);
	if (preci >= 0)
	{
		fl[i++] = '.';
		ft_put_int(fl, preci, len_p, &i);
	}
	ft_put_type(fl, type, &i);
	return (fl);
}
