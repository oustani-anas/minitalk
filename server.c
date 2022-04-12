/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:50:57 by aoustani          #+#    #+#             */
/*   Updated: 2022/03/26 23:14:10 by aoustani         ###   ########.fr       */
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
	return (0);
}
