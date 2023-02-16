/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheap_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:15:09 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/16 17:15:08 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cheap_rrr(t_stack *cheap, t_data *data)
{
	while (cheap->cost_a != 0 || cheap->cost_b != 0)
	{
		if (cheap->cost_a < 0 && cheap->cost_b < 0)
		{
			ft_rrr(data);
			cheap->cost_a++;
			cheap->cost_b++;
		}
		if (cheap->cost_a == 0 && ft_abs(cheap->cost_b) > 0)
		{
			ft_rrb(data);
			cheap->cost_b++;
		}
		else if (ft_abs(cheap->cost_a) > 0 && cheap->cost_b == 0)
		{
			ft_rra(data);
			cheap->cost_a++;
		}
	}
	ft_pa(data);
}

void	ft_cheap_r(t_stack *cheap, t_data *data)
{
	while (cheap->cost_a != 0 || cheap->cost_b != 0)
	{
		if (cheap->cost_a > 0 && cheap->cost_b > 0)
		{
			ft_rr(data);
			cheap->cost_a--;
			cheap->cost_b--;
		}
		if (cheap->cost_a == 0 && ft_abs(cheap->cost_b) > 0)
		{
			ft_rb(data);
			cheap->cost_b--;
		}
		else if (cheap->cost_a > 0 && ft_abs(cheap->cost_b) == 0)
		{
			ft_ra(data);
			cheap->cost_a--;
		}
	}
	ft_pa(data);
}

void	ft_cheap_mov(t_stack *cheap, t_data *data)
{
	while (cheap->cost_a != 0 || cheap->cost_b != 0)
	{
		if (cheap->cost_a > 0)
		{
			ft_ra(data);
			cheap->cost_a--;
		}
		else if (cheap->cost_a < 0)
		{
			ft_rra(data);
			cheap->cost_a++;
		}
		if (cheap->cost_b > 0)
		{
			ft_rb(data);
			cheap->cost_b--;
		}
		else if (cheap->cost_b < 0)
		{
			ft_rrb(data);
			cheap->cost_b++;
		}
	}
	ft_pa(data);
}
