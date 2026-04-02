/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 02:41:38 by shonakam          #+#    #+#             */
/*   Updated: 2023/10/05 21:44:36 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (!*lst)
	{
		*lst = new;
		new->prev = NULL;
	}
	else
	{
		p = ft_lstlast(*lst);
		new->prev = p;
		p->next = new;
	}
	new->next = NULL;
}
