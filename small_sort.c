/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:04:18 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/18 21:16:29 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_small_sort(t_data *data)
{
	if (data->iargs_len + 1 == 2)
	{
		ft_sa(data);
		return ;
	}
	while (!ft_ifsorted(*data))
	{
		if (data->a->value > data->a->next->value
			&& data->a->value > data->a->next->next->value)
			ft_ra(data);
		else if (data->a->next->value > data->a->value
			& data->a->next->value > data->a->next->next->value)
			ft_rra(data);
		else if (data->a->value > data->a->next->value)
			ft_sa(data);
	}
}
