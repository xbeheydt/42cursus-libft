/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .tests.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:02:01 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/03/09 11:02:01 by xbeheydt         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TESTS_H
# define _TESTS_H

# include <stdio.h>
# include <stdlib.h>

/* Commons macros */
# define SPACE			" "
# define ENDL			"\n"

enum state_s
{
	RUN,
	STOP,
	END,
	SKIP,
	OK,
	KO
};

typedef struct unit_s
{
	const char	*testName;
	int			(*testFcn)(void *);
	void		(*setupFcn)(void *);
	void		(*teardownFcn)(void *);
	int			state;
}	unit_t;

/* GUI helpers */

/* Colors */
# define RESET_COLOR	"\033[0m"

# define FG_BLACK		"\033[30m"
# define FG_RED			"\033[31m"
# define FG_GREEN		"\033[32m"
# define FG_YELLOW		"\033[33m"
# define FG_BLUE		"\033[34m"
# define FG_MAGENTA		"\033[35m"
# define FG_CYAN		"\033[36m"
# define FG_WHITE		"\033[37m"

# define BG_BLACK		"\033[40m"
# define BG_RED			"\033[41m"
# define BG_GREEN		"\033[42m"
# define BG_YELLOW		"\033[43m"
# define BG_BLUE		"\033[44m"
# define BG_MAGENTA		"\033[45m"
# define BG_CYAN		"\033[46m"
# define BG_WHITE		"\033[47m"

void	print_skip(const char *s, const char *endl)
{
	dprintf(1, "[%sSKIP%s] %s%s", FG_YELLOW, RESET_COLOR, s, endl);
}
void	print_ok(const char *s, const char *endl)
{
	dprintf(1, "[%sOK%s] %s%s", FG_GREEN, RESET_COLOR, s, endl);
}
void	print_ko(const char *s, const char *endl)
{
	dprintf(1, "[%sKO%s] %s%s", FG_RED, RESET_COLOR, s, endl);
}

/* Main API */
# define TEST_FCN(fcn)	#fcn, fcn
# define TEST_END { NULL, NULL, NULL, NULL, END }

int	__main(int argc, const char *argv[])
{
	(void)argc; (void)argv;
}

#endif /* _TESTS_H */