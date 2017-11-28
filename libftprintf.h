/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 11:52:49 by nolivier          #+#    #+#             */
/*   Updated: 2017/03/01 13:00:21 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <wchar.h>
# include <stdlib.h>
# include <stdarg.h>
# include "ft_styles.h"

# define FLAG_HASH 1
# define FLAG_0 2
# define FLAG_MINUS 4
# define FLAG_PLUS 8
# define FLAG_SPACE 16
# define FLAG_DOLLAR 32
# define FLAG_APOST 64
# define TYPE_HH 1
# define TYPE_H 2
# define TYPE_J 4
# define TYPE_L 8
# define TYPE_LL 16
# define TYPE_Z 32
# define TYPE_UPPERL 64

struct	s_printf
{
	int		(*ptr)(va_list params, char *flag, char **buf, int *ret);
	char	convers;
};

typedef struct s_printf	t_printf;
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
int		ft_printf(const char *restrict format, ...);
int		ft_dprintf(int fd, const char *restrict format, ...);
int		ft_len_w(int n);
int		ft_len_p(int n);
int		ft_len_type(int type);
int		ft_len_flag(int flag);
int		ft_read_flag(va_list params, char *str, char **flag);
char	*ft_write_flag(int width, int preci, int flag, int type);
int		ft_isconvers(int c);
int		ft_isflag(int c);
int		ft_convert_flag(char *str);
int		ft_convert_type(char *str, char speci);
int		ft_read_width(char *flag);
int		ft_read_preci(char *flag);
void	ft_put_sign(char *str, long long int n, int fl);
int		ft_put_n(char *str, unsigned long long nb, int len_n);
int		ft_choose_type(char *flag);
char	*ft_itoa_long(long long int n, char *flag);
char	*ft_itoa_ulong(unsigned long long n, char *flag);
char	*ft_itoa_olong(unsigned long long n, char *flag);
char	*ft_itoa_xlong(unsigned long long n, char *flag);
char	*ft_itoa_upxlong(unsigned long long n, char *flag);
char	*ft_itoa_blong(unsigned long long n, char *flag);
int		ft_unicode_two(wchar_t wc, char *str);
int		ft_unicode_three(wchar_t wc, char *str);
int		ft_unicode_four(wchar_t wc, char *str);
int		ft_put_wi(wint_t wi, char *flag, char **str);
char	*ft_put_wc(wchar_t *wc, char *flag);
int		ft_joinfree(char **buf, char *tmp);
int		flag_percent(va_list params, char *flag, char **buf, int *ret);
int		flag_c(va_list params, char *flag, char **buf, int *ret);
int		flag_s(va_list params, char *flag, char **buf, int *ret);
int		flag_d(va_list params, char *flag, char **buf, int *ret);
int		flag_u(va_list params, char *flag, char **buf, int *ret);
int		flag_p(va_list params, char *flag, char **buf, int *ret);
int		flag_o(va_list params, char *flag, char **buf, int *ret);
int		flag_x(va_list params, char *flag, char **buf, int *ret);
int		flag_upc(va_list params, char *flag, char **buf, int *ret);
int		flag_ups(va_list params, char *flag, char **buf, int *ret);
int		flag_upd(va_list params, char *flag, char **buf, int *ret);
int		flag_upu(va_list params, char *flag, char **buf, int *ret);
int		flag_upo(va_list params, char *flag, char **buf, int *ret);
int		flag_upx(va_list params, char *flag, char **buf, int *ret);
int		flag_b(va_list params, char *flag, char **buf, int *ret);
int		flag_color(va_list params, char *flag, char **buf, int *ret);
int		flag_none(char *str, char *flag, char **buf, int *ret);

static t_printf g_tab[] =
{
	{&flag_percent, '%'},
	{&flag_c, 'c'},
	{&flag_s, 's'},
	{&flag_d, 'd'},
	{&flag_d, 'i'},
	{&flag_u, 'u'},
	{&flag_p, 'p'},
	{&flag_o, 'o'},
	{&flag_x, 'x'},
	{&flag_upc, 'C'},
	{&flag_ups, 'S'},
	{&flag_upd, 'D'},
	{&flag_upu, 'U'},
	{&flag_upo, 'O'},
	{&flag_upx, 'X'},
	{&flag_b, 'b'},
	{&flag_color, '@'},
	{NULL, -1}
};

#endif
