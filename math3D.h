#ifndef MATH_3D_HEADER
#define MATH_3D_HEADER

#include <math.h>

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

vec3_t	vec3(float x, float y, float z);
vec4_t	vec4(float x, float y, float z, float w);
vec4_t 	m4_mult_pos(mat4_t matrix, vec4_t position);
mat4_t  mat4(t_matrix matrice);
void    ft_print_mat4(mat4_t matrice);
mat4_t  mult_mat4(mat4_t matrice1, mat4_t matrice2);
mat4_t	m4_translation(vec3_t offset);
mat4_t	m4_scaling(vec3_t scale);
mat4_t	m4_rotationx(float angle);
mat4_t	m4_rotationy(float angle);
mat4_t	m4_rotationz(float angle);
mat4_t	m4_rotation(float angle, vec3_t axis);
mat4_t	m4_transpose(mat4_t matrice);
mat4_t 	m4_perspective(float vertical_field_of_view_in_deg, float aspect_ratio, float near_view_distance, float far_view_distance);

#endif