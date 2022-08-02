#include <stdio.h>
#include <stdlib.h>
int main(char* argv[]){
int x = argv[1];
int y = argv[2];
int a,b;
int **firstArr = (int**)malloc(x * sizeof(int *));
for(a = 0; a<x;a++){
	firstArr[a]=(int*)malloc(x*sizeof(int));
}
for(a =0;a<x;a++){
	for(b=0;b<y;b++){
		firstArr[a][b] = (rand()%101)-50;
	}
}
printf("first matrix:\n");
for(a =0;a<x;a++){
        for(b=0;b<y;b++){
		printf("%d\t",firstArr[a][b]);
	}
	printf("\n");
}
int **secondArr = (int**)malloc(x*sizeof(int*));
for(a = 0; a<x;a++){
       secondArr[a]=(int*)malloc(x*sizeof(int));
}
for(a=0;a<x;a++){
        for(b=0;b<y;b++){
               secondArr[a][b] = firstArr[x-a-1][b];
        }
}
printf("second matrix:\n");
for(int a =0;a<x;a++){
        for(int b=0;b<y;b++){
                printf("%d\t",secondArr[a][b]);
        }
	printf("\n");
}
return 0;
}


