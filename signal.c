#include "minitalk.h"

void	ft_signal(int sig, void *handler, bool use_siginfo)
{
	struct sigaction	sa = {0};

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
