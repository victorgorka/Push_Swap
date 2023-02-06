/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:50:38 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/06 17:45:38 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_push(t_stack **x, t_stack **y)
{
	t_stack	*aux;

	aux = (*x)->next;
	if (!*y)
		(*x)->next = NULL;
	else
		(*x)->next = *y;
	*y = *x;
	*x = aux;
}

void	ft_pa(t_data *data)
{
	ft_push(&data->b, &data->a);
	ft_printf("pa\n");
}

void	ft_pb(t_data *data)
{
	ft_push(&data->a, &data->b);
	ft_printf("pb\n");
}
