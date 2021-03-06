/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_preci.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:58:19 by nolivier          #+#    #+#             */
/*   Updated: 2017/02/23 10:52:56 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_read_preci(char *flag)
{
	while (*flag)
	{
		if (*flag == '.')
			return (ft_atoi(flag + 1));
		flag++;
	}
	return (-1);
}
