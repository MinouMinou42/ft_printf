/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 12:17:13 by nolivier          #+#    #+#             */
/*   Updated: 2017/02/17 14:51:08 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include "libftprintf.h"

int			flag_d(va_list params, char *flag, char **buf, int *ret)
{
	char	*tmp;
	int		type;

	if ((type = ft_choose_type(flag)) == 1)
		tmp = ft_itoa_long(va_arg(params, int), flag);
	else if (type == 2)
		tmp = ft_itoa_long((char)va_arg(params, int), flag);
	else if (type == 3)
		tmp = ft_itoa_long((short int)va_arg(params, int), flag);
	else if (type == 4)
		tmp = ft_itoa_long(va_arg(params, long int), flag);
	else if (type == 6)
		tmp = ft_itoa_long(va_arg(params, intmax_t), flag);
	else if (type == 7)
		tmp = ft_itoa_long(va_arg(params, size_t), flag);
	else
		tmp = ft_itoa_long(va_arg(params, long long int), flag);
	free(flag);
	*ret = 1;
	return (ft_joinfree(buf, tmp));
}
