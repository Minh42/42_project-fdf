/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_functions2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:23:47 by mpham             #+#    #+#             */
/*   Updated: 2018/02/12 19:09:44 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math3d.h"

t_mat4	m4_translation(t_vec3 offset)
{
	t_mat4	matrice;

	matrice = mat4((t_matrix)
		{1, 0, 0, offset.x,
		0, 1, 0, offset.y,
		0, 0, 1, offset.z,
		0, 0, 0, 1});
	return (matrice);
}

t_mat4	m4_scaling(t_vec3 scale)
{
	t_mat4	matrice;

	matrice = mat4((t_matrix)
		{scale.x, 0, 0, 0,
		0, scale.y, 0, 0,
		0, 0, scale.z, 0,
		0, 0, 0, 1});
	return (matrice);
}

t_mat4	m4_rotationx(float angle)
{
	t_mat4	matrice;

	matrice = mat4((t_matrix)
		{1, 0, 0, 0,
		0, cos(angle), -sin(angle), 0,
		0, sin(angle), cos(angle), 0,
		0, 0, 0, 1});
	return (matrice);
}

t_mat4	m4_rotationy(float angle)
{
	t_mat4	matrice;

	matrice = mat4((t_matrix)
		{cos(angle), 0, sin(angle), 0,
		0, 1, 0, 0,
		-sin(angle), 0, cos(angle), 0,
		0, 0, 0, 1});
	return (matrice);
}

t_mat4	m4_rotationz(float angle)
{
	t_mat4	matrice;

	matrice = mat4((t_matrix)
		{cos(angle), -sin(angle), 0, 0,
		sin(angle), cos(angle), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1});
	return (matrice);
}
