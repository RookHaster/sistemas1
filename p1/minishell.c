#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(){
	int sen = 1;
	char *line = NULL;
	char *args[64];
	size_t len = 0;
	int read;
	while(sen){
		printf(">>> ");
		read = getline(&line, &len, stdin);
		if (line[read-1] == '\n') line[read-1] = '\0';
		char *token = strtok(line, " ");
		int i = 0;
		int j = -1;
		while (token != NULL){
			args[i] = token;
			if(!strcmp(args[i],">")){
				j = i;
				args[i] = NULL;
			}
			i++;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;
		int pid = fork();
		if (pid == 0){
			if(j == -1) execvp(args[0],args);
			else {
				int fd = open(args[j+1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
				dup2(fd, 1);
				execvp(args[0],args);
			}
		}
		else {
			wait(0);
		}
	}
	return 0;
}
