/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 11:56:43 by barmarti          #+#    #+#             */
/*   Updated: 2025/06/29 18:28:36 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h> 
# include <sys/types.h> 

/*
 				BEFORE SET AS FINISHED
 * VERIFIER TOUS LES FICHIERS (INCLUDE, PROTO, \n ETC.)
 * FAIRE TESTE COMPLETS (MAX, MIN, NULL, WHITESPACES ETC.)
 * THEN WHEN TESTS SEEMS DONE USE A TESTER FROM GITHUB OR STUD
 * */

enum
{
	READY ,
	BUSY ,
};

/* utils_msg.c */
void	send_msg(pid_t pid, char *msg);
void	send_char(pid_t pid, char c);
void	demand_handler(int sig);
void	stop_handler(int sig);

/* utils_signals.c */
void	ft_signal(int sig, void *handler, bool use_siginfo);
void	ft_kill(pid_t pid, int sig);

#endif
