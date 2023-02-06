/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:25:36 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/06 16:45:17 by vde-prad         ###   ########.fr       */
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
}	t_data;
//*************************** FUNCTIONS **************************************
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
#endif
