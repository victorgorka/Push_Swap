/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:56:51 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/23 13:30:28 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate(t_stack **x)
{
	t_stack	*tail;
	t_stack	*aux;

	aux = *x;
	tail = *x;
	if ((*x) == NULL)
		return ;
	while (tail->next)
		tail = tail->next;
	tail->next = aux;
	*x = (*x)->next;
	aux->next = NULL;
}

void	ft_ra(t_data *data)
{
	if (data->a_size > 1)
		ft_rotate(&data->a);
}

void	ft_rb(t_data *data)
{
	if (data->b_size > 1)
		ft_rotate(&data->b);
}

void	ft_rr(t_data *data)
{
	if (data->a_size > 1)
		ft_rotate(&data->a);
	if (data->b_size > 1)
		ft_rotate(&data->b);
}
