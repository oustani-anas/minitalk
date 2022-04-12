/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:46:54 by aoustani          #+#    #+#             */
/*   Updated: 2022/03/19 11:46:58 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal, siginfo_t *info, void *nothing)
{
	static int	client_id;
	static int	i;
	static int	c;

	(void) nothing;
	if (client_id != info->si_pid)
	{
		i = 0;
		c = 0;
	}
	c = c << 1 | (signal - 30);
	i++;
	if (i == 8)
	{
		if (c == 0)
		{
			kill(info->si_pid, SIGUSR1);
		}
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
	client_id = info->si_pid;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr("PID :\t");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
	{
		pause();
	}
}
