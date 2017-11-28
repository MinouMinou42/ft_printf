/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 10:54:44 by nolivier          #+#    #+#             */
/*   Updated: 2017/02/27 11:08:11 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"

int			flag_color(va_list params, char *flag, char **buf, int *ret)
{
	char		*str;
	char		*tmp;
	int			len;

	tmp = va_arg(params, char*);
	str = *buf;
	*buf = ft_strjoin(*buf, tmp);
	len = ft_strlen(tmp);
	free(str);
	free(flag);
	*ret = 1;
	return (len);
}
