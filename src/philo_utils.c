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
    while (nptr[++idx])
	{
        if (!ft_isdigit(nptr[idx]))
            flag = 1;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = (*nptr - 48) + (nb * 10);
		nptr++;
	}
	if (flag == 1 || (nb < 0 || nb > 2147483647))
    {
        printf("ERROR : The value you entered is incorrect\n");
        return (-1);
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s11;
	unsigned char	*s22;
	size_t			cnt;

	if (!s1 || !s2)
		return (0);
	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	cnt = 0;
	while ((*s11 || *s22) && cnt < n)
	{
		if (*s11 != *s22)
			return (*s11 - *s22);
		s22++;
		s11++;
		cnt++;
	}
	return (0);
}