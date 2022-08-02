#include <stdio.h>
int main(void){
int x;
printf("Enter some integer: \n");
scanf("%d",&x);
int rows = x;
if(x < 2 || x > 10){
printf("Invalid integer.\n");
return 0;
}
while(rows > 0){
	int columns = rows-1;
		for(int y = 0; y <= columns; y++){
		printf(" ");
		}
	printf("*\n");
	rows=rows-1;
}
return 0;
}

