#include <stdio.h>
int main(void){
for(int a = 0; a <= 15; a++){
int b = 8;
int lines = 0;
while(b > 0){
if((a & b)!= 0){
printf(" 1 ");
}
else{
printf(" -1 ");
}
lines ++;
if(lines == 2){
printf("\n");
}
b = b/2;
}
printf("\n\n");

}
return 0;
}
