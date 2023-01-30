/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:46:37 by vde-prad          #+#    #+#             */
/*   Updated: 2023/01/30 18:47:32 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


t_stack	*ft_newnode(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->value = value;
	node->index = 0;
	node->pos = 0;
	node->target_pos = 0;
	node->cost_a = 0;
	node->cost_b = 0;
	node->next = 0;
	return (node);
}

void ft_fillstack(t_stack **a, int argc, char **argv)
{
	t_stack	*node;
	int		i;

	i = 1;
	*a = ft_newnode(atoi(argv[i++]));
	node = *a;
	while (i < argc)
	{
		node->next = ft_newnode(atoi(argv[i++]));
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
