#include "minitalk.h"

/** @brief
 * 
 * @msg 
 * @pid
 */
void	send_msg(int pid, char *msg)
{
	int	index;
	int	bit;

	index = 0;
	while (msg[index])
	{
		bit = 0;
		while (bit < 8)
		{
			if (c & (0b1000000 >> bit))
				ft_kill(pid, SIGUSR1);
			else 
				ft_kill(pid, SIGUSR2);
			bit++;
		}
		index++;
}

int	main(int ac, char **av)
{
	pid_t	serv_pid;
	char	*msg;
	int		index;

	if (ac != 3)
	{
		ft_putstr_fd("Error: please send a PID and a message\n", 2);
		exit (EXIT_FAILURE)
	}
	serv_pid = ft_atoi(av[1]);
	msg = av[2];
	index = 0;
	send_msg(pid, msg);
	return (0);
}
