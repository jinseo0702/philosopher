#include "lab.h"

void *p_function(void *data);
int num = 0;
pthread_mutex_t key;

void *p_function(void *data)
{
    int pid;
    int tid;

    pid = getpid();
    tid = pthread_self();
    char *thread_name = (char *)data;
    int i = 0;

    while (i < 100000000)
    {
		pthread_mutex_lock(&key);
        // printf("thread name : %s, tid : %x, pid : %u\n", thread_name, (unsigned int)tid, (unsigned int)pid);
        i++;
		num++;
		pthread_mutex_unlock(&key);
        // sleep(1);
    }
}

int main(void)
{
    pthread_t pthread[2];
    int thr_id;
    int status;
    char p1[] = "jinseo_thread1";
    char p2[] = "jinseo_thread2";
    char p3[] = "jinseo_thread3";
	pthread_mutex_init(&key, NULL);

    sleep(1);

    thr_id = pthread_create(&pthread[0], NULL, p_function, (void*)p1);
    thr_id = pthread_create(&pthread[1], NULL, p_function, (void*)p2);
    if (thr_id < 0)
    {
        perror("pthread1 create error");
        exit(EXIT_FAILURE);
    }

    // p_function((void *)p3);

    pthread_join(pthread[0], (void **)&status);
    printf("pthread[0] status value is %d \n", status);
    pthread_join(pthread[1], (void **)&status);

    printf("num is %d \n", num);
    printf("end??\n");
	pthread_mutex_destroy(&key);

    return (0);
}