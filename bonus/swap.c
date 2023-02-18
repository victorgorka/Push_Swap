/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:56:37 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/18 14:53:59 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_stack	**x)
{
	t_stack	*aux;

	aux = (*x)->next;
	(*x)->next = (*x)->next->next;
	aux->next = *x;
	(*x) = aux;
}

void	ft_sa(t_data *data)
{
	ft_swap(&data->a);
}

void	ft_sb(t_data *data)
{
	ft_swap(&data->b);
}

void	ft_ss(t_data *data)
{
	ft_swap(&data->a);
	ft_swap(&data->b);
}
