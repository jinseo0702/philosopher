#include "../include/philo.h"

int main(int argc, char **argv)
{
    if (argc != 5 && argc != 6)
    {
        printf("The number of arguments is different.\n");
        return (1);
    }
    if (check_argv(argv) == -1)
        return (0);
    ft_start(argc, argv);
    return (0);
}

void ft_start(int argc, char **argv)
{
    t_arg arg;
    t_philo *philo;

    init_arg(&arg, argc, argv);
    philo = init_thread(&arg);
    do_routin(philo);
    destroy_fork_philo(&arg, philo);
}