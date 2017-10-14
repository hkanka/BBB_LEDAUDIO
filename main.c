//
// Created by joek on 10/4/16.
//

#include <stdbool.h>
#include "BBB_P10.h"
#include "udp.h"
#include <pthread.h>
#include <stdlib.h>

bool Scanning = true;
const char *MSG = "No Audio";
typedef struct {
    pthread_mutex_t mutex;
    pthread_t thread;
}threadstruct;
unsigned char hi[64];
void *scan_thread(void *data){
    threadstruct *threadstruct1 = (threadstruct*)data;
    while(Scanning){
        pthread_mutex_lock(&threadstruct1->mutex);
        Scan_Panels();
        pthread_mutex_unlock(&threadstruct1->mutex);
    }
    pthread_exit(NULL);
}
void *display_thread(void *data){
    threadstruct *threadstruct1 = (threadstruct*)data;
    while(Scanning){

        receivefb(hi);
        pthread_mutex_lock(&threadstruct1->mutex);
        Fill_Buffer(hi);
        pthread_mutex_unlock(&threadstruct1->mutex);

    }

    pthread_exit(NULL);
}
int main(int argc, char *argv[]) {
    int res;
    Setup_Pins();
    Clear_Buffer(false);
    //drawmessage(MSG,AlignHCenter,AlignCenter);
    udp_setup_socket(80);
    threadstruct *threadstruct1 = malloc(sizeof(threadstruct));
    pthread_mutex_init(&(threadstruct1->mutex), NULL);
    res = pthread_create(&threadstruct1->thread, NULL, scan_thread, threadstruct1);
    if (res < 0) {
        printf("failed to create thread %d\n", res);
        return res;
    }

    threadstruct *threadstruct2 = malloc(sizeof(threadstruct));
    pthread_mutex_init(&(threadstruct2->mutex), NULL);
    res = pthread_create(&threadstruct2->thread, NULL, display_thread, threadstruct2);
    if (res < 0) {
        printf("failed to create thread %d\n", res);
        return res;
    }

    pthread_join(threadstruct1->thread, NULL);
    pthread_join(threadstruct2->thread, NULL);

    pthread_mutex_destroy(&threadstruct1->mutex);
    pthread_mutex_destroy(&threadstruct2->mutex);

    Free_BBB_P10();

    return 0 ;
}