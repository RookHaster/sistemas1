#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define VISITANTES 40000
int total = 0;

void* molinete1(void* arg){
	int i;
	for (i = 0; i < VISITANTES/2; i++){
		int c;
		c = total;
		usleep(200);
		total = c + 1;
	}
	return NULL;
}


void* molinete2(void* arg){
	int i;
	for (i = 0; i < VISITANTES/2; i++){
		int c;
		c = total;
		usleep(200);
		total = c + 1;
	}
	return NULL;
}

int main(){
	pthread_t t1, t2;
	pthread_create(&t1, NULL, molinete1, NULL);
	pthread_create(&t2, NULL, molinete2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("total: %d\n", total);
	return 0;
}
