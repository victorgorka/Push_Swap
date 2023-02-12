#include "push_swap.h"

void	ft_assign_pos(t_stack **x)
{
	t_stack *aux;
	int		i;

	i = 0;
	aux = *x;
	while (aux)
	{
		aux->pos = i++;
		aux = aux->next;	
	}
}

int	ft_calc_targ(t_data *data, int b_indx)
{
	t_stack	*aux_a;
	int		tar_indx;
	int		tar_pos;
	int		trig;

	trig = 1;
	tar_indx = INT_MAX;
	aux_a = data->a;
	while (aux_a)
	{
		if (trig && aux_a->index > b_indx && aux_a->index < tar_indx)
		{
			tar_indx = aux_a->index;
			tar_pos = aux_a->pos;
		} else if (!trig && aux_a->index < tar_indx)
		{
			tar_indx = aux_a->index;
			tar_pos = aux_a->pos;
		} else if (!aux_a->next && tar_indx == INT_MAX && trig--)
			aux_a = data->a;
		aux_a = aux_a->next;
	}
	return (tar_pos);
}

void	ft_target(t_data *data)
{
	t_stack	*aux_b;

	aux_b = data->b;
	while (aux_b)
	{
		aux_b->target_pos = ft_calc_targ(data, aux_b->index);
		aux_b = aux_b->next;
	}
}
