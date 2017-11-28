/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 11:22:16 by nolivier          #+#    #+#             */
/*   Updated: 2017/02/23 10:15:07 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_choose_type(char *flag)
{
	int		i;

	i = 0;
	while (flag[i])
	{
		if ((ft_isflag(flag[i++])) == 0)
			return (0);
	}
	i--;
	if (flag[i] == 'h')
		return ((i > 0 && flag[i - 1] == 'h') ? 2 : 3);
	else if (flag[i] == 'l')
		return ((i > 0 && flag[i - 1] == 'l') ? 5 : 4);
	else if (flag[i] == 'j')
		return (6);
	else if (flag[i] == 'z')
		return (7);
	return (1);
}
