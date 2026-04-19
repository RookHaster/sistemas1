#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

int x = 0, y = 0, a = 0, b = 0;

void* foo(void* v){
	pthread_mutex_lock(&m);
	x = 1;
	a = y;
	pthread_mutex_unlock(&m);
	return NULL;
}

void* bar(void* v){
	pthread_mutex_lock(&m);
	y = 1;
	b = x;
	pthread_mutex_unlock(&m);
	return NULL;
}

int main(){
	pthread_t t0, t1;
	pthread_create(&t0, NULL, foo, NULL);
	pthread_create(&t1, NULL, bar, NULL);
	pthread_join(t0, NULL);
	pthread_join(t1, NULL);
	assert(a || b);
	return 0;
}
