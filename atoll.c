/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoll.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:42:39 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/01 14:40:14 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	ft_check_sign(char *str)
{
	if (*str == '-')
		return (-1);
	return (1);
}

long long	ft_atoll(const char *str)
{
	long long	res;
	int			sign;

	sign = 1;
	res = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r' )
		str++;
	if (*str == '-' || *str == '+')
		sign = ft_check_sign ((char *)str++);
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	res *= sign;
	return (res);
}
/*
#include<stdlib.h>
int main()
{
	char str[40] = "99999999999999999999999999";
	printf("%d\n", ft_atoi(str));
	printf("%d\n", atoi(str));
}
*/
