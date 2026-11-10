// esempio di single producer 2 consumer con più condition variable

#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

#define LOOPS 15
#define CONSUMERS 2

volatile bool full = false;
volatile int buf = 0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t ccv = PTHREAD_COND_INITIALIZER;
pthread_cond_t pcv = PTHREAD_COND_INITIALIZER;

void *producer(void *arg) {
    for (int i = 1; i < LOOPS; ++i) {
        pthread_mutex_lock(&m);
        while (full)
            pthread_cond_wait(&pcv, &m);
        buf = i;
        full = true;
        pthread_cond_signal(&ccv);
        pthread_mutex_unlock(&m);
    }
}

void *consumer(void *arg) {
    int id = *(int*)arg;
    for (int i = 0; i < LOOPS - 1; ++i) {
        pthread_mutex_lock(&m);
        while (!full)
            pthread_cond_wait(&ccv, &m);
        int x = buf;
        buf = 0;
        full = false;
        pthread_cond_signal(&pcv);
        pthread_mutex_unlock(&m);
        printf("consumer %d got %d\n", id, x);
    }
}

int main(void) {
    pthread_t consumer_tids[CONSUMERS];
    pthread_t producer_tid;
    pthread_create(&producer_tid, NULL, producer, NULL);
    int consumers[CONSUMERS] = {0};
    for (int i = 0; i < CONSUMERS; ++i) {
        consumers[i] = i;
        pthread_create(&consumer_tids[i], NULL, consumer, &consumers[i]);
    }

    pthread_join(producer_tid, NULL);
    return 0;
}
