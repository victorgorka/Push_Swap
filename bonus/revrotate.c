/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:56:59 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/22 12:58:32 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_revrotate(t_stack **x)
{
	t_stack	*tail;
	t_stack	*aux;

	aux = *x;
	tail = *x;
	if ((*x) == NULL)
		return ;
	while (tail->next)
		tail = tail->next;
	while (aux->next != tail)
		aux = aux->next;
	tail->next = *x;
	*x = tail;
	aux->next = NULL;
}

void	ft_rra(t_data *data)
{
	ft_revrotate(&data->a);
}

void	ft_rrb(t_data *data)
{
	ft_revrotate(&data->b);
}

void	ft_rrr(t_data *data)
{
	ft_revrotate(&data->a);
	ft_revrotate(&data->b);
}
