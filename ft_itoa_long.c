/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:34:21 by nolivier          #+#    #+#             */
/*   Updated: 2017/02/23 15:57:55 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

static int		ft_len_n(long long int nbr, int fl, int preci)
{
	int					count;
	unsigned long long	n;

	count = 0;
	if (nbr == 0 && preci == 0)
		return (0);
	if (nbr < 0)
	{
		n = -nbr;
		count++;
	}
	else
	{
		n = nbr;
		if ((fl & FLAG_PLUS))
			count++;
	}
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	return (count + 1);
}

static char		*ft_set_n(long long int n, int len, int len_n, int fl)
{
	char				*str;
	int					i;
	unsigned long long	nb;

	if ((str = (char*)malloc(sizeof(char) * (len + 1))) == 0)
		return (NULL);
	nb = (n < 0) ? -n : n;
	i = ft_put_n((str + len - 1), nb, len_n);
	if (fl & FLAG_0)
	{
		while (i < len)
			str[len - 1 - i++] = '0';
		ft_put_sign((str + len - i), n, fl);
	}
	else
	{
		ft_put_sign((str + len - i), n, fl);
		while (i < len)
			str[len - 1 - i++] = ' ';
	}
	if ((fl & FLAG_SPACE) && n >= 0)
		str[len - i] = ' ';
	str[len] = '\0';
	return (str);
}

static char		*ft_set_n_left(long long int n, int len, int len_n, int fl)
{
	char				*str;
	int					i;
	unsigned long long	nb;

	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (NULL);
	nb = (n < 0) ? -n : n;
	i = 0;
	if ((fl & FLAG_SPACE))
		str[i++] = ' ';
	i += ft_put_n((str + len_n - 1 + i), nb, len_n);
	ft_put_sign((str + len_n - i), n, fl);
	while (i < len)
		str[i++] = ' ';
	str[i] = '\0';
	return (str);
}

char			*ft_itoa_long(long long int n, char *flag)
{
	int					len;
	int					len_n;
	int					fl;

	fl = ft_convert_flag(flag);
	if ((len = ft_read_preci(flag)) != -1)
		fl = fl & (~FLAG_0);
	len_n = ft_len_n(n, fl, len);
	if (len >= len_n)
	{
		len_n = len;
		if ((n < 0) || (fl & FLAG_PLUS))
			len_n++;
	}
	len = ft_read_width(flag);
	len = (len > len_n) ? len : len_n;
	if ((fl & FLAG_SPACE) && len == len_n && n >= 0)
		len++;
	if ((fl & FLAG_MINUS))
		return (ft_set_n_left(n, len, len_n, fl));
	return (ft_set_n(n, len, len_n, fl));
}
