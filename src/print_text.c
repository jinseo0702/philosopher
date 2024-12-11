#include "../include/philo.h"

void msg_lock_fork(t_philo *philo, pthread_mutex_t *mutex, t_arg *arg)
{
    pthread_mutex_t print;

    pthread_mutex_init(&print, NULL);
    pthread_mutex_lock(mutex);
    pthread_mutex_lock(&print);
    philo->time = check_time(arg, philo);
    printf("%lld %d has taken a fork\n", philo->time, philo->id);
    pthread_mutex_unlock(&print);
    pthread_mutex_destroy(&print);
}

long long check_time(t_arg *arg, t_philo *philo)
{
    long long seconds;
    long long microseconds;
    long long temp;

    gettimeofday(&philo->end, NULL);
    seconds = philo->end.tv_sec - arg->start.tv_sec;
    microseconds = philo->end.tv_usec - arg->start.tv_usec;
    temp = (seconds / 1000000.0) + microseconds;
    return (temp);
}