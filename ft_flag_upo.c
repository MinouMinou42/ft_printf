/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_upo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:33:44 by nolivier          #+#    #+#             */
/*   Updated: 2017/02/17 12:34:08 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include "libftprintf.h"

int			flag_upo(va_list params, char *flag, char **buf, int *ret)
{
	char	*str;
	char	*tmp;
	int		type;

	type = ft_choose_type(flag);
	if (type <= 4 || type == 6)
		tmp = ft_itoa_olong(va_arg(params, unsigned long), flag);
	else if (type == 7)
		tmp = ft_itoa_olong(va_arg(params, size_t), flag);
	else
		tmp = ft_itoa_olong(va_arg(params, unsigned long long), flag);
	str = *buf;
	*buf = ft_strjoin(*buf, tmp);
	type = ft_strlen(tmp);
	free(flag);
	free(str);
	free(tmp);
	*ret = 1;
	return (type);
}
