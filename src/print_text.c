#include "../include/philo.h"

void msg(t_philo *philo, t_arg *arg, const char *str)
{
    long long time;

    pthread_mutex_lock(&arg->print);
    if (arg->cnt > 0)
    {
        pthread_mutex_unlock(&arg->print);
        return ;
    }
    time = check_time();
    printf("%lld %d %s\n", time - arg->start, philo->id, str);
    if (!ft_strncmp(str, "is eating", 9))
    {
        philo->btime = time - arg->start;
    }
    pthread_mutex_unlock(&arg->print);
}

long long check_time(void)//마이크로 단위로 변환
{
	struct timeval time;

    gettimeofday(&time, NULL);
    return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void ft_usleep(long long how)
{
    long long now; 

    now = check_time();
    while (check_time() - now < how)
    {
        usleep(how /10);
    }
}

void ft_even(t_arg *arg)
{
    ft_usleep(arg->tte /2);
}