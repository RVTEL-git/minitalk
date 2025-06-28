#include "minitalk.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	index;

	index = 0;
	while (str[index])
	{
		write(fd, &str[index], 1);
		index++;
	}
}
