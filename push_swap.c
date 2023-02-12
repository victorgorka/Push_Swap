/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:54:20 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/09 17:12:47 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_printstack(t_stack *node)
{
	if (!node)
		printf("null\n");
	while (node)
	{
		printf("val: %d ind: %d pos: %d tar_pos: %d\n", node->value, node->index, node->pos, node->target_pos);
		node = node->next;
	}
}

void	check(void)
{
	system("leaks push_swap");
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

int	ft_ifsorted(t_data	data)
{
	if (ft_count_stack(data) > 1)
	{
		while (data.a->next)
		{
			if (data.a->value < data.a->next->value)
				data.a = data.a->next;
			else
				return (0);
		}
	}
	return (1);
}

void	ft_sorting_type(t_data *data)
{
	if (!ft_ifsorted(*data) && data->a_size <= 3)
		ft_small_sort(data);
	else
		ft_main_algo(data);
}

int	main(int argc, char	**argv)
{
	t_data	data;

	data.b = NULL;
	if (argc == 1)
		return (0);
	else if (!ft_check_args(argc, argv, &data))
		ft_error();
	ft_fillstack(&data);
	data.a_size = (unsigned int)data.iargs_len + 1;
	data.b_size = 0;
	puts("stack a");
	ft_printstack(data.a);
	puts("stack b");
	ft_printstack(data.b);
	ft_index_init(&data);
	//ft_sorting_type(&data);
	ft_pb(&data);
	ft_pb(&data);
	ft_pb(&data);
	ft_target(&data);
	puts("stack a");
	ft_printstack(data.a);
	puts("stack b");
	ft_printstack(data.b);
	ft_clean(&data, argc);
	atexit(check);
}
//if 1st number is highest -->ra
//if 2nd numbeer is highest -->rra
//if  1st  number > 2nd number --> sa
// TODO pop y push
