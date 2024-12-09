#include "../include/philo.h"

int main(int argc, char **argv)
{
    t_arg arg;
    t_philo philo;

    if (argc >= 5 && argc <= 6)
    {
        if (check_argv(argv) == -1)
            return (0);
         init_arg(&arg,  argc, argv);
        printf("Hello Wrold\n");
    }
    else
        printf("The number of arguments is different.\n");
    return (0);
}