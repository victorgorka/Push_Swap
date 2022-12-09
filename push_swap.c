/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:54:20 by vde-prad          #+#    #+#             */
/*   Updated: 2022/12/09 20:15:37 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"


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

void	ft_push(t_stack x)
{


}
// void	check(void)
// {
//     system("leaks push_swap");
// }
int	main(int argc, char	**argv)
{
	t_stack	*a;	

	// atexit(check);
	a = NULL;
	if (argc > 1)
		ft_fillstack(&a, argc, argv);
	else
		return (0);

	t_stack *n = a;
	while (n)
	{
		printf("value: %d\n", n->value);
		n = n->next;
	}
	ft_cleanstack(&a);
}
//if 1st number is highest -->ra
//if 2nd numbeer is highest -->rra
//if  1st  number > 2nd number --> sa
//
// TODO pop y push
