/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:35:11 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/18 20:42:10 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_lstclear(t_list **lst)
{
	t_list	*cpy;

	while (*lst != 0)
	{
		cpy = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = cpy;
	}
}
