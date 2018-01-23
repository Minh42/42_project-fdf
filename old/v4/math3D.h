#ifndef MATH_3D_HEADER
#define MATH_3D_HEADER

#include <math.h>
#include <stdio.h>

typedef struct
{
	float x, y, z;
}				vec3_t;

typedef struct
{
	float x, y, z, w;
}				vec4_t;

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

// 3D Vectors

vec3_t	vec3(float x, float y, float z);
vec3_t	vec3_add(vec3_t a, vec3_t b);
vec3_t	vec3_sub(vec3_t a, vec3_t b);
vec3_t	vec3_mult(vec3_t a, vec3_t b);
vec3_t	vec3_div(vec3_t a, vec3_t b);
void	ft_print_vec3(vec3_t vec3);

// 4D Vectors

vec4_t	vec4(float x, float y, float z, float w);
vec4_t 	m4_mult_pos(mat4_t matrix, vec4_t position);

// Matrice 4 x 4

mat4_t  mat4(t_matrix matrice);
void    ft_print_mat4(mat4_t matrice);
mat4_t  m4_identity();
mat4_t  ft_mult_mat4(mat4_t matrice1, mat4_t matrice2);
mat4_t	m4_translation(vec3_t offset);
mat4_t	m4_scaling(vec3_t scale);
mat4_t	m4_rotationx(float angle);
mat4_t	m4_rotationy(float angle);
mat4_t	m4_rotationz(float angle);
mat4_t	m4_rotation(float angle, vec3_t axis);
mat4_t	m4_transpose(mat4_t matrice);

#endif