/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:20:14 by vde-prad          #+#    #+#             */
/*   Updated: 2023/01/22 16:51:08 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int ft_check_args(int argc, char **argv)
{
	char	**args;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = malloc(argc * sizeof(char **));
		while (argc > 0)
			argc = *argv;
	}
}

void ft_error()
{

}
