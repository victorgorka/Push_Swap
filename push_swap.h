/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:25:36 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/09 16:24:19 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//*********************** STANDARD LIBRARIES *********************************
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "libft/libft.h"
//************************** DEFINITIONS *************************************
typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	t_stack			*a;
	t_stack			*b;
	char			**args;
	int				*iargs;
	unsigned int	iargs_len;
	unsigned int	a_size;
	unsigned int	b_size;
}	t_data;
//*************************** FUNCTIONS **************************************
//push_swap.c
int				ft_ifsorted(t_data data);
//first_check.c
unsigned int	ft_check_args(int argc, char **argv, t_data *data);
int				ft_check_str(t_data *data);
int				ft_check_int(t_data *data);
int				ft_check_duplicate(t_data *data);
void			ft_error();
//atoll.c
long long		ft_atoll(const char *str);
//init_stack.c
void			ft_fillstack(t_data	*data);
void			ft_cleanstack(t_stack **x);
void			ft_index_init(t_data *data);
void			ft_clean(t_data *data, int argc);
//push.c
void			ft_pa(t_data *data);
void			ft_pb(t_data *data);
//swap.c
void			ft_sa(t_data *data);
void			ft_sb(t_data *data);
void			ft_ss(t_data *data);
//rotate.c
void			ft_ra(t_data *data);
void			ft_rb(t_data *data);
void			ft_rr(t_data *data);
//revrotate.c
void			ft_rra(t_data *data);
void			ft_rrb(t_data *data);
void			ft_rrr(t_data *data);
//small_sort.c
void			ft_small_sort(t_data *data);
//sorting.c
void			ft_main_algo(t_data *data);
//target_pos.c
void			ft_target(t_data *data);
void			ft_assign_pos(t_stack **x);
#endif
