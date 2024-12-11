#include "../include/philo.h"

void msg_lock_fork(t_philo *philo, pthread_mutex_t *mutex, t_arg *arg)
{
    pthread_mutex_t print;

    pthread_mutex_init(&print, NULL);
    pthread_mutex_lock(mutex);
    pthread_mutex_lock(&print);
    philo->time = check_time();
    printf("%lld %d has taken a fork\n", philo->time - arg->start, philo->id);
    pthread_mutex_unlock(&print);
    pthread_mutex_destroy(&print);
}

long long check_time(void)//마이크로 단위로 변환
{
	struct timeval time;

    gettimeofday(&time, NULL);
    return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}