/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_functions2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:23:47 by mpham             #+#    #+#             */
/*   Updated: 2018/02/13 09:54:03 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mat4	m4_translation(t_vec3 offset)
{
	t_mat4	matrix;

	matrix = m4_identity();
	matrix.data[0][3] = offset.x;
	matrix.data[1][3] = offset.y;
	matrix.data[2][3] = offset.z;
	return (matrix);
}

t_mat4	m4_scaling(t_vec3 scale)
{
	t_mat4	matrix;

	matrix = m4_identity();
	matrix.data[0][0] = scale.x;
	matrix.data[1][1] = scale.y;
	matrix.data[2][2] = scale.z;
	return (matrix);	
}

t_mat4	m4_rotationx(float angle)
{
	t_mat4	matrix;

	matrix = m4_identity();
	matrix.data[1][1] = cos(angle);
	matrix.data[1][2] = sin(angle);
	matrix.data[2][1] = -sin(angle);
	matrix.data[2][2] = cos(angle);
	return (matrix);
}

t_mat4	m4_rotationy(float angle)
{
	t_mat4	matrix;

	matrix = m4_identity();
	matrix.data[0][0] = cos(angle);
	matrix.data[2][0] = sin(angle);
	matrix.data[0][2] = -sin(angle);
	matrix.data[2][2] = cos(angle);
	return (matrix);
}

t_mat4	m4_rotationz(float angle)
{
	t_mat4	matrix;

	matrix = m4_identity();
	matrix.data[0][0] = cos(angle);
	matrix.data[0][1] = sin(angle);
	matrix.data[1][0] = -sin(angle);
	matrix.data[1][1] = cos(angle);
	return (matrix);	
}
