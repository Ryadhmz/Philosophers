#include "philo/philosophers.h"

void routine(void)
{
    int nb = 0;
    printf("Debut thread %d\n", nb);
    nb += 1;
    sleep(1);
    printf("Valeur : %d\n", nb);
    printf("Fin thread\n");


}

int main(void)
{
    pthread_t p1;
    pthread_t p2;
    pthread_create(&p1, NULL, &routine, NULL);
    pthread_create(&p2, NULL, &routine, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    return 0;
}