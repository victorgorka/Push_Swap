/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:20:14 by vde-prad          #+#    #+#             */
/*   Updated: 2023/01/27 14:01:19 by vde-prad         ###   ########.fr       */
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
		while (i < (argc - 1))
		{
			args[i] = ft_strdup(argv[i + 1]);
			i++;
		}
		args[argc - 1] = NULL;
	}
	i = 0;
	while (i < 4)
		ft_printf("%s\n", args[i++]);
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
