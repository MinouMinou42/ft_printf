/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_styles.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:14:05 by nolivier          #+#    #+#             */
/*   Updated: 2017/02/27 11:19:21 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STYLES_H
# define FT_STYLES_H

/*
**		DEFINE CONTROL SEQUENCES FOR FORMATTING TEXT
*/

# define INIT            "\033[0m"
# define BOLD            "\033[1m"
# define DIM            "\033[2m"
# define UNDERLINED        "\033[4m"
# define BLINK            "\033[5m"
# define REVERSE        "\033[7m"
# define HIDDEN            "\033[8m"

/*
**		THE FOLLOWING COLORS WORKS WITH ITERM2 AND MOST TERMINALS
**
**		NOTE: THE COLORS CAN VARY DEPENDING OF THE TERMINAL CONFIGURATION
*/

/*
**		Regular Colors
*/

# define BLACK            "\033[0;30m"
# define RED            "\033[0;31m"
# define GREEN            "\033[0;32m"
# define YELLOW            "\033[0;33m"
# define BLUE            "\033[0;34m"
# define PURPLE            "\033[0;35m"
# define CYAN            "\033[0;36m"
# define WHITE            "\033[0;37m"

/*
**		Bold Style
*/

# define B_BLACK        "\033[1;30m"
# define B_RED            "\033[1;31m"
# define B_GREEN        "\033[1;32m"
# define B_YELLOW        "\033[1;33m"
# define B_BLUE            "\033[1;34m"
# define B_PURPLE        "\033[1;35m"
# define B_CYAN            "\033[1;36m"
# define B_WHITE        "\033[1;37m"

/*
**		Bold High Intensty Colors
*/

# define H_BLACK        "\033[1;90m"
# define H_RED            "\033[1;91m"
# define H_GREEN        "\033[1;92m"
# define H_YELLOW        "\033[1;93m"
# define H_BLUE            "\033[1;94m"
# define H_PURPLE        "\033[1;95m"
# define H_CYAN            "\033[1;96m"
# define H_WHITE        "\033[1;97m"

/*
**		Background Colors
*/

# define BK_BLACK        "\033[40m"
# define BK_RED            "\033[41m"
# define BK_GREEN        "\033[42m"
# define BK_YELLOW        "\033[43m"
# define BK_BLUE        "\033[44m"
# define BK_PURPLE        "\033[45m"
# define BK_CYAN        "\033[46m"
# define BK_WHITE        "\033[47m"

/*
**		High Intensty Backgrounds
*/

# define BKI_BLACK        "\033[100m"
# define BKI_RED        "\033[101m"
# define BKI_GREEN        "\033[102m"
# define BKI_YELLOW        "\033[103m"
# define BKI_BLUE        "\033[104m"
# define BKI_PURPLE        "\033[105m"
# define BKI_CYAN        "\033[106m"
# define BKI_WHITE        "\033[107m"

#endif
