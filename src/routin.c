#include "../include/philo.h"

void *do_thread(void *philo)
{
    t_philo *temp;
    t_arg *arg;

    temp = (t_philo *)philo;
    arg = temp->arg;
    if ((temp->id % 2) == 0)
		ft_usleep(arg->tte /2);
    while (!temp->die)
    {
        pthread_mutex_lock(temp->left);
        msg(temp, arg, "has taken a fork");
        pthread_mutex_lock(temp->right);
        msg(temp, arg, "has taken a fork");
        msg(temp, arg, "is eating");
        // pthread_mutex_lock(&arg->eat);
        temp->eat++;
        // pthread_mutex_unlock(&arg->eat);
        ft_usleep(arg->tte);
        pthread_mutex_unlock(temp->right);
        pthread_mutex_unlock(temp->left);
        msg(temp, arg, "is sleeping");
        ft_usleep(arg->tts);
        msg(temp, arg, "is thinking");
    }
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
    pthread_join(moniter, &val);
    if ((int *)val == (int *)1)
        return ;
    cnt = -1;
    while (++cnt < arg->num)
    {
        pthread_join(philo[cnt].philo, NULL);
    }

}

void *ft_moniter(void *philo)
{
    t_philo *temp;
    t_arg *arg;
    int cnt;
    int pn;

    temp = (t_philo *)philo;
    arg = temp->arg;
    while (1)
    {
        if (arg->cnt == 1)
            return ((void *)0x01);
        if (arg->argc == 6)
        {
            cnt = -1;
            while (++cnt < arg->num)
                if (temp[cnt].eat == arg->mse)
                    temp[cnt].die = 1;
            cnt = -1;
            pn = arg->num;
            while (++cnt < arg->num)
            {
                if (temp[cnt].die == 1)
                    pn--;
            }
            if (pn == 0)
                return ((void *)0x01);
        }
    }
    return (NULL);
}
