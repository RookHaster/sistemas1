#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define VISITANTES 40000

int total = 0;

int flag[2] = {0};
int turn;

void* molinete1(void* v){
	for (int i = 0; i < VISITANTES/2; i++){
		flag[0] = 1;
		turn = 1;
		while(flag[1] && turn == 1);
		total += 1; // seccion critica
		flag[0] = 0;
	}
	return NULL;
}

void* molinete2(void* v){
	for (int i = 0; i < VISITANTES/2; i++){
		flag[1] = 1;
		turn = 0;
		while(flag[0] && turn == 0);
		total += 1; // seccion critica
		flag[1] = 0;
	}
	return NULL;
}

int main(){
pthread_t t0, t1;
pthread_create(&t0, NULL, molinete1, NULL);
pthread_create(&t1, NULL, molinete2, NULL);
pthread_join(t0, NULL);
pthread_join(t1, NULL);
printf("total: %d\n", total);
return 0;
}
