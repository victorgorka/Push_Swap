/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:54:20 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/06 17:58:28 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_printstack(t_stack **x)
{
	t_stack			*node;
	unsigned int	i;

	i = 0;
	node = *x;
	if (!node)
		ft_printf("null");
	else
	{
		while (node->next)
		{
			ft_printf("%d\n", node->value);
			node = node->next;
			if (!node->next)
				ft_printf("%d\n", node->value);
		}
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
	ft_pb(&data);
	ft_pb(&data);
	ft_pb(&data);
	ft_pb(&data);
	ft_rrr(&data);
	puts("stack a");
	ft_printstack(&data.a);
	puts("stack b");
	ft_printstack(&data.b);
	ft_clean(&data, argc);
	atexit(check);
}
//if 1st number is highest -->ra
//if 2nd numbeer is highest -->rra
//if  1st  number > 2nd number --> sa
// TODO pop y push
