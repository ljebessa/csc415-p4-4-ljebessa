#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
/**
 * THESE DEFINE VALUES CANNOT BE CHANGED.
 * DOING SO WILL CAUSE POINTS TO BE DEDUCTED
 * FROM YOUR GRADE
 */
 /** BEGIN VALUES THAT CANNOT BE CHANGED */
#define MAX_THREADS 36
#define MAX_ITERATIONS 22
/** END VALUES THAT CANNOT BE CHANGED */


/**
 * use this struct as a parameter for the
 * nanosleep function.
 * For exmaple : nanosleep(&ts, NULL);
 */
struct timespec ts = {0, 150000};
pthread_t tid[MAX_THREADS];
char *strerror(int errnum);
int G_Val = 0;

void bold_magenta()
{
    printf("\033[1;35m");
}
void bold_cyan()
{
    printf("\033[1;36m");
}
void red()
{
    printf("\033[0;31m");
}
void resetColor()
{
    printf("\033[0m");
}
void* Add_Thread(void *tid){
    int threadId = *((int*)tid);
    int i =0;
    while ( i < MAX_ITERATIONS){
        signed int Temp_V = G_Val;
        nanosleep(&ts, NULL);
        Temp_V = Temp_V + 10;
        G_Val = Temp_V;
        red();
        printf("Current Value written to Global Variables by thread : %d is %d\n",threadId, G_Val);
        resetColor();
        i++;
    }
    return NULL;

}
void* Sub_Thread(void *tid){
    int threadId = *((int*)tid);

    int i =0;
    while ( i < MAX_ITERATIONS){
        signed int Temp_V = G_Val;
        nanosleep(&ts, NULL);
        Temp_V = Temp_V - 10;
        G_Val = Temp_V;
        bold_cyan();
        printf("Current Value written to Global Variables by thread : %d is %d\n", threadId, G_Val);
        resetColor();
        i++;
    }
    return NULL;

}
int main(int argc, char** argv)
{

    int err;
    for (int i = 0; i < MAX_THREADS; i++ ){
        if ( i % 2 == 0){
            err = pthread_create(&tid[i], NULL, &Add_Thread,  (void*)&i);// create a thread
            if( err !=0){
                printf("ERROR! can not create ADDER THREADS: %s", strerror(err));
                exit(1);
            }
        }else{
            err = pthread_create(&tid[i], NULL, &Sub_Thread,  (void*)&i);
            if( err){
                printf("ERROR! can not create SUBTRACTOR THREADS: %s", strerror(err));
                exit(1);
            }
        }

    }
    for (int i = 0; i <= MAX_THREADS; i++){
        pthread_join(tid[i], NULL);
    }
    bold_magenta();
    printf("Final Value of Shared Variable : %d\n",G_Val);
    resetColor();
    return 0;
}



