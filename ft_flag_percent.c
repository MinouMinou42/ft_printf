/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 12:25:43 by nolivier          #+#    #+#             */
/*   Updated: 2017/02/23 15:49:25 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libftprintf.h"

static char		*ft_set_perc(int len, int fl)
{
	char	*tmp;
	int		i;
	char	c;

	tmp = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	c = (fl & FLAG_0) ? '0' : ' ';
	while (i < len - 1)
		tmp[i++] = c;
	tmp[i] = '%';
	tmp[len] = '\0';
	return (tmp);
}

static char		*ft_set_perc_left(int len)
{
	char	*tmp;
	int		i;

	tmp = (char*)malloc(sizeof(char) * (len + 1));
	i = 1;
	tmp[0] = '%';
	while (i < len)
		tmp[i++] = ' ';
	tmp[len] = '\0';
	return (tmp);
}

static char		*ft_put_percent(char *flag)
{
	int		len;
	int		fl;

	fl = ft_convert_flag(flag);
	len = ft_read_width(flag);
	len = (len > 0) ? len : 1;
	if ((fl & FLAG_MINUS))
		return (ft_set_perc_left(len));
	return (ft_set_perc(len, fl));
}

int				flag_percent(va_list params, char *flag, char **buf, int *ret)
{
	char	*str;
	char	*tmp;
	int		len;

	(void)params;
	str = *buf;
	tmp = ft_put_percent(flag);
	*buf = ft_strjoin(*buf, tmp);
	len = ft_strlen(tmp);
	free(tmp);
	free(flag);
	free(str);
	*ret = 1;
	return (len);
}
