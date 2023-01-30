/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:54:20 by vde-prad          #+#    #+#             */
/*   Updated: 2023/01/30 19:32:05 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_push(t_stack **x, t_stack **y)
{
	t_stack	*aux;

	aux = (*x)->next;
	if (!*y)
		(*x)->next = NULL;
	else
		(*x)->next = *y;
	*y = *x;
	*x = aux;
}

// void	check(void)
// {
//     system("leaks push_swap");
// }
// 
// int	main(int argc, char	**argv)
// {
//     t_stack	*a;
//     t_stack	*b;
//     t_data	data;
// 
//     data.argc = argc;
//     b = NULL;
//     if (argc > 1 && !ft_check_args(argc, argv, &data))
//         ft_error();
//     else
//         return (0);
//     ft_fillstack(&a, argc, data.args);
//     t_stack *n = a;
//     while (n)
//     {
//         printf("value: %d\n", n->value);
//         n = n->next;
//     }
//     puts("\n");
//     ft_push(&a, &b);
//     n = a;
//     while (n)
//     {
//         printf("value: %d\n", n->value);
//         n = n->next;
//     }
//     n = a;
//     ft_cleanstack(&a);
//     ft_cleanstack(&b);
//     atexit(check);
// }
//if 1st number is highest -->ra
//if 2nd numbeer is highest -->rra
//if  1st  number > 2nd number --> sa
// TODO pop y push
