/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:57:17 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/22 13:01:24 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_choose_mov(t_data *data, char *line)
{
	if (!ft_strncmp(line, "pa\n", 4))
		ft_pa(data);
	else if (!ft_strncmp(line, "pb\n", 4))
		ft_pb(data);
	else if (!ft_strncmp(line, "ra\n", 4))
		ft_ra(data);
	else if (!ft_strncmp(line, "rb\n", 4))
		ft_rb(data);
	else if (!ft_strncmp(line, "rr\n", 4))
		ft_rr(data);
	else if (!ft_strncmp(line, "rra\n", 4))
		ft_rra(data);
	else if (!ft_strncmp(line, "rrb\n", 4))
		ft_rrb(data);
	else if (!ft_strncmp(line, "rrr\n", 4))
		ft_rrr(data);
	else if (!ft_strncmp(line, "sa\n", 4))
		ft_sa(data);
	else if (!ft_strncmp(line, "sb\n", 4))
		ft_sb(data);
	else if (!ft_strncmp(line, "ss\n", 4))
		ft_ss(data);
	else
		ft_error();
}

void	ft_iterlst(t_data *data)
{
	t_list	*mv_lst;
	t_list	*tmp;

	mv_lst = ft_lstnew((char *)get_next_line(0));
	while (ft_lstlast(mv_lst)->content)
		ft_lstadd_back(&mv_lst, ft_lstnew((char *)get_next_line(0)));
	tmp = mv_lst;
	while (tmp->content)
	{
		ft_choose_mov(data, (char *)tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear(&mv_lst, free);
}

int	main(int argc, char **argv)
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
	ft_index_init(&data);
	ft_iterlst(&data);
	if (ft_ifsorted(data) && data.b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_clean(&data, argc);
}
