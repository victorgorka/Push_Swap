/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:03:57 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/16 17:13:59 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*	Push all to stack 'b' but save 3, first push the smaller ones, then,
 *	push the last ones until stack a have got 3 left
 * */
void	ft_push_to_b(t_data *data)
{
	int	num_elem;

	num_elem = data->a_size;
	while (data->a_size > 6 && data->b_size < num_elem / 2)
	{
		if (data->a->index <= num_elem / 2)
			ft_pb(data);
		else
			ft_ra(data);
	}
	while (data->a_size > 3)
		ft_pb(data);
}

void	ft_final_rot(t_data *data)
{
	int	i;

	i = 0;
	data->tmp_a = data->a;
	while (data->tmp_a)
	{
		if (data->tmp_a->index == 1)
			break ;
		i++;
		data->tmp_a = data->tmp_a->next;
	}
	if (data->tmp_a->index < data->a_size / 2)
		while (data->a->index != 1)
			ft_ra(data);
	else if (data->tmp_a->index > data->a_size / 2)
		while (data->a->index != 1)
			ft_rra(data);
}

void	ft_main_algo(t_data *data)
{
	ft_push_to_b(data);
	ft_small_sort(data);
	while (data->b)
	{
		ft_target(data);
		ft_cost(data);
		ft_cheapest(data);
	}
	ft_final_rot(data);
}
