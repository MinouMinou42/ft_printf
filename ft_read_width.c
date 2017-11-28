/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:58:00 by nolivier          #+#    #+#             */
/*   Updated: 2017/02/13 15:46:38 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_read_width(char *flag)
{
	while (*flag)
	{
		if (*flag >= '1' && *flag <= '9' && *(flag - 1) != '.')
			return (ft_atoi(flag));
		else if (*(flag - 1) == '.')
			return (0);
		flag++;
	}
	return (0);
}
