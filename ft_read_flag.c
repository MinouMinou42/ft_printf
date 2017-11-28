/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 13:08:48 by nolivier          #+#    #+#             */
/*   Updated: 2017/03/01 16:21:35 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

static void			ft_read_digit(char *str, int *i, int *width, int *preci)
{
	if (str[*i] == '.')
	{
		*preci = ft_atoi(str + *i + 1);
		while (ft_isdigit(str[*i + 1]))
			*i += 1;
	}
	else if (str[*i] >= '1' && str[*i] <= '9')
	{
		*width = ft_atoi(str + *i);
		while (ft_isdigit(str[*i + 1]))
			*i += 1;
	}
}

static void			ft_read_starpreci(va_list params, int *preci)
{
	if ((*preci = va_arg(params, int)) < 0)
		*preci = -1;
}

static void			ft_read_starwidth(va_list params, int *width, int *fl)
{
	if ((*width = va_arg(params, int)) < 0)
	{
		*fl = *fl | FLAG_MINUS;
		*width = -*width;
	}
}

int					ft_read_flag(va_list params, char *str, char **flag)
{
	int			width;
	int			preci;
	int			fl;
	int			i;

	width = 0;
	preci = -1;
	fl = ft_convert_flag(str);
	i = 0;
	while (ft_isconvers(str[i]) == 0 && ft_isflag(str[i]) == 1 && str[i])
	{
		if (str[i] == '*')
			(str[i - 1] == '.') ? ft_read_starpreci(params, &preci) :
				ft_read_starwidth(params, &width, &fl);
		else
			ft_read_digit(str, &i, &width, &preci);
		i += 1;
	}
	*flag = ft_write_flag(width, preci, fl, ft_convert_type(str, str[i]));
	return (i);
}
