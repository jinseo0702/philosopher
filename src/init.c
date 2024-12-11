#include "../include/philo.h"

int init_arg(t_arg *arg,  int argc, char **argv)
{
    arg->argc = argc;
    arg->num = ft_atoi(argv[1]);
    arg->ttd = ft_atoi(argv[2]);
    arg->tte = ft_atoi(argv[3]);
    arg->tts = ft_atoi(argv[4]);
    if (init_fork(arg) == -1)
        return (-1);
    if (mutex_init(&arg->eat) == -1)
        return (-1);
    if (argc == 6)
        arg->mse = ft_atoi(argv[5]);
    else
        arg->mse = 0;
    return (1);
}

int mutex_init(pthread_mutex_t *mutex)
{
    if(pthread_mutex_init(mutex, NULL) != 0)
        return (-1);//error처리하기
    return (1);
}

int init_thread(t_philo *philo, t_arg *arg)
{
    int cnt;
    int siz;

    cnt = 0;
    philo = malloc(sizeof(t_philo) * (arg->num + 1));
    if (!philo)
        return (-1);
    siz = sizeof(philo) * (arg->num + 1);
    memset(philo, 0, siz);
    while (cnt < arg->num)
    {
        philo[cnt].arg = arg;
        philo[cnt].id = (cnt + 1);
        philo[cnt].eat = 0;
        philo[cnt].die = 0;
        philo[cnt].right = &arg->fork[cnt];
        if (cnt == arg->num - 1)
            philo[cnt].left = &arg->fork[0];
        else
            philo[cnt].left = &arg->fork[cnt + 1];
        cnt++;
    }
    return (1);
}

int init_fork(t_arg *arg)
{
    int cnt;
    int siz;

    cnt = 0;
    arg->fork = malloc(sizeof(pthread_mutex_t) * (arg->num + 1));
    if (!arg->fork)
        return (-1);
    siz = sizeof(pthread_mutex_t) * (arg->num + 1);
    memset(arg->fork, 0, siz);
    while (cnt < arg->num)
    {
        if(pthread_mutex_init(&arg->fork[cnt], NULL) != 0)
            return (-1);//error처리하기
        cnt++;
    }
    return (1);
}

int destroy_fork(t_arg *arg)
{
    int cnt;

    cnt = -1;
    while (++cnt <= arg->argc)
        if (pthread_mutex_destroy(&arg->fork[cnt]) != 0)
            return (-1);//free어떻게 해줄건지 생각해보기.
    free(arg->fork);
    return (1);
}