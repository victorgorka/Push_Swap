/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:54:20 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/06 20:07:35 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_printstack(t_stack *node)
{
	unsigned int	i;

	i = 0;
	if (!node)
		ft_printf("null\n");
	while (node)
	{
		ft_printf("%d\n", node->value);
		node = node->next;
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

unsigned int ft_count_stack(t_data data)
{
	unsigned int	i;

	i = 0;
	while (data.a)
	{
		data.a = data.a->next;
		i++;
	}
	return (i);
}

int	ft_issorted(t_data	data)
{
	if (ft_count_stack(data) > 1)
	{
		while (data.a)
		{
			puts("h");
			if (data.a->next && data.a->value < data.a->next->value)
				data.a = data.a->next;
			else
				return (0);
		}
	}
	return (1);
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
	puts("stack a");
	ft_printstack(data.a);
	puts("stack b");
	ft_printstack(data.b);
	if (ft_issorted(data))
		puts("is sorted");
	else
		puts("not sorted");
	ft_clean(&data, argc);
	atexit(check);
}
//if 1st number is highest -->ra
//if 2nd numbeer is highest -->rra
//if  1st  number > 2nd number --> sa
// TODO pop y push
