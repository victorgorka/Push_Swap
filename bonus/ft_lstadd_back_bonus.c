/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:33:42 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/18 18:56:01 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//no hago new->next = 0; porque me hace segfault
#include "../push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*plast;

	if (*lst == 0)
		*lst = new;
	else
	{
		plast = ft_lstlast(*lst);
		plast->next = new;
	}
}
