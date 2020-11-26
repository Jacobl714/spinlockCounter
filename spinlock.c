#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int x = 0;
pthread_spinlock_t spin;

void increase(int cnt){
    int i;
    for(i=0; i<cnt; i++){
        pthread_spin_lock(&spin);
        x = x+1;
        pthread_spin_unlock(&spin);
    }
}

int main(int argc, char* argv[]){
    pthread_t tid1, tid2;
    int status;
    long cnt = atol(argv[1]);
    pthread_spin_init(&spin, 0);
    status = pthread_create(&tid1, NULL, (void*(*)(void*))increase, (void*)cnt);
    status = pthread_create(&tid2, NULL, (void*(*)(void*))increase, (void*)cnt);
    void *v1, *v2;
    pthread_join(tid1, &v1);
    pthread_join(tid2, &v2);
    pthread_spin_destroy(&spin);
    printf("counter is %d\n", x);
    return 0;
}
