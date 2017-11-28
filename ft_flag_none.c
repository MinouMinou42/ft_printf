/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_none.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:48:55 by nolivier          #+#    #+#             */
/*   Updated: 2017/03/01 15:39:54 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

static char		*ft_set_none(char *str, int len, int fl)
{
	char	*tmp;
	int		i;
	char	c;

	tmp = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	c = (fl & FLAG_0) ? '0' : ' ';
	while (i < len - 1)
		tmp[i++] = c;
	tmp[i] = *str;
	tmp[len] = '\0';
	return (tmp);
}

static char		*ft_set_none_left(char *str, int len)
{
	char	*tmp;
	int		i;

	tmp = (char*)malloc(sizeof(char) * (len + 1));
	i = 1;
	tmp[0] = *str;
	while (i < len)
		tmp[i++] = ' ';
	tmp[len] = '\0';
	return (tmp);
}

static char		*ft_put_none(char *str, char *flag)
{
	int		len;
	int		fl;

	if (*str == '\0')
		return (ft_strdup("\0"));
	fl = ft_convert_flag(flag);
	len = ft_read_width(flag);
	len = (len > 0) ? len : 1;
	if ((fl & FLAG_MINUS))
		return (ft_set_none_left(str, len));
	return (ft_set_none(str, len, fl));
}

int				flag_none(char *str, char *flag, char **buf, int *ret)
{
	char	*s;
	char	*tmp;
	int		len;

	s = *buf;
	tmp = ft_put_none(str, flag);
	*buf = ft_strjoin(*buf, tmp);
	len = ft_strlen(tmp);
	free(tmp);
	free(flag);
	free(s);
	*ret = 1;
	return (len);
}
