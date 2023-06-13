/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_math.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfregni <tfregni@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:06:27 by tfregni           #+#    #+#             */
/*   Updated: 2023/06/13 17:20:37 by tfregni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_MATH_H
# define MATRIX_MATH_H
# include "minirt.h"

typedef float	t_matrix_trans[4][4];

t_matrix	mx_get_identity(void);
/* TRANSFORMATIONS */
t_matrix	mx_rotate_x(t_matrix mx, float x);
t_matrix	mx_rotate_y(t_matrix mx, float y);
t_matrix	mx_rotate_z(t_matrix mx, float z);
t_matrix	mx_transl(t_matrix mx, t_point_3d p);
t_point_3d	transform(t_point_3d p, t_matrix_trans m);
/* OPERATIONS */
t_matrix	mx_cross(t_matrix a, t_matrix b);
t_point_3d	mx_mult(t_matrix m, t_point_3d p);

#endif