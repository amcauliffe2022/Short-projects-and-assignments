#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int GT,E,LT = 0;
int span;

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
void Check(int start){
    int temp = start;
    int count = 0;
    while(temp > 1){
        if(temp %2 != 0){
            temp = (3*temp +1)/2;
        }
        else{
            temp = temp/2;
        }
        count++;
    }
    if(start < count){
        LT++;
    }
    else if(start > count){
        GT++;
    }
    else{
        E++;
    }
}
void *threadFun(void *arg){
    int *p = (int *)arg;
    for(int x = 0; x <= span; x++){
    pthread_mutex_lock(&count_mutex);
    Check(((*p)+x));
    pthread_mutex_unlock(&count_mutex);
    }
}
int main(int argc, char *argv[])
{
    int lower = atoi(argv[1]);
    int upper = atoi(argv[2]);
    int threadNum = atoi(argv[3]);
    span = (upper - lower)/threadNum;
    pthread_t t[threadNum];
    
    for(int x = 0; x < threadNum; x++){
        int temp = lower + (x * span);
        int *p = &temp;
       pthread_create(&t[x],NULL,threadFun,p);
    }
    for(int y = 0; y < threadNum; y++){
        pthread_join(t[y],NULL);
    }
    printf("using %d threads.\nThe number of integers from %d~%d whose Collatz list length is < the integer itself is %d\nThe number of integers from %d~%d whose Collatz list length is = the integer itself is %d\nThe number of integers from %d~%d whose Collatz list length is > the integer itself is %d", threadNum,lower,upper,GT,lower,upper,E,lower,upper,LT);

    return 0;
}


