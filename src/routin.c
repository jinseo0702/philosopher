#include "../include/philo.h"

void do_thread(void *philo)
{
    t_philo *temp;

    temp = (t_philo *)philo;
    while (1)
    {
        take_fork(temp);
    }
    
}

void do_routin(t_philo *philo)
{
    t_arg *arg;
    int cnt;

    cnt = -1;
    arg = philo->arg;
    while (++cnt < arg->num)
    {
        pthread_create(&philo[cnt].philo, NULL, (void *)do_thread, &philo[cnt]);
    }
    
}

void take_fork(t_philo *philo)
{
    if (philo->arg->num == 1)
        msg_lock_fork(philo, philo->right);
    else if ((philo->id % 2) == 0)
    {
        msg_lock_fork(philo, philo->left);
        msg_lock_fork(philo, philo->right);
    }
    else if ((philo->id % 2) == 1)
    {
        msg_lock_fork(philo, philo->right);
        msg_lock_fork(philo, philo->left);
    }
}

void do_eat(t_philo *philo, t_arg *arg)
{
    pthread_mutex_lock(&arg->eat);
    printf("%d is eating\n", philo->id);
    philo->eat++;
    pthread_mutex_unlock(&arg->eat);
    pthread_mutex_unlock(philo->left);
    pthread_mutex_unlock(philo->right);
}