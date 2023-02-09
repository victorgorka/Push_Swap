#include "push_swap.h"

/*	-push all to stack 'b' but save 3
 *	-push first the smaller ones
 * */
void	ft_push_to_b(t_data *data)
{
	unsigned int	i;
	unsigned int	num_elemnts;

	num_elemnts = data->a_size;
	i = 0;
	while (data->a->a_size > 6 && data->a_size < num_elemnts / 2)	
	{
		if (data->a->index <= data->a_size / 2)
			ft_pb(data);
		else
			ft_ra(data);
		i++;
	}
	while (data->a_size > 3)
		ft_pb(data);
}

void	ft_main_algo(t_data *data)
{
	ft_push_to_b(data);
	ft_small_sort(data);
}
