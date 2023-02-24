/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:46:37 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/24 19:40:20 by vde-prad         ###   ########.fr       */
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

void	ft_fillstack(t_data *data)
{
	t_stack			*node;
	unsigned int	i;

	i = 0;
	data->a = ft_newnode(data->iargs[i]);
	node = data->a;
	node->pos = i++;
	while (i <= data->iargs_len)
	{
		node->next = ft_newnode(data->iargs[i]);
		node = node->next;
		node->pos = i++;
	}
}

void	ft_cleanstack(t_stack **x)
{
	t_stack	*node;

	while (*x)
	{
		node = *x;
		*x = (*x)->next;
		free(node);
	}
}

void	ft_clean(t_data *data, int argc)
{
	unsigned int	i;

	i = 0;
	ft_cleanstack(&data->a);
	ft_cleanstack(&data->b);
	if (argc == 2 && data->args != NULL)
	{
		while (data->args[i])
			free(data->args[i++]);
		free(data->args);
	}
	if (data->iargs != NULL)
		free(data->iargs);
}

void	ft_index_init(t_data *data)
{
	t_stack	*aux;
	t_stack	*max;

	data->iargs_lenaux = data->iargs_len;
	while (data->iargs_lenaux-- + 1 > 0)
	{
		aux = data->a;
		max = NULL;
		while (aux)
		{
			if (aux->index == -1 && max)
			{
				if (aux->value > max->value)
					max = aux;
				aux = aux->next;
			}
			else
			{
				if (!max && aux->index == -1)
					max = aux;
				aux = aux->next;
			}
		}
		max->index = data->iargs_lenaux + 2;
	}
}
