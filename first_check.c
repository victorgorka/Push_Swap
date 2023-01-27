/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:20:14 by vde-prad          #+#    #+#             */
/*   Updated: 2023/01/27 16:34:21 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

unsigned int ft_check_args(int argc, char **argv)
{
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = malloc(sizeof(char **));
		*args = malloc((argc - 1) * sizeof(char	*));
		while (i++ < (argc - 1))
			args[i - 1] = ft_strdup(argv[i]);
		args[argc - 1] = NULL;
	}
	return (0);
}

void ft_error()
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

int main(int argc, char	**argv)
{
	ft_check_args(argc, argv);
}
