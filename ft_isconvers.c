/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isconvers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 11:24:30 by nolivier          #+#    #+#             */
/*   Updated: 2017/02/27 12:12:36 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_isconvers(int c)
{
	char	*conv;

	conv = "sSpdDioOuUxXcCb%eEfFgGaAn@";
	while (*conv && *conv != (char)c)
		conv++;
	if (*conv == (char)c && *conv != 0)
		return (1);
	return (0);
}
