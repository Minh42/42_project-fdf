/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 11:41:25 by mpham             #+#    #+#             */
/*   Updated: 2018/01/19 12:50:04 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"
# include "math3D.h"

// 3D Vectors

vec3_t  vec3(float x, float y, float z)
{
    return (vec3_t)
    {
        x, y , z
    };
}




void  ft_print_vec3(vec3_t vec3)
{
    ft_putnbr(vec3.x);
    ft_putchar('\n');
    ft_putnbr(vec3.y);
    ft_putchar('\n');
    ft_putnbr(vec3.z);
}



// Matrice 4 x 4

mat4_t  mat4(t_matrix m) 
{
    return (mat4_t)
    {
        {{m.m00, m.m01, m.m02, m.m03},
         {m.m10, m.m11, m.m12, m.m13},
         {m.m20, m.m21, m.m22, m.m23},
         {m.m30, m.m31, m.m32, m.m33}}
    };
}

void    ft_print_mat4(mat4_t matrice)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < 4)
    {
        while (j < 4)
        {
            ft_putnbr(matrice.m[i][j]);
            ft_putchar('|');
            j++;
        }
        if (i < 3)
            ft_putchar('\n');
        j = 0;
        i++;
    }
}

mat4_t  m4_identity(void)
{
    return mat4((t_matrix)
		{1, 0, 0, 0,
		 0, 1, 0, 0,
		 0, 0, 1, 0,
		 0, 0, 0, 1}
    );
}

mat4_t  ft_mult_mat4(mat4_t m1, mat4_t m2)
{
    int     i;
    int     j;
    int     k;
    mat4_t  result;
    
    i = 0;
    j = 0;
    k = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            k = 0;
            result.m[i][j] = 0;
            while (k < 4)
            {
                result.m[i][j] += m1.m[i][k] * m2.m[k][j];
                k++;
            }
            j++;
        }
        i++;
    }
    return (result);
}
