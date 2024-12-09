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
} t_arg;

typedef struct s_philo
{
    t_arg *arg;
    pthread_t philo;
    long long eat;
    pthread_mutex_t *left;
    pthread_mutex_t *right;
} t_philo;


int check_argv(char **argv);
int init_arg(t_arg *arg,  int argc, char **argv);
int init_fork(t_arg *arg);
long long	ft_atoi(const char *nptr);
int	ft_isdigit(int c);

# endif