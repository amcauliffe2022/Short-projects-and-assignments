#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<time.h>
#include<sys/wait.h>

int main()
{
    int p[2];
    if(pipe(p) == -1){
        printf("Pipe Error");
    }
    
    int P = fork();
    if(P == 0){
        close(p[0]);
        int arr[20];
        for(int x = 0; x < 20; x++){
            arr[x] = (rand()%25) - 5; 
        }
        printf("child sent into unnamed pipe\n");
        for(int y = 0; y < 10;y++){
                printf("%d,",arr[y]);
        }
        for(int y = 10; y < 20;y++){
         printf("%d,",arr[y]);
        }
        write(p[1],&arr,sizeof(int)*20);
        close(p[1]);
        printf("\n");
    }
    else
    {
        close(p[1]);
        int arr2[20];
        read(p[0],&arr2,sizeof(int) * 20);
        printf("parent received into unnamed pipe\n");
        for(int y = 0; y < 10;y++){
            printf("%d,",arr2[y]);
        }
        for(int y = 10; y < 20;y++){
            printf("%d,",arr2[y]);
        }
        
        int  temp;
        for(int x = 0; x < 10; x++){
            temp = temp + (arr2[x] * arr2[x + 10]);
        }
        printf("\nThe two vectors are orthogonal?");
        if(temp == 0){
            printf("yes");
        }
        else{
            printf("no");
        }
    }
    return 0;
}