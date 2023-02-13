/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:03:57 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/13 19:08:21 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	Push all to stack 'b' but save 3 but first push the smaller ones, then,
 *	push the last one until stack a have got 3 left
 * */

void	ft_push_to_b(t_data *data)
{
	unsigned int	num_elem;

	num_elem = data->a_size;
	while (data->a_size > 6 && data->b_size < num_elem / 2)	
	{
		if ((unsigned int)data->a->index <= num_elem / 2)
			ft_pb(data);
		else
			ft_ra(data);
	}
	while (data->a_size > 3)
		ft_pb(data);
}

void	ft_main_algo(t_data *data)
{
	ft_push_to_b(data);
	ft_small_sort(data);
	ft_target(data);
	ft_cost(data);
}
