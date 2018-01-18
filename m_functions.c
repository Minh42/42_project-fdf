/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 11:41:25 by mpham             #+#    #+#             */
/*   Updated: 2018/01/18 18:45:49 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"
# include "math3D.h"

// matrice 4 x 4

# include "fdf.h"
# include "math3D.h"

// matrice 4 x 4

mat4_t  mat4(t_matrix m) 
{
    return (mat4_t)
    {
		.m[0][0] = m.m00, .m[0][1] = m.m01, .m[0][2] = m.m02, .m[0][3] = m.m03,
		.m[1][0] = m.m10, .m[1][1] = m.m11, .m[1][2] = m.m12, .m[1][3] = m.m13,
		.m[2][0] = m.m20, .m[2][1] = m.m21, .m[2][2] = m.m22, .m[2][3] = m.m23,
		.m[3][0] = m.m30, .m[3][1] = m.m31, .m[3][2] = m.m32, .m[3][3] = m.m33
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
            j++;
        }
        if (i < 3)
            ft_putchar('\n');
        j = 0;
        i++;
    }
}

// mat4_t  m4_identity()
// {
//     return mat4(
// 		1, 0, 0, 0,
// 		0, 1, 0, 0,
// 		0, 0, 1, 0,
// 		0, 0, 0, 1
//     );
// }

// mat4_t  ft_mult_mat4(mat4_t matrice1, mat4_t matrice2)
// {
//     int i;
//     int j;
    
//     i = 0;
//     j = 0;
    



// }