/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:46:37 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/04 17:53:14 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*ft_newnode(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->value = value;
	node->index = -1;
	node->pos = -1;
	node->target_pos = -1;
	node->cost_a = -1;
	node->cost_b = -1;
	node->next = NULL;
	return (node);
}

void ft_fillstack(t_data *data)
{
	t_stack			*node;
	unsigned int	i;

	i = 0;
	data->a = ft_newnode(data->iargs[i++]);
	node = data->a;
	while (i <= data->iargs_len)
	{
		node->next = ft_newnode(data->iargs[i++]);
		node = node->next;
	}
}

void	ft_cleanstack(t_stack **x)
{
	t_stack *node;

	while (*x)
	{
		node = *x;
		*x = (*x)->next;
		free(node);
	}
}
