#ifndef MATH_3D_HEADER
#define MATH_3D_HEADER

#include <math.h>
#include <stdio.h>

// 3D Vectors

typedef struct
{
	float x, y, z;
}				vec3_t;

vec3_t vec3(float x, float y, float z);
// vec3_t v3_add
// vec3_t v3_mul


// Matrice 4 x 4

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
mat4_t  ft_mult_mat4(mat4_t matrice1, mat4_t matrice2);



#endif