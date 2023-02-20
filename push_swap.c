/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:54:20 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/20 19:34:34 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (ft_ifsorted(data))
		exit(0);
	data.a_size = (unsigned int)data.iargs_len + 1;
	data.b_size = 0;
	ft_index_init(&data);
	ft_sorting_type(&data);
	ft_clean(&data, argc);
}
