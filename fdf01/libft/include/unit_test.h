/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:26:20 by stephane          #+#    #+#             */
/*   Updated: 2024/01/23 00:11:48 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_TEST_H
# define UNIT_TEST_H

# include "ft_printf.h"
# include <stdio.h>
# include <limits.h>

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define FIRST_FIELD_WIDTH -30

typedef struct s_unit_test{
	int	passed;
	int	success;
}	t_unit_test;

typedef enum e_action{
	init,
	increase_tests,
	increase_success,
	get_tests,
	get_success
}	t_action;

int		unit_test(t_action action);

void	unit_test_print_result(const char *title, int field_width);

#endif