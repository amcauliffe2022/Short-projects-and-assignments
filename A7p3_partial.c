//to compile: gcc A7p3.c -lpthread -fpermissive -w -o A7p3
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <pthread.h>

int gnum_threads;
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
int ga,gb,gcount[3]={0};//gcount[0],gcount[1],gcount[2] will store the number of integers from ga~gb whose Collatz list length <;=;> the integer itself respectively
//if we don't use the global gcount, then no need to use count_mutex
void usage(char *s)
{
	fprintf(stderr,....);
	exit(0);
}

void *thread_function( void *arg )
{
	int index,i;//index will become 0,1,...,gnum_threads-1
	index = (int)(long)arg;//we may need "-fpermissive" when compiling to avoid possible warnings or errors.
	int count[3]={0,0,0};//count[0],count[1],count[2] will store the number of integers from index*(gb-ga+1)/gnum_threads+ga to (index+1)*(gb-ga+1)/gnum_threads +ga-1 whose Collatz list has length <;=;> the integer itself respectively

	for(i=index*(gb-ga+1)/gnum_threads+ga;i<=...;i++)//each thread processes a subset ((gb-ga+1)/gnum_threads) of integers between ga and gb
	{
		int t=i,y=1;//y will store the Collatz list length for t (we save a copy of i because we do not want to mess with i)
		while(t!=1) 
		{
			if(t%2)//odd
				t=...;
			else//even
				t=t/2;
			y++;
		}
		if(y<i) count[0]++;
		else if(y==i) ...;
		else count[2]++;
	}//for
	pthread_mutex_lock(&count_mutex);//updating global array gcount now; use mutex to avoid race condition
	for(i=0;i<3;i++) gcount[i]+=...;
	pthread_mutex_unlock(...);
}//thread_function

int main(int argc, char *argv[])
{
	if(argc!=2) usage(argv[0]);
	ga=atoi(argv[1]);
	gb=atoi(argv[2]);
	gnum_threads=atoi(argv[3]);
	assert(...);
	printf("using %d threads.\n",gnum_threads);
	
	pthread_t thread[gnum_threads];
	
	int i,tmp;
	for(i=0; i<gnum_threads; i++) {
		tmp = pthread_create(&thread[i], NULL, ..., (void *)i);
		if(tmp != 0) {
			fprintf(stderr,"Creating thread %d failed\n", i);
			return 1;
		}
	}

	for(i=0; i<gnum_threads; i++) {
		tmp = pthread_join(thread[i], NULL);
		if(tmp != 0) {
			fprintf(stderr,"Joining thread %d failed\n", i);
			return 1;
		}
	}
	//for(i=0;i<3;i++) printf("gcount[%d]=%d\n",i,gcount[i]);
	//assert(gcount[0]+gcount[1]+gcount[2]==gb-ga+1);
	printf("The number of integers from %d~%d whose Collatz list length is < the integer itself is %d\n",ga,gb,gcount[0]);
	printf("The number of integers from %d~%d whose Collatz list length is = the integer itself is %d\n",ga,gb,gcount[1]);
	printf("The number of integers from %d~%d whose Collatz list length is > the integer itself is %d\n",ga,gb,gcount[2]);
	free(thread);
	return 0;
}//main
