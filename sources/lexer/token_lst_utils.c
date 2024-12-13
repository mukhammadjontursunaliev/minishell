/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtursuna <mtursuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:48:10 by mtursuna          #+#    #+#             */
/*   Updated: 2024/12/13 19:50:27 by mtursuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lstdelone_token(t_token *lst, void (*del)(void *))
{
	if (del && lst && lst->str)
	{	
		(*del)(lst->str);
		lst->str = NULL;
	}
	if (del && lst && lst->str_backup)
	{	
		(*del)(lst->str_backup);
		lst->str_backup = NULL;
	}
	if (lst->prev)
		lst->prev->next = lst->next;
	if (lst->next)
		lst->next->prev = lst->prev;
	free_ptr(lst);
}

void	lstclear_token(t_token **lst, void (*del)(void *))
{
	t_token	*tmp;

	tmp = NULL;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		lstdelone_token(*lst, del);
		*lst = tmp;
	}
}