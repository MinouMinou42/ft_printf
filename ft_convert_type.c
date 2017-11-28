/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:05:53 by nolivier          #+#    #+#             */
/*   Updated: 2017/02/23 15:45:39 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int			ft_isdouble(int c)
{
	char	*conv;

	conv = "eEfFgGaA";
	while (*conv && *conv != (char)c)
		conv++;
	if (*conv == (char)c)
		return (1);
	return (0);
}

static int			ft_set_type(char *str, int type, int *i)
{
	if (str[*i] == 'h')
	{
		if (str[*i + 1] != 'h')
			type = (type > TYPE_H) ? type : TYPE_H;
		else if (str[(*i)++ + 1] == 'h')
			type = (type > TYPE_HH) ? type : TYPE_HH;
	}
	else if (str[*i] == 'j')
		type = (type > TYPE_J) ? type : TYPE_J;
	else if (str[*i] == 'l')
	{
		if (str[*i + 1] != 'l')
			type = (type > TYPE_L) ? type : TYPE_L;
		else if (str[(*i)++ + 1] == 'l')
			type = (type > TYPE_LL) ? type : TYPE_LL;
	}
	else if (str[*i] == 'z')
		type = (type > TYPE_Z) ? type : TYPE_Z;
	return (type);
}

int					ft_convert_type(char *str, char speci)
{
	int		type;
	int		i;

	type = 0;
	i = 0;
	while (str[i] && ft_isconvers(str[i]) == 0)
	{
		if (str[i] == 'L' && ft_isdouble(speci))
			return (TYPE_UPPERL);
		else if (!ft_isdouble(speci))
			type = ft_set_type(str, type, &i);
		i++;
	}
	return (type);
}
