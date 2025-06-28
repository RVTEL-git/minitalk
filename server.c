#include "minitalk.h"

void	handler(int signum, siginfo_t *info, void *more_info)
{
	(void)more_info;
	static char		c;
	static int		i;
	static pid_t	client_pid;

	client_pid = info->si_pid;
	if (signum == SIGUSR1)
		c |= (0b1000000 >> bit);
	else if (signum == SIGUSR2)
		c &= ~(0b1000000 >> bit);
	bit++;
	if (bit == 8)
	{
		bit = 0;
		if (c == '\0')
		{
			write(1, "\n", 1);
			ft_kill(client_pid, SIGUSR2);
			return ;
		}
		else
			write(1, &c, 1);
	}
	ft_kill(client_pid, SIGUSR1);
}

int	main(void)
{
	printf("%d\n", getpid());//Remplacer par ft_
	ft_signal(SIGUSR1, handler, true);
	ft_signal(SIGUSR2, handler, true);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
