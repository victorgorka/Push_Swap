/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:29:54 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/15 12:11:14 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

unsigned int	ft_abs(int x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}