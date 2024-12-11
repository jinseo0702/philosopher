# ifndef PHILO_H
# define PHILO_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_arg
{
    long long num;
    long long ttd;
    long long tte;
    long long tts;
    long long mse;
    int argc;
    pthread_mutex_t *fork;
    pthread_mutex_t eat;
} t_arg;

typedef struct s_philo
{
    t_arg *arg;
    pthread_t philo;
    int id;
    long long eat;
    int die;
    pthread_mutex_t *left;
    pthread_mutex_t *right;
} t_philo;

void msg_lock_fork(t_philo *philo, pthread_mutex_t *mutex);
int mutex_init(pthread_mutex_t *mutex);
int init_arg(t_arg *arg,  int argc, char **argv);
int init_thread(t_philo *philo, t_arg *arg);
int init_fork(t_arg *arg);
int destroy_fork(t_arg *arg);
int check_argv(char **argv);
long long	ft_atoi(const char *nptr);
int	ft_isdigit(int c);
void do_thread(void *philo);
void do_routin(t_philo *philo);
void take_fork(t_philo *philo);
void do_eat(t_philo *philo, t_arg *arg);

# endif