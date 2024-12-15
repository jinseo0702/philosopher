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
    long long start;
    int cnt;
    int fc;
    pthread_mutex_t *fork;
    pthread_mutex_t print;
    pthread_mutex_t eat;
    pthread_mutex_t fin;
} t_arg;

typedef struct s_philo
{
    t_arg *arg;
    pthread_t philo;
    int id;
    long long eat;
    long long btime;
    int die;
    int fis;
    int t_argc;
    long long t_mse;
    pthread_mutex_t *left;
    pthread_mutex_t *right;
    pthread_mutex_t t_fin;
} t_philo;

void msg(t_philo *philo, t_arg *arg, const char *str);
long long check_time(void);
void ft_usleep(long long how);
int destroy_mutex(pthread_mutex_t *mutex);
int init_arg(t_arg *arg,  int argc, char **argv);
t_philo *init_thread(t_arg *arg);
int init_fork(t_arg *arg);
int destroy_fork_philo(t_arg *arg, t_philo *philo);
int check_argv(char **argv);
long long	ft_atoi(const char *nptr);
int	ft_isdigit(int c);
void *do_thread(void *philo);
void do_routin(t_philo *philo);
void ft_start(int argc, char **argv);
void *ft_moniter(void *philo);
void ft_even(t_arg *arg);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void check_died(t_philo *philo, t_arg *arg);
int check_mse(t_philo *philo);
# endif