/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:29:54 by mpham             #+#    #+#             */
/*   Updated: 2018/02/12 18:28:34 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math3d.h"

void	ft_print_matrice(t_matrice *matrice)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 4)
	{
		while (y < 4)
		{
			printf("%d ", matrice[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
}
