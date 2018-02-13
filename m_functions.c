/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 11:41:25 by mpham             #+#    #+#             */
/*   Updated: 2018/02/13 09:54:14 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3	vec3(float x, float y, float z)
{
	t_vec3	vec3;

	vec3.x = x;
	vec3.y = y;
	vec3.z = z;
	return (vec3);
}

t_vec4	vec4(float x, float y, float z, float w)
{
	t_vec4	vec4;

	vec4.x = x;
	vec4.y = y;
	vec4.z = z;
	vec4.w = w;
	return (vec4);
}

t_mat4	m4_identity(void)
{
	int		i;
	int		j;
	t_mat4	matrix;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			matrix.data[i][j] = (i == j) ? 1 : 0;
	}
	return (matrix);
}

t_mat4	mult_mat4(t_mat4 m1, t_mat4 m2)
{
	int		i;
	int		j;
	int		k;
	t_mat4	result;

	i = 0;
	j = 0;
	k = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			result.data[i][j] = 0;
			while (k < 4)
			{
				result.data[i][j] += m1.data[i][k] * m2.data[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (result);
}

t_vec4	m4_mult_pos(t_mat4 matrix, t_vec4 position)
{
	t_vec4 result;

	result = vec4(matrix.data[0][0] * position.x + matrix.data[0][1] * position.y +
	matrix.data[0][2] * position.z + matrix.data[0][3] * position.w,
	matrix.data[1][0] * position.x + matrix.data[1][1] * position.y +
	matrix.data[1][2] * position.z + matrix.data[1][3] * position.w,
	matrix.data[2][0] * position.x + matrix.data[2][1] * position.y +
	matrix.data[2][2] * position.z + matrix.data[2][3] * position.w,
	matrix.data[3][0] * position.x + matrix.data[3][1] * position.y +
	matrix.data[3][2] * position.z + matrix.data[3][3] * position.w);
	return (result);
}
