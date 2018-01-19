#ifndef MATH_3D_HEADER
#define MATH_3D_HEADER

#include <math.h>
#include <stdio.h>

typedef struct s_matrix t_matrix;
typedef union 
{
	float m[4][4];
    struct	s_matrix
    {
		float m00, m01, m02, m03;
		float m10, m11, m12, m13;
		float m20, m21, m22, m23;
		float m30, m31, m32, m33;
	}	   	t_matrix;
} mat4_t;



mat4_t  mat4(t_matrix matrice);
void    ft_print_mat4(mat4_t matrice);
mat4_t  m4_identity();




#endif