/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:36:27 by shonakam          #+#    #+#             */
/*   Updated: 2023/10/10 17:07:03 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	solve_long(const char *str, int sign)
{
	long long	res;
	long long	mem;

	res = 0;
	while (*str != '\0' && ('0' <= *str && *str <= '9'))
	{
		res = (res * 10) + (*str - '0');
		if (0 > res)
		{
			if (sign == 1)
				return ((int)(LONG_MAX));
			else
				return ((int)(LONG_MIN));
		}
		str++;
	}
	return ((int)(sign * res));
}

int	ft_atoi(const char *str)
{
	int		result;
	int		flag;

	result = 0;
	flag = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag *= -1;
		str++;
	}
	return (solve_long(str, flag));
}

// int	main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		int	res1 = ft_atoi(av[1]);
// 		int	res2 = atoi(av[1]);
// 		printf("ft :'%d'\n", res1);
// 		printf("uni:'%d'\n", res2);
// 	}
// }
