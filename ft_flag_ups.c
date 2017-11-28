/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_ups.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:02:56 by nolivier          #+#    #+#             */
/*   Updated: 2017/02/13 12:53:50 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <wchar.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libftprintf.h"

int			flag_ups(va_list params, char *flag, char **buf, int *ret)
{
	char			*str;
	wchar_t			*wc;
	char			*tmp;
	int				len;

	wc = va_arg(params, wchar_t*);
	tmp = ft_put_wc(wc, flag);
	str = *buf;
	*buf = ft_strjoin(*buf, tmp);
	len = ft_strlen(tmp);
	free(tmp);
	free(flag);
	free(str);
	*ret = 1;
	return (len);
}
