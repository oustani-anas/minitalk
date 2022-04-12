/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:46:30 by aoustani          #+#    #+#             */
/*   Updated: 2022/03/26 22:59:33 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_character(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		kill(pid, (c >> i & 1) + SIGUSR1);
		usleep(300);
		i--;
	}
}

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1, "\033[0;32m", 7);
		write(1, "characters received\n", 21);
	}	
	exit(0);
}

int	main(int ac, char **av)
{
	char	*string;
	int		i;
	int		pid;

	if (ac != 3)
	{
		write(1, "\033[0;31m", 8);
		write(1, "WRONG ARGUMENTS", 16);
		return (1);
	}
	string = av[2];
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		write(1, "\033[0;31m", 8);
		write(1, "INVALID PID", 11);
	}
	i = 0;
	signal(SIGUSR1, sig_handler);
	while (string[i])
	{
		send_character(string[i], pid);
		i++;
	}
	send_character(0, pid);
}
