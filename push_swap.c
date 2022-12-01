/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:54:20 by vde-prad          #+#    #+#             */
/*   Updated: 2022/12/01 17:27:52 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"


t_stack		*ft_newnode()
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->value = 0;
	node->index = 0;
	node->pos = 0;
	node->target_pos = 0;
	node->cost_a = 0;
	node->cost_b = 0;
	node->next = 0;
	return (node);
}

ft_fillstack(t_stack **a, t_stack new)
{
	
}

int	main(int argc, char	**argv)
{
	t_stack	*a;

	a = ft_newnode();
	while (argc-- > 1)
		ft_fillstack(&a, &ft_newnode());
}
//if 1st number is highest -->ra
//if 2nd numbeer is highest -->rra
//if  1st  number > 2nd number --> sa
//
// TODO pop y push
