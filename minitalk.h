#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/* 				TO DO
 * MAKE A BRIEF FOR ALL FUNCTION (USE YOUR HEAD)
 * MAKE FOLDER
 * MAKEFILE
 * 
 * 				BEFORE SET A FINISHED
 * CHECK CORRECTION SHEET
 * VERIFIER TOUS LES FICHIERS (INCLUDE, PROTO, \n ETC.)
 * FAIRE TESTE COMPLETS (MAX, MIN, NULL, WHITESPACES ETC.)
 * THEN WHEN TESTS SEEMS DONE USE A TESTER FROM GITHUB OR STUD
 * */
void	ft_putstr_fd(char *str, int fd);
int		ft_atoi(char *str);
void	ft_signal(int sig, void *handler, bool use_siginfo);
void	ft_kill(pid_t pid, int sig)

#endif
