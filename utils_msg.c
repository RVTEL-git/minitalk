/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:25:03 by barmarti          #+#    #+#             */
/*   Updated: 2025/06/29 18:54:21 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

/**
 * @brief Global variable used to determinate the status of the
 * server. Like this it's eazier to know when we can send an other
 * char
 */
bool	g_server;

/**
 * @brief A handler to print the confirmation message when the serv
 * well recieved the string
 */
void	stop_handler(int sig)
{
	(void)sig;
	ft_putstr_fd("Message recieved\n", 1);
	exit(EXIT_SUCCESS);
}

/**
 * @brief A handler to tell the server that we can send an other char
 */
void	demand_handler(int sig)
{
	(void)sig;
	g_server = READY;
}

/**
 * @brief Send the char used in param to the server. Using two signal so using
 * bitwise operator to know wich of the signal that we nees to send
 * 
 * @param pid the pid of the server
 * @param c the char that we want to send
 */
void	send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_server = BUSY;
		if ((c >> (7 - bit)) & 1)
			ft_kill(pid, SIGUSR1);
		else
			ft_kill(pid, SIGUSR2);
		bit++;
		while (g_server == BUSY)
			usleep(50);
	}
}

/**
 * @brief Take a string and call send char, char by char to the server
 *
 * @param pid the pid of the server program
 * @param msg the msg that we want to send
 */
void	send_msg(int pid, char *msg)
{
	int		index;

	index = 0;
	while (msg[index])
	{
		send_char(pid, msg[index]);
		index++;
	}
	send_char(pid, '\0');
}
