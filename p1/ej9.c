#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int sig){
	char c;
	printf("Seguro que quieres salir? [y/n] ");
	c = getchar();
	if (c=='y' || c=='Y') exit(0);
}

int main(){
	signal(SIGINT, handler);
	while(1) sleep(10);
}
