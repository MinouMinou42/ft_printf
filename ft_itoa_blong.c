/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_blong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:13:08 by nolivier          #+#    #+#             */
/*   Updated: 2017/02/23 16:24:01 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

static int		ft_put_n_bina(char *str, unsigned long long nb, int len_n)
{
	int					i;

	i = 0;
	while (i < len_n)
	{
		str[-i++] = '0' + nb % 2;
		nb = nb / 2;
	}
	return (i);
}

static int		ft_len_n(unsigned long long nb, int preci)
{
	int					count;

	if (nb == 0 && preci == 0)
		return (0);
	count = 0;
	while (nb >= 2)
	{
		nb = nb / 2;
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
	i = ft_put_n_bina((str + len - 1), nb, len_n);
	if (fl & FLAG_0)
	{
		while (i < len)
			str[len - 1 - i++] = '0';
		if ((fl & FLAG_HASH) && nb != 0)
			str[len - i + 1] = 'b';
	}
	else
	{
		if ((fl & FLAG_HASH) && nb != 0)
			str[len - i + 1] = 'b';
		while (i < len)
			str[len - 1 - i++] = ' ';
	}
	str[len] = '\0';
	return (str);
}

static char		*ft_set_n_left(unsigned long long nb, int len,
		int len_n, int fl)
{
	char				*str;
	int					i;

	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (NULL);
	i = ft_put_n_bina((str + len_n - 1), nb, len_n);
	while (i < len)
		str[len - 1 + len_n - i++] = ' ';
	str[len] = '\0';
	if ((fl & FLAG_HASH) && nb != 0)
		str[1] = 'b';
	return (str);
}

char			*ft_itoa_blong(unsigned long long n, char *flag)
{
	int					len;
	int					len_n;
	int					fl;

	fl = ft_convert_flag(flag);
	if ((len = ft_read_preci(flag)) != -1)
		fl = fl & (~FLAG_0);
	len_n = ft_len_n(n, len);
	if (len > len_n)
		len_n = len;
	if ((fl & FLAG_HASH) && n != 0)
		len_n += 2;
	len = ft_read_width(flag);
	len = (len > len_n) ? len : len_n;
	if ((fl & FLAG_MINUS))
		return (ft_set_n_left(n, len, len_n, fl));
	return (ft_set_n(n, len, len_n, fl));
}
