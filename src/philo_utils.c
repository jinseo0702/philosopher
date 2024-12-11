#include "../include/philo.h"

int check_argv(char **argv)
{
    int idx;
    int flag;
  
    idx = 0;
    flag = 0;
    while (argv[++idx])
    {
        flag = ft_atoi(argv[idx]);
        if (flag == -1)
            return (-1);
    }
    return (1);
}

long long	ft_atoi(const char *nptr)
{
	long long	nb;
    int idx;
    int flag;

	nb = 0;
    idx = -1;
    flag = 0;
    if (nptr[0] == '0')
            flag = 1;
    while (nptr[++idx])
        if (!ft_isdigit(nptr[idx]))
            flag = 1;
    if (flag == 1)
    {
        printf("ERROR : The value you entered is incorrect\n");
        return (-1);
    }
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = (*nptr - 48) + (nb * 10);
		nptr++;
	}
	return (nb);
}

int	ft_isdigit(int c)
{
	unsigned char	as;

	as = (unsigned char)c;
	if (as >= '0' && as <= '9')
		return (2048);
	return (0);
}
