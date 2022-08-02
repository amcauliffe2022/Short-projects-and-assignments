#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    char *input = argv[1];
    int len = strlen(argv[1]);
    if (fork() == 0){
    printf("I am the child. Printing the original version:\n");
    for(int a = 0; a < len; a++){
        printf("%c",input[a]);
    }
    
    printf("\n");
    }else{
        wait(NULL);
        char temp[len + 1];
        for(int x = 0; x < len; x++){
            temp[x]= 97 + (122 - input[x]);
        }
        printf("I am the parent. Printing the original and complementary version:\n");
    for(int b = 0; b < len; b++){
        printf("%c",input[b]);
    }
    printf("\n");
    for(int c = 0; c < len;c++){
        printf("%c",temp[c]);
    }
    }
    
    return 0;
}

