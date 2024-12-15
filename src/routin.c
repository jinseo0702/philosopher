#include "../include/philo.h"

void *do_thread(void *philo)
{
    t_philo *temp;
    t_arg *arg;

    temp = (t_philo *)philo;
    arg = temp->arg;
    if ((temp->id % 2) == 0)
		ft_usleep(arg->tte /2);
    while (arg->cnt == 0)
    {
        pthread_mutex_lock(temp->right);
        msg(temp, arg, "has taken a fork");
        if(arg->num > 1)
        {
        pthread_mutex_lock(temp->left);
        msg(temp, arg, "has taken a fork");
        msg(temp, arg, "is eating");
        temp->eat++;
        if (check_mse(temp))
        {
            pthread_mutex_unlock(temp->left);
            pthread_mutex_unlock(temp->right);
            break;
        }
        ft_usleep2(arg->tte, arg);
        pthread_mutex_unlock(temp->left);
        pthread_mutex_unlock(temp->right);
        msg(temp, arg, "is sleeping");
        ft_usleep2(arg->tts, arg);
        msg(temp, arg, "is thinking");
        }
        else
        {
            ft_usleep2(arg->ttd * 2, arg);
            pthread_mutex_unlock(temp->right);
        }
    }
    pthread_mutex_lock(&arg->fin);
    arg->fc++;
    pthread_mutex_unlock(&arg->fin);
    pthread_mutex_lock(&temp->t_fin);
    temp->fis++;
    pthread_mutex_unlock(&temp->t_fin);
    return (NULL);
}

void do_routin(t_philo *philo)
{
    t_arg *arg;
    pthread_t moniter;
    void *val;
    int cnt;

    cnt = -1;
    arg = philo->arg;
    pthread_create(&moniter, NULL, (void *)ft_moniter, philo);
    while (++cnt < arg->num)
    {
        pthread_create(&philo[cnt].philo, NULL, do_thread, &philo[cnt]);
    }
    cnt = -1;
    while (++cnt < arg->num)
    {
        pthread_join(philo[cnt].philo, NULL);
    }
    pthread_join(moniter, &val);
    if ((int *)val == (int *)1)
        return ;

}

void *ft_moniter(void *philo)
{
    t_philo *temp;
    t_arg *arg;
    int cnt;
    int fc;

    temp = (t_philo *)philo;
    arg = temp->arg;
    while (1)
    {
        cnt = -1;
        while (++cnt < arg->num)
            check_died(&temp[cnt], arg);
        pthread_mutex_lock(&arg->fin);
        fc = arg->fc;
        pthread_mutex_unlock(&arg->fin);
        if (arg->cnt == 1)
        {
            if (fc == arg->num)
                return ((void *)0x01);
        }
        if (fc == arg->num)
            return ((void *)0x01);
    }
    return (NULL);
}


void check_died(t_philo *philo, t_arg *arg)
{
    long long time;
    int fis;
    long long last_eat;

    time = check_time();
    pthread_mutex_lock(&philo->t_fin);
    fis = philo->fis;
    pthread_mutex_unlock(&philo->t_fin);
    pthread_mutex_lock(&arg->print);
    last_eat = philo->btime;
    if (arg->cnt > 0 || fis > 0)
    {
        pthread_mutex_unlock(&arg->print);
        return ;
    }
    if (time - arg->start - last_eat > arg->ttd)
    {
        printf("%lld %d died\n", time - arg->start, philo->id);
        arg->cnt++;
        arg->sleep++;
        pthread_mutex_unlock(&arg->print);
        return ;
    }
    pthread_mutex_unlock(&arg->print);
    return ;
}

int check_mse(t_philo *philo)
{
    if (philo->t_argc == 6)
    {
        if (philo->t_mse == philo->eat)
            return (1);
    }
    return (0);
}