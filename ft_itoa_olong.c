/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_olong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:54:25 by nolivier          #+#    #+#             */
/*   Updated: 2017/03/01 16:18:08 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

static int		ft_put_n_octo(char *str, unsigned long long nb, int len_n)
{
	int					i;

	i = 0;
	while (i < len_n)
	{
		str[-i++] = '0' + nb % 8;
		nb = nb / 8;
	}
	return (i);
}

static int		ft_len_n(unsigned long long nb, int preci)
{
	int					count;

	if (nb == 0 && preci == 0)
		return (0);
	count = 0;
	while (nb >= 8)
	{
		nb = nb / 8;
		count++;
	}
	return (count + 1);
}

static char		*ft_set_n(unsigned long long nb, int len, int len_n, int fl)
{
	char				*str;
	int					i;

	if ((str = (char*)malloc(sizeof(char) * (len + 1))) == 0)
		return (NULL);
	i = ft_put_n_octo((str + len - 1), nb, len_n);
	if (fl & FLAG_0)
	{
		while (i < len)
			str[len - 1 - i++] = '0';
	}
	else
	{
		while (i < len)
			str[len - 1 - i++] = ' ';
	}
	str[len] = '\0';
	return (str);
}

static char		*ft_set_n_left(unsigned long long nb, int len,
		int len_n)
{
	char				*str;
	int					i;

	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (NULL);
	i = ft_put_n_octo((str + len_n - 1), nb, len_n);
	while (i < len)
		str[len - 1 + len_n - i++] = ' ';
	str[len] = '\0';
	return (str);
}

char			*ft_itoa_olong(unsigned long long n, char *flag)
{
	int					len;
	int					len_n;
	int					fl;

	fl = ft_convert_flag(flag);
	if ((len = ft_read_preci(flag)) != -1)
		fl = fl & (~FLAG_0);
	len_n = ft_len_n(n, len);
	if ((fl & FLAG_HASH) && (len == 0 || (n != 0 && len_n >= len)))
		len_n += 1;
	if (len > len_n)
		len_n = len;
	len = ft_read_width(flag);
	len = (len > len_n) ? len : len_n;
	if ((fl & FLAG_MINUS))
		return (ft_set_n_left(n, len, len_n));
	return (ft_set_n(n, len, len_n, fl));
}
