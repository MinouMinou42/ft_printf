/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 13:55:09 by nolivier          #+#    #+#             */
/*   Updated: 2017/02/23 10:45:29 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_len_flag(int flag)
{
	int		count;

	count = 0;
	if (flag & FLAG_HASH)
		count++;
	if (flag & FLAG_0)
		count++;
	if (flag & FLAG_MINUS)
		count++;
	if (flag & FLAG_PLUS)
		count++;
	if (flag & FLAG_SPACE)
		count++;
	if (flag & FLAG_DOLLAR)
		count++;
	if (flag & FLAG_APOST)
		count++;
	return (count);
}
