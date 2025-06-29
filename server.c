/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 12:05:23 by barmarti          #+#    #+#             */
/*   Updated: 2025/06/29 18:39:09 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"
#include <stdio.h>

/**
 * @brief Get the expected len object depending of it's an
 * emoji or all other unicode char (U+00E9, U+0100 etc.)
 * 
 * @param c the char to check in order to get its byte size
 * @return int the byte size of the char that we're checking for
 */
int	get_expected_len(char c)
{
	int				expected_len;
	unsigned char	uc;

	expected_len = 0;
	uc = (unsigned char)c;
	if ((uc & 0x80) == 0x00)
		expected_len = 1;
	else if ((uc & 0xE0) == 0xC0)
		expected_len = 2;
	else if ((uc & 0xF0) == 0xE0)
		expected_len = 3;
	else if ((uc & 0xF8) == 0xF0)
		expected_len = 4;
	else
		expected_len = 1;
	return (expected_len);
}

/**
 * @brief once we have recieved a char, we check for it's byte size anf then 
 * determinate how de we need to behave with it. Then print it and send a sig
 * to the client to make it know that we are ready for the next.
 * 
 * @param pid the process ID of the client to send him the top signal
 * @param c the char that we are dealing with
 */
void	print_char(pid_t pid, char c)
{
	static char	buffer[5];
	static int	index = 0;
	static int	expected_len = 0;

	buffer[index++] = c;
	if (index == 1)
		expected_len = get_expected_len(c);
	if (index == expected_len || c == '\0')
	{
		buffer[index] = '\0';
		if (c != '\0')
			ft_putstr_fd(buffer, 1);
		else
		{
			ft_putchar_fd('\n', 1);
			ft_kill(pid, SIGUSR2);
		}
		index = 0;
	}
}

/**
 * @brief A handler is used when we want to adopt a certain behavior when
 * we recieve a signal.
 * 
 * @param signum The signal number (in this case SIGUSR1 or SIGUSR2)
 * @param info We are usign siaction struct to determinate what we want to do
 * when we're calling the handler
 * @param more_info It could be use for other specific action (using more
 * info of the sigaction struct)
 */
void	ft_handler(int signum, siginfo_t *info, void *more_info)
{
	static unsigned char		c = 0;
	static int					bit = 0;
	static pid_t				client_pid = 0;

	(void)more_info;
	if (info->si_pid != client_pid)
	{
		c = 0;
		bit = 0;
		client_pid = info->si_pid;
	}
	if (signum == SIGUSR1)
		c |= (1 << (7 - bit));
	else if (signum == SIGUSR2)
		c &= ~(1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		bit = 0;
		print_char(client_pid, c);
	}
	ft_kill(client_pid, SIGUSR1);
}

int	main(void)
{
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	ft_signal(SIGUSR1, ft_handler, true);
	ft_signal(SIGUSR2, ft_handler, true);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
