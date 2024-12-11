#include "../include/philo.h"

int main(int argc, char **argv)
{
    if (check_argv(argv) == -1)
        return (0);
    if (argc == 5)
        ft_start(argc, argv);
    else if (argc == 6)
        ft_start(argc, argv);
    else
        printf("The number of arguments is different.\n");
    return (0);
}

void ft_start(int argc, char **argv)
{
    t_arg arg;
    t_philo *philo;

    init_arg(&arg, argc, argv);
    philo = init_thread(&arg);
    do_routin(philo);
}