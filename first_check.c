/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:20:14 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/02 19:10:09 by vde-prad         ###   ########.fr       */
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
	if (!ft_check_str(data) || !ft_check_int(data))
		ft_error();
	return (1);
}

int	ft_check_int(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (data->args[i])
		i++;
	data->iargs_len = i - 1;
	data->iargs = malloc((i + 1) * sizeof(int));
	i = -1;
	while (data->args[++i])
	{
		if (ft_atoll(data->args[i]) > INT_MAX 
			|| ft_atoll(data->args[i]) < INT_MIN)
			return (0);
		data->iargs[i] = ft_atoi(data->args[i]);
	}
	if (!ft_check_duplicate(data))
		return (0);
	return (1);
}

int	ft_check_duplicate(t_data *data)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i <= data->iargs_len)
	{
		j = 0;
		while (j <= data->iargs_len)
		{
			if (i != j && data->iargs[i] == data->iargs[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
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
			if (!ft_isdigit(data->args[i][j])) 
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

// void check_leaks(void)
// {
//     system("leaks push_swap");
// }
// 
// int main(int argc, char	**argv)
// {
//     t_data data;
//     int i= 0;
// 
//     ft_check_args(argc, argv, &data);
//     puts(data.args[0]);
//     // printf("%lld\n", data.iargs[0]);
//     if (argc == 2)
//     {
//          while (data.args[i])
//          {
//              if (data.args[i])
//                 free(data.args[i++]);
//         }
//         free(data.args);	
//     }
//     free(data.iargs);
//     atexit(check_leaks);
// }
//CASOS DE ERROR
//-0 +0 1 2 3  DUPLICADO
//--3 DOS SIGNOS SEGUIDOS
//++3 DOS SIGNOS SEGUIDOS
//2147483650 SUPERIOR A INT
