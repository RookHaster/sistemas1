#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <assert.h>

volatile int x = 0;
volatile int y = 0;

void* wr(void* v){
	x = 123;
	y = 1;
	return NULL;
}

void* rd(void* v){
	while(!y);
	assert(x == 123);
}

int main(){
pthread_t t0, t1;
pthread_create(&t0, NULL, wr, NULL);
pthread_create(&t1, NULL, rd, NULL);
pthread_join(t0, NULL);
pthread_join(t1, NULL);
return 0;
}
