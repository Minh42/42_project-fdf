#ifndef MATH_3D_HEADER
#define MATH_3D_HEADER

#include <math.h>
#include <stdio.h>


typedef struct s_matrice
{
  int       nb_ligne;    
  int       nb_col;       
  double    *matrice;  
}              t_matrice;

typedef union 
{
	float m[4][4];
    struct 
    {
		float m00, m01, m02, m03;
		float m10, m11, m12, m13;
		float m20, m21, m22, m23;
		float m30, m31, m32, m33;
	};
} mat4_t;







mat4_t  mat4(float m00, float m01, float m02, float m03, 
    float m10, float m11, float m12, float m13,
    float m20, float m21, float m22, float m23, 
    float m30, float m31, float m32, float m33);
void    ft_print_mat4(mat4_t matrice);
mat4_t  m4_identity();




#endif