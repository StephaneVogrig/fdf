/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:10:46 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/23 00:10:48 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	unit_test_print_result(const char *title, int field_width)
{
	ft_printf("%-*s ", field_width, title);
	ft_printf("%3i / ", unit_test(get_success));
	ft_printf("%3i tests passed\n", unit_test(get_tests));
}

int	unit_test(t_action action)
{
	static t_ui32	tests;
	static t_ui32	success;

	if (action == init)
	{
		tests = 0;
		success = 0;
	}
	if (action == increase_tests)
		return (tests++);
	if (action == increase_success)
		return (success++);
	if (action == get_tests)
		return (tests);
	if (action == get_success)
		return (success);
	return (0);
}
