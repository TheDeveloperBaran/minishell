/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsahin <ilsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:07:29 by ilsahin           #+#    #+#             */
/*   Updated: 2023/10/28 14:07:30 by ilsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_process(void)
{
	t_process	*tmp;
	t_process	*process;

	process = g_ms.process;
	if (!process)
		return ;
	while (process)
	{
		free_array(process->execute);
		free_array(process->redirects);
		tmp = process;
		process = process->next;
		free(tmp);
	}
}
