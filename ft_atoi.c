int	ft_atoi(char *str)
{
	int	ret;
	int	sign;
	int	index;

	ret = 0;
	sign = 1;
	index = 0;
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == 32)
		i++;
	if (str[index] == 45 || str[index] == 43)
	{
		if (str[index] == 45)
			sign = -1;
		i++;
	}
	while (str[index] >= 48 && str[index] <= 57)
	{
		ret = ret * 10 + (str[index] - 48);
		i++;
	}
	return (ret * sign);
}
