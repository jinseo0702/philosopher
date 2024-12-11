#include "../include/philo.h"

void do_thread(void *philo)
{
    int cnt;
    t_philo *temp;
    t_arg *arg;

    temp = (t_philo *)philo;
    arg = temp->arg;
    cnt = 0;
    while (1)
    {
        take_fork(temp, arg);
        do_eat(temp, arg);
        do_sleep(temp, arg);
        do_think(temp, arg);
    }
    
}

void do_routin(t_philo *philo)
{
    t_arg *arg;
    int cnt;

    cnt = -1;
    arg = philo->arg;
    gettimeofday(&arg->start, NULL);
    while (++cnt < arg->num)
    {
        pthread_create(&philo[cnt].philo, NULL, (void *)do_thread, &philo[cnt]);
        usleep(10);
    }
    
}

void take_fork(t_philo *philo, t_arg *arg)
{
    if (arg->num == 1)
        msg_lock_fork(philo, philo->right, arg);
    else if ((philo->id % 2) == 1)
    {
        msg_lock_fork(philo, philo->left, arg);
        msg_lock_fork(philo, philo->right, arg);
    }
    else if ((philo->id % 2) == 0)
    {
        msg_lock_fork(philo, philo->right, arg);
        msg_lock_fork(philo, philo->left, arg);
    }
}

void do_eat(t_philo *philo, t_arg *arg)
{
    pthread_mutex_t eat;

    pthread_mutex_init(&eat, NULL);
    pthread_mutex_lock(&eat);
    philo->time = check_time(arg, philo);
    printf("%lld %d is eating\n", philo->time, philo->id);
    philo->eat++;
    usleep(arg->tte);
    pthread_mutex_unlock(philo->right);
    pthread_mutex_unlock(philo->left);
    pthread_mutex_unlock(&eat);
    pthread_mutex_destroy(&eat);
}

void do_sleep(t_philo *philo, t_arg *arg)
{
    pthread_mutex_t sleep;

    pthread_mutex_init(&sleep, NULL);
    pthread_mutex_lock(&sleep);
    philo->time = check_time(arg, philo);
    printf("%lld %d is sleeping\n", philo->time, philo->id);
    usleep(arg->tts);
    pthread_mutex_unlock(&sleep);
    pthread_mutex_destroy(&sleep);
}

void do_think(t_philo *philo, t_arg *arg)
{
    pthread_mutex_t think;

    pthread_mutex_init(&think, NULL);
    pthread_mutex_lock(&think);
    philo->time = check_time(arg, philo);
    printf("%lld %d is thinking\n", philo->time, philo->id);
    pthread_mutex_unlock(&think);
    pthread_mutex_destroy(&think);
}