/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:25:36 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/06 15:01:18 by vde-prad         ###   ########.fr       */
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
unsigned int	ft_check_args(int argc, char **argv, t_data *data);
int				ft_check_str(t_data *data);
int				ft_check_int(t_data *data);
int				ft_check_duplicate(t_data *data);
void			ft_error();

long long		ft_atoll(const char *str);
void			ft_fillstack(t_data	*data);
void			ft_cleanstack(t_stack **x);
#endif
