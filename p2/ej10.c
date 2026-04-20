#include <stdio.h>
#include <pthread.h>

int array[10] = {1,1,1,1,1,1,1,1,1,1};
int len = 10;
int i = 0;
int total = 0;

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void* count1(void* arg){
	while (i < len){
		pthread_mutex_unlock(&m);	
		pthread_mutex_lock(&m);
		total += array[i];
		i += 1;
	}
	return NULL;
}

void* count2(void* arg){
	while (i < len){
		pthread_mutex_unlock(&m);	
		pthread_mutex_lock(&m);
		total += array[i];
		i += 1;
	}
	return NULL;
}

int main(){
	pthread_t t1, t2;
	pthread_create(&t1, NULL, count1, NULL);
	pthread_create(&t2, NULL, count1, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("total: %d\n", total);
	return 0;
}
