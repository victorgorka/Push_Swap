/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:52:59 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/14 19:20:53 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cost(t_data *data)
{
	data->tmp_b = data->b;
	while (data->tmp_b)
	{
		if (data->tmp_b->pos > data->b_size / 2)
			data->tmp_b->cost_b = (data->b_size - data->tmp_b->pos) * -1;
		else
			data->tmp_b->cost_b = data->tmp_b->pos;
		if (data->tmp_b->target_pos > data->a_size / 2)
			data->tmp_b->cost_a = (data->a_size - data->tmp_b->target_pos) * -1;
		else
			data->tmp_b->cost_a = data->tmp_b->target_pos;
		data->tmp_b = data->tmp_b->next;
	}
}

void	ft_cheapest(t_data *data)
{
	t_stack	*cheap;
	int		tot_cost;

	tot_cost = INT_MAX;
	cheap = data->b;
	data->tmp_b = data->b;
	while (data->tmp_b)
	{
		if (data->tmp_b->cost_a < 0 && data->tmp_b->cost_b < 0)
		{
			if (data->tmp_b->cost_a < data->tmp_b->cost_b)
			{
				tot_cost = ft_absolute_nb(data->tmp_b->cost_a);
			}
		}
	}
}