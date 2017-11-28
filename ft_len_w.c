/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_w.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 13:56:59 by nolivier          #+#    #+#             */
/*   Updated: 2017/02/23 10:47:18 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_len_w(int n)
{
	int			count;

	count = 0;
	if (n < 1)
		return (0);
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	count++;
	return (count);
}
