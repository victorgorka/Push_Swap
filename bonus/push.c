/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:50:38 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/22 12:52:43 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(t_stack **x, t_stack **y)
{
	t_stack	*aux;

	if ((*x) == NULL)
		return ;
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
}

void	ft_pb(t_data *data)
{
	ft_push(&data->a, &data->b);
}
