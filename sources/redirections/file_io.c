/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtursuna <mtursuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:55:20 by mtursuna          #+#    #+#             */
/*   Updated: 2024/12/13 20:15:44 by mtursuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/* restore_io:
*	Restores the original standard input and standard output
*	to their original fds of 0 and 1. Used to clear the input/output
*	fds after execution, in preparation for the next set of user commands.
*	Returns 1 if the duplication was successful, 0 if not.
*/
bool	restore_io(t_io_fds *io)
{
	int	ret;

	ret = true;
	if (!io)
		return (ret);
	if (io->stdin_backup != -1)
	{
		if (dup2(io->stdin_backup, STDIN_FILENO) == -1)
			ret = false;
		close(io->stdin_backup);
		io->stdin_backup = -1;
	}
	if (io->stdout_backup != -1)
	{
		if (dup2(io->stdout_backup, STDOUT_FILENO) == -1)
			ret = false;
		close(io->stdout_backup);
		io->stdout_backup = -1;
	}
	return (ret);
}

/* check_infile_outfile:
*	Checks if the infile and outfile are set correctly.
*	Returns 1 on success, 0 on failure.
*/
bool	check_infile_outfile(t_io_fds *io)
{
	if (!io || (!io->infile && !io->outfile))
		return (true);
	if ((io->infile && io->fd_in == -1)
		|| (io->outfile && io->fd_out == -1))
		return (false);
	return (true);
}
