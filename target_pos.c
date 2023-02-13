/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:03:47 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/13 18:13:39 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_assign_pos(t_stack **x)
{
	t_stack	*aux;
	int		i;

	i = 0;
	aux = *x;
	while (aux)
	{
		aux->pos = i++;
		aux = aux->next;
	}
}

static int	ft_calc_targ(t_data *data, int b_indx)
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
		}
		else if (!trig && aux_a->index < tar_indx)
		{
			tar_indx = aux_a->index;
			tar_pos = aux_a->pos;
		}
		aux_a = aux_a->next;
		if (!aux_a && tar_indx == INT_MAX && trig--)
			aux_a = data->a;
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