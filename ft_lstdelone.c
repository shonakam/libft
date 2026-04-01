/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 02:41:38 by shonakam          #+#    #+#             */
/*   Updated: 2023/10/05 21:44:36 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (del)
		del(lst->content);
	free(lst);
}

// #include <stdio.h>
// #include <string.h>

// void	del_content(void *content, size_t size)
// {
// 	if (content)
// 	{
// 		printf("Deleting content: %s (size: %zu)\n", (char *)content, size);
// 		free(content);
// 	}
// }

// int  main(void)
// {
// 	t_list	*node;
// 	char	*str;
// 	size_t	size;

// 	str = strdup("Hello 42 Tokyo!");
// 	size = strlen(str) + 1;

// 	node = ft_lstnew(str, size);
// 	free(str);

// 	if (!node)
// 		return (printf("Node creation failed\n"), 1);
// 	printf("Before delone: node address = %p, content = %s\n", (void *)node, (char *)node->content);
// 	ft_lstdelone(&node, del_content);

// 	if (node == NULL)
// 		printf("Success: node pointer is now NULL\n");
// 	else
// 		printf("Failure: node pointer is NOT NULL\n");
// 	return (0);
// }
