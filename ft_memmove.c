/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:22:12 by shonakam          #+#    #+#             */
/*   Updated: 2023/10/10 11:03:21 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d < s)
	{
		while (len)
			*d++ = (len--, *s++);
	}
	else
	{
		d += len;
		s += len;
		while (len)
			*--d = (len--, *--s);
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char str[] = "abcde'fghijklmno'pqrstu";

// 	printf("移動前：%s\n", str);

// 	ft_memmove(str + 5, str, 10);

// 	printf("移動後：%s\n", str);
// }
