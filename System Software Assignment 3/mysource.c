#include <stdio.h>
#include "mysource.h"

void generateChars(char *myarr, int len){
	int x;
	for(x = 0; x<len;x++){
		myarr[x] = 'a' + (rand() %26);
	}
}
void offsetChars(char *myarr, int len){
	int x;
	char a;
	for(x = 0; x<len; x++){
		for(a = 'a'; a <= 'z'; a++){
			if(myarr[x] == a){
				myarr[x]= a + 1;
				break;
			}
			if(myarr[x] == 'z'){
				myarr[x] = 'a';
				break;
			}
		}
	}
}
void printChars(char *myarr, int len){
	int x;
	for(x=0; x<len;x++){
		printf("%c",myarr[x]);
	}
}

