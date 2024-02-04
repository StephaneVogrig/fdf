/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:03:51 by stephane          #+#    #+#             */
/*   Updated: 2024/02/04 22:32:37 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include "mlx_linux/mlx_int.h"
# include "mlx_linux/mlx.h"

# define WINDOW_WIDTH 1600
# define WINDOW_HEIGTH 900

typedef struct s_data{
	void	*mlx;
	void	*win;
	t_img	*img;
} t_data;

#endif