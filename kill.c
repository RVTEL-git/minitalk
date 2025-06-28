#include "minitalk.h"

void	ft_kill(pid_t pid, int sig)
{
	if (kill(pid, sig) < 0)
	{
		ft_putstr_fd("Kill Error\n", 2);
		exit (EXIT_FAILURE);
	}
}
