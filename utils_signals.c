/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 13:17:02 by barmarti          #+#    #+#             */
/*   Updated: 2025/06/29 18:54:57 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

/**
 * @brief A pre-prog that try to send a signal. If
 * it fail, exit the program and print an Error msg
 * 
 * @param pid of the program
 * @param sig the kill signal
 */
void	ft_kill(pid_t pid, int sig)
{
	if (kill(pid, sig) < 0)
	{
		ft_putstr_fd("Kill Error\n", 2);
		exit (EXIT_FAILURE);
	}
}

/**
 * @brief When we want to use the signal function we want to determinate
 * wich function that we wanna use. We could simply call the func
 * but it'll take many line to set up the all thing. So I've pre
 * init everything to make thing eazier.
 * If we wanna use the sigaction flag/function we'll send the bool
 * as true and then set the struc with the param that we need. If 
 * not use an simpler handler.
 * Then we set all the mask signal as 0 and set the SIGUSR1 and SIGUSR2
 * as the signal that we want to catch.
 * If the SIGUSR failed, print a msg and exit the prog
 * 
 * @param sig the signal that we wanna use
 * @param handler the function to do when recieving the message
 * @param use_siginfo if we use the sigaction funct or not
 */
void	ft_signal(int sig, void *handler, bool use_siginfo)
{
	struct sigaction	sa;

	sa.sa_flags = 0;
	if (use_siginfo)
	{
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = handler;
	}
	else
		sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(sig, &sa, NULL) < 0)
	{
		ft_putstr_fd("sigaction failed\n", 2);
		exit(EXIT_FAILURE);
	}
}
