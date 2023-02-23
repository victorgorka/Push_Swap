/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:56:37 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/23 13:31:54 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_stack	**x)
{
	t_stack	*aux;

	if ((*x) == NULL)
		return ;
	aux = (*x)->next;
	(*x)->next = (*x)->next->next;
	aux->next = *x;
	(*x) = aux;
}

void	ft_sa(t_data *data)
{
	if (data->a_size > 1)
		ft_swap(&data->a);
}

void	ft_sb(t_data *data)
{
	if (data->b_size > 1)
		ft_swap(&data->b);
}

void	ft_ss(t_data *data)
{
	if (data->a_size > 1)
		ft_swap(&data->a);
	if (data->b_size > 1)
		ft_swap(&data->b);
}
