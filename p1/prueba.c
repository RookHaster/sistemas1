#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(){
	char buff[] = "nigga";
	char buffread[10];
	int pipefd[2];
	pipe(pipefd);
	int pid = fork();
	
	if(pid == 0){
	printf("esto es el hijo\n");
	close(pipefd[1]);
	read(pipefd[0], &buffread, strlen(buff)+1);
	printf("mensaje leido: %s\n", buffread);
	//printf("%c\n", buffread[0]);
	}

	else{
	close(pipefd[0]);
	printf("esto es el padre\n");
	write(pipefd[1], buff, strlen(buff)+1);
	}
	return 0;
}
