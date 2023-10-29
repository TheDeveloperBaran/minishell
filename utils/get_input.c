/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsahin <ilsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:13:20 by ilsahin           #+#    #+#             */
/*   Updated: 2023/10/28 16:16:45 by ilsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_input(void)
{
	char	*input;

	write(1, "\033[36m", 5);
	input = readline("minishell_> ");
	write(1, "\033[0m", 4);
	return (input);
}