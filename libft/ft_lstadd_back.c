/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:32:55 by rakhsas           #+#    #+#             */
/*   Updated: 2022/10/30 20:20:16 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*nt;

	if (*lst == NULL)
		*lst = new;
	else
	{
		nt = *lst;
		while (nt->next != NULL)
			nt = nt->next;
		nt->next = new;
	}
}
