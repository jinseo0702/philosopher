#include "../include/philo.h"

void msg_lock_fork(t_philo *philo, pthread_mutex_t *mutex)
{
    pthread_mutex_lock(mutex);
    printf("%d has taken a fork\n", philo->id);
}