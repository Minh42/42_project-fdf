/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 09:43:29 by mpham             #+#    #+#             */
/*   Updated: 2018/01/17 09:55:53 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"
# include <stdio.h>

void ft_print_list(t_list *list)
{
    t_list *tmp = list;
    if (tmp == NULL)
    {
        ft_putstr("erreur");
    }
    while (tmp)
    {
        printf("%d", ((t_point *)(tmp->content))->x);
        printf("%d", ((t_point *)(tmp->content))->y);
        printf("%d", ((t_point *)(tmp->content))->z);
        printf("%s", ((t_point *)(tmp->content))->color);
        tmp = tmp->next;
    }
    
}
