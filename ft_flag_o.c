/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:52:15 by nolivier          #+#    #+#             */
/*   Updated: 2017/02/17 14:56:37 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include "libftprintf.h"

int			flag_o(va_list params, char *flag, char **buf, int *ret)
{
	char	*tmp;
	int		type;

	if ((type = ft_choose_type(flag)) == 1)
		tmp = ft_itoa_olong(va_arg(params, unsigned int), flag);
	else if (type == 2)
		tmp = ft_itoa_olong((unsigned char)va_arg(params, unsigned int), flag);
	else if (type == 3)
		tmp = ft_itoa_olong((unsigned short)va_arg(params, unsigned int), flag);
	else if (type == 4)
		tmp = ft_itoa_olong(va_arg(params, unsigned long), flag);
	else if (type == 6)
		tmp = ft_itoa_olong(va_arg(params, uintmax_t), flag);
	else if (type == 7)
		tmp = ft_itoa_olong(va_arg(params, size_t), flag);
	else
		tmp = ft_itoa_olong(va_arg(params, unsigned long long), flag);
	free(flag);
	*ret = 1;
	return (ft_joinfree(buf, tmp));
}
