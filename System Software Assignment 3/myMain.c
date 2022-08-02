#include <stdio.h>
#include "mysource.h"

int main(){
int len;
printf("Enter the length \n");
scanf("%d",&len);
char myarr[len];
printf("\nOriginal random string:\n");
generateChars(&myarr,len);
printChars(&myarr,len);
printf("\nOffset string\n");
offsetChars(&myarr,len);
printChars(&myarr,len);
return 0;
}
