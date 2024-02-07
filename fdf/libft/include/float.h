/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:13:52 by stephane          #+#    #+#             */
/*   Updated: 2024/01/18 22:11:33 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_H
# define FLOAT_H

# include "vs_type.h"

# define POSITIVE 1
# define NEGATIVE -1

# define FLOAT_MAX_EXPONENT 1024

# define FLOAT32_MAX 3.40282346e38
# define FLOAT32_MIN -3.40282346e38

# define FLOAT64_MAX 1.7976931348623157e308
# define FLOAT64_MIN -1.7976931348623157e308

# define FLOAT32_CLOSE_ZERO_POSITIVE 1.4e-45
# define FLOAT32_CLOSE_ZERO_NEGATIVE -1.4e-45

# define FLOAT64_CLOSE_ZERO_POSITIVE 4.9406564584124654e-324
# define FLOAT64_CLOSE_ZERO_NEGATIVE -4.9406564584124654e-324

# define DOUBLE_BIAS_NORMALISE 1023
# define DOUBLE_BIAS_DENORMALISE 1022

typedef union u_float64{
	double	f;
	t_ui64	ui;
	struct {
		t_ui64	mantissa	: 52;
		t_ui64	exponent_biais : 11;
		t_ui64	sign	: 1;
	};
}	t_u_float64;

typedef struct s_round {
	t_ui32	nbr_digit : 16;
	t_ui32	intpart : 1;
	t_ui32	decpart : 1;
}	t_round;

/* float64_get --------------------------------------------------------------*/
int			float64_get_sign(t_float64 f);
int			float64_get_exponent(t_float64 f);
t_ui64		float64_get_mantissa(t_float64 f);
t_float64	float64_get_decimal_part(t_float64 nbr);

/* nbr digit ----------------------------------------------------------------*/

int			nbr_digit_si32(int n);
int			nbr_digit_si64(t_si64 n);
int			nbr_digit_ui32(t_ui32 n);
int			nbr_digit_ui64(t_ui64 n);
t_ui16		nbr_digit_float64_integer_part(t_float128 n);

/* mvs_10pow ----------------------------------------------------------------*/
t_float128	vs_10pow(t_ui16 p);

#endif
