/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_gradient.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 03:09:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/22 19:21:50 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_GRADIENT_H
# define COLOR_GRADIENT_H

# include "libft.h"
# include <math.h>

typedef struct s_gradiant{
	t_vec3f	gradiant;
	t_vec3f	accu;
}	t_grad;

t_grad	color_gradiant(t_color start, t_color end, t_vec2i d);
t_color	color_gradiant_add(t_grad *grad);
#endif