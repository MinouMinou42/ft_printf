/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 12:09:15 by nolivier          #+#    #+#             */
/*   Updated: 2017/02/23 15:44:55 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_set_flag(int flag)
{
	if ((flag & FLAG_0) && (flag & FLAG_MINUS))
		flag = flag & ~FLAG_0;
	if ((flag & FLAG_SPACE) && (flag & FLAG_PLUS))
		flag = flag & ~FLAG_SPACE;
	return (flag);
}

int				ft_convert_flag(char *str)
{
	int		flag;
	int		i;

	flag = 0;
	i = 0;
	while (str[i] && ft_isconvers(str[i]) == 0)
	{
		if (str[i] == '#')
			flag = flag | FLAG_HASH;
		else if (str[i] == '0' && (i == 0 ||
					(ft_isdigit(str[i - 1]) == 0 && str[i - 1] != '.')))
			flag = flag | FLAG_0;
		else if (str[i] == '-')
			flag = flag | FLAG_MINUS;
		else if (str[i] == '+')
			flag = flag | FLAG_PLUS;
		else if (str[i] == ' ')
			flag = flag | FLAG_SPACE;
		else if (str[i] == '$')
			flag = flag | FLAG_DOLLAR;
		else if (str[i] == '\'')
			flag = flag | FLAG_APOST;
		i++;
	}
	return (ft_set_flag(flag));
}
