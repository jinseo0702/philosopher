# ifndef PHILO_H
# define PHILO_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_arg
{
    long long num;
    long long ttd;
    long long tte;
    long long tts;
    long long mse;
    int argc;
    struct timeval start;
    pthread_mutex_t *fork;
} t_arg;

typedef struct s_philo
{
    t_arg *arg;
    pthread_t philo;
    int id;
    long long eat;
    int die;
    long long time;
    struct timeval end;
    pthread_mutex_t *left;
    pthread_mutex_t *right;
} t_philo;

void msg_lock_fork(t_philo *philo, pthread_mutex_t *mutex, t_arg *arg);
long long check_time(t_arg *arg, t_philo *philo);
int mutex_init(pthread_mutex_t *mutex);
int destroy_mutex(pthread_mutex_t *mutex);
int init_arg(t_arg *arg,  int argc, char **argv);
t_philo *init_thread(t_arg *arg);
int init_fork(t_arg *arg);
int destroy_fork(t_arg *arg);
int check_argv(char **argv);
long long	ft_atoi(const char *nptr);
int	ft_isdigit(int c);
void do_thread(void *philo);
void do_routin(t_philo *philo);
void take_fork(t_philo *philo, t_arg *arg);
void do_eat(t_philo *philo, t_arg *arg);
void do_sleep(t_philo *philo, t_arg *arg);
void do_think(t_philo *philo, t_arg *arg);
void ft_start(int argc, char **argv);

# endif