/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikorkut <ikorkut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:09:56 by ilsahin           #+#    #+#             */
/*   Updated: 2023/10/29 17:05:48 by ikorkut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	g_ms;

void	init_app(char **env)
{
	g_ms.paths = NULL;
	g_ms.parent_pid = getpid();
	set_env(env);
	set_export(env);
	set_paths();
}

void	init_shell(char *input)
{
	g_ms.token = NULL;
	g_ms.process = NULL;
	g_ms.process_count = 0;
	tokenize(input);
	if (!lexer())
		return ;
	start_cmd();
	free_process();
}

void	ctrl_c(int sig)
{
	(void)sig;
	g_ms.check_flag = 1;
	g_ms.ignore = TRUE;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	write(1, "\033[A", 3);
}

void	ctrl_d(char *input)
{
	if (!input)
	{
		printf("exit\n");
		exit(errno);
	}
}

int	main(int ac, char **av, char **env)
{
	char	*input;

	init_app(env);
	while (ac == 1 && av)
	{
		check_flag();
		g_ms.ignore = FALSE;
		signal(SIGINT, &ctrl_c);
		signal(SIGQUIT, SIG_IGN);
		check_flag();
		input = get_input();
		ctrl_d(input);
		if (g_ms.ignore)
		{
			free(input);
			input = malloc(1);
		}
		if (*input)
		{
			init_shell(input);
			add_history(input);
		}
		free(input);
	}
	exit(errno);
}
