/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:20:42 by bcarpent          #+#    #+#             */
/*   Updated: 2024/05/06 13:21:25 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

char	*g_str;

void	exit_handler(void)
{
	if (*g_str)
	{
		ft_printf("Send failed\n");
		exit(0);
	}
	ft_printf("Message send\n");
	exit(0);
}

void	fill_data(t_data *data, int pid)
{
	data->str_len = ft_strlen(g_str);
	data->s_pid = pid;
	data->i = 31;
}

void	ft_send_len(t_data *data)
{
	if (data->i == 0)
	{
		data->i = 8;
		data->verif = 1;
		ft_printf("PID send\n...\n");
	}
	if (data->str_len >> data->i & 1)
		kill(data->s_pid, SIGUSR2);
	else
		kill(data->s_pid, SIGUSR1);
	data->i--;
	return ;
}

void	sigusr_handler(int signum, siginfo_t *info, void *context)
{
	static t_data	data;

	if (signum == SIGUSR2)
		exit_handler();
	if (!data.str_len)
		fill_data(&data, info->si_pid);
	if (!data.verif)
		return (ft_send_len(&data));
	if (*g_str >> data.i & 1)
		kill(data.s_pid, SIGUSR2);
	else
		kill(data.s_pid, SIGUSR1);
	data.i--;
	if (data.i == -1 && *g_str)
	{
		data.i = 7;
		g_str++;
	}
	(void)signum;
	(void)context;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3 || !argv[1] || !argv[2] || ft_atoi(argv[1]) <= 0)
		return (1);
	sa.sa_sigaction = sigusr_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	g_str = argv[2];
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (ft_printf("Faillure\n"), 1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (ft_printf("Faillure\n"), 1);
	ft_printf("%d\n", getpid());
	kill(ft_atoi(argv[1]), SIGUSR1);
	while (1)
		pause();
}
