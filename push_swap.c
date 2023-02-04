/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:54:20 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/04 18:43:42 by vde-prad         ###   ########.fr       */
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

void	ft_printstack(t_data *data)
{
	t_stack			node;
	unsigned int	i;

	i = 0;
	node = *data->a;
	while (i <= data->iargs_len)
	{
		puts("hola");
		ft_printf("%d\n", node.value);
		if (i++ != data->iargs_len)
			node = *node.next;
	}
}

void	check(void)
{
	system("leaks push_swap");
}

int	main(int argc, char	**argv)
{
	t_data	data;
	int		i;

	i = 0;
	data.b = NULL;
	if (argc == 1)
		return (0);
	else if (!ft_check_args(argc, argv, &data))
		ft_error();
	ft_fillstack(&data);
	ft_printstack(&data);
	ft_cleanstack(&data.a);
	ft_cleanstack(&data.b);
	puts(data.args[2]);
	while (data.args[i])
	{
		puts("free i");
		free(data.args[i++]);
	}
	free(data.args);
	free(data.iargs);
	atexit(check);
}
//if 1st number is highest -->ra
//if 2nd numbeer is highest -->rra
//if  1st  number > 2nd number --> sa
// TODO pop y push
