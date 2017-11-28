/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_upc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 14:28:23 by nolivier          #+#    #+#             */
/*   Updated: 2017/02/23 10:42:06 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libftprintf.h"

int			flag_upc(va_list params, char *flag, char **buf, int *ret)
{
	wint_t			wc;
	char			*tmp;
	char			*str;
	int				len;

	wc = va_arg(params, wint_t);
	if (wc > 1114111)
	{
		free(flag);
		*ret = -1;
		return (0);
	}
	len = ft_put_wi(wc, flag, &tmp);
	str = *buf;
	*buf = ft_strjoin(*buf, tmp);
	free(flag);
	free(str);
	free(tmp);
	*ret = 1;
	return (len);
}
