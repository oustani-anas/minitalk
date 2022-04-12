/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:51:13 by aoustani          #+#    #+#             */
/*   Updated: 2022/03/22 10:43:26 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<signal.h>

int		ft_putchar(char c);
int		ft_atoi(const char *str);
int		ft_putstr(char *s);
void	ft_putnbr(int nb);

#endif