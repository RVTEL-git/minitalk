/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 11:53:39 by barmarti          #+#    #+#             */
/*   Updated: 2025/06/29 15:43:18 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

int	main(int ac, char **av)
{
	pid_t	serv_pid;
	char	*msg;

	if (ac != 3)
	{
		ft_putstr_fd("Error: please send a PID and a message\n", 2);
		exit (EXIT_FAILURE);
	}
	serv_pid = ft_atoi(av[1]);
	msg = av[2];
	ft_signal(SIGUSR1, demand_handler, false);
	ft_signal(SIGUSR2, stop_handler, false);
	send_msg(serv_pid, msg);
	return (0);
}
