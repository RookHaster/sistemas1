#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

pid_t objetivo;

void handler(int sig){
	pid_t pid = getpid();
	printf("[%d]: Recibido, respondiendo...\n", pid);
	fflush(stdout);
	sleep(1);
	kill(objetivo,SIGUSR1);
}

int main(){
	signal(SIGUSR1, handler);

	pid_t pid_hijo = fork();

	if (pid_hijo == 0){ // hijo
		objetivo = getppid();
		printf("HIJO: PID = %d // Esperando..\n", pid_hijo);
		fflush(stdout);
		while(1) pause();
	}
	else{
		objetivo = pid_hijo;
		printf("PADRE: PID = %d // Iniciando Ping Pong\n", getppid());
		fflush(stdout);
		sleep(2);
		kill(objetivo,SIGUSR1);
		while(1) pause();
	}
	return 0;
}
