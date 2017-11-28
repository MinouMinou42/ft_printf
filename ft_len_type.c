/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 13:56:09 by nolivier          #+#    #+#             */
/*   Updated: 2017/02/23 10:46:34 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_len_type(int type)
{
	if ((type & TYPE_HH) || (type & TYPE_LL))
		return (2);
	else if (type)
		return (1);
	else
		return (0);
}
