/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabderra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:52:12 by zabderra          #+#    #+#             */
/*   Updated: 2022/06/03 20:13:53 by zabderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

void	reset_data(void)
{
	g_data.i = 0;
	g_data.x = 0;
	g_data.client_pid = 0;
}

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	sig -= SIGUSR1;
	if (g_data.client_pid != info->si_pid)
		reset_data();
	g_data.x = g_data.x << 1 | sig;
	g_data.i++;
	if (g_data.i == 8)
	{
		write(1, &g_data.x, 1);
		reset_data();
	}
	g_data.client_pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	sa;

	reset_data();
	ft_putstr("pid :    ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		sleep(1);
}
