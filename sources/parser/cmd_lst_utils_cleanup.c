/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_utils_cleanup.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtursuna <mtursuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:44:41 by mtursuna          #+#    #+#             */
/*   Updated: 2024/12/13 19:44:48 by mtursuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lst_delone_cmd(t_command *lst, void (*del)(void *))
{
	if (lst->command)
		(*del)(lst->command);
	if (lst->args)
		free_str_tab(lst->args);
	if (lst->pipe_fd)
		(*del)(lst->pipe_fd);
	if (lst->io_fds)
		free_io(lst->io_fds);
	(*del)(lst);
}

void	lst_clear_cmd(t_command **lst, void (*del)(void *))
{
	t_command	*temp;

	temp = NULL;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		lst_delone_cmd(*lst, del);
		*lst = temp;
	}
}
