/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:20:14 by vde-prad          #+#    #+#             */
/*   Updated: 2023/01/30 19:29:31 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

unsigned int ft_check_args(int argc, char **argv, t_data *data)
{
	int	i;

	i = -1;
	data->argc = argc;
	if (argc == 2)
		data->args = ft_split(argv[1], ' ');
	else
		data->args = &argv[1];
	if (ft_check_str(data) && ft_check_int(data))
		ft_error();
	return (1);
}

int	ft_check_int(data)
{
	data->iargs = malloc(data->argc - 1 * sizeof(int));

}

int	ft_check_str(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->args[i])
	{
		j = 0;
		if (data->args[i][j] == '-' || data->args[i][j] == '+')
			j++;
		while (data->args[i][j])
		{
			if (data->args[i][j] < '0' || data->args[i][j] > '9') 
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}


void ft_error()
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

void check_leaks(void)
{
	system("leaks push_swap");
}

int main(int argc, char	**argv)
{
	t_data data;

	atexit(check_leaks);
	ft_check_args(argc, argv, &data);
}
//CASOS DE ERROR
//-0 +0 1 2 3  DUPLICADO
//--3 DOS SIGNOS SEGUIDOS
//++3 DOS SIGNOS SEGUIDOS
//2147483650 SUPERIOR A INT
