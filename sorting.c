#include "push_swap.h"

/*	-push all to stack 'b' but save 3
 *	-push first the smaller ones
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
}
