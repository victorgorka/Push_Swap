/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:54:20 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/06 15:25:11 by vde-prad         ###   ########.fr       */
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

void	ft_swap(t_stack	**x)
{
	t_stack	*aux;

	aux = (*x)->next;
	(*x)->next = (*x)->next->next;
	aux->next = *x;
	(*x) = aux;
}

void	ft_rotate(t_stack **x)
{
	t_stack	*tail;
	t_stack	*aux;

	aux = *x;
	tail = *x;
	while (tail->next)
		tail = tail->next;
	tail->next = aux;
	*x = (*x)->next;
	aux->next = NULL;
}

void	ft_revrotate(t_stack **x)
{
	t_stack	*tail;
	t_stack	*aux;

	aux = *x;
	tail = *x;
	while (tail->next)
		tail = tail->next;
	while (aux->next != tail)
		aux = aux->next;
	tail->next = *x;
	*x = tail;
	aux->next = NULL;
}

void	ft_printstack(t_data *data)
{
	t_stack			node;
	unsigned int	i;

	i = 0;
	node = *data->a;
	while (i <= data->iargs_len)
	{
		ft_printf("%d\n", node.value);
		if (i++ != data->iargs_len)
			node = *node.next;
	}
}

void	check(void)
{
	system("leaks push_swap");
}

void	ft_clean(t_data *data, int argc)
{
	unsigned int	i;

	i = 0;
	ft_cleanstack(&data->a);
	ft_cleanstack(&data->b);
	if (argc == 2)
	{
		while (data->args[i])
			free(data->args[i++]);
		free(data->args);
	}
	free(data->iargs);
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
	ft_revrotate(&data.a);
	ft_printstack(&data);
	ft_clean(&data, argc);
	atexit(check);
}
//if 1st number is highest -->ra
//if 2nd numbeer is highest -->rra
//if  1st  number > 2nd number --> sa
// TODO pop y push
