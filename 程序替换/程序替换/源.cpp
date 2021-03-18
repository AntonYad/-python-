#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("begin\n");
	sleep(1);
	execl("/usr/bin/ls", "ls", "-l", NULL);
	execlp("ls", "ls", "-a", NULL);//不带PATH
	char *arg[] = { "-a", "-l", NULL };
	execv("/usr/bin/ls", arg);//将指令放入数组中
	execvp("ls", arg);//PATH
	char *env[] = { "hello world", NULL };
	execle("./myproc", "./myproc", NULL, env);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main()
{
	pid_t id = fork();
	if (id < 0)
	{
		perror("fork");
		return 1;
	}
	else if (id > 0){ //parent
		printf("parent[%d] is sleeping...\n", getpid());
		sleep(5);
	}
	else
	{
		printf("child[%d] is begin Z...\n", getpid());
		sleep(30);
		exit(EXIT_SUCCESS);

	}
	printf("procenv:%s\n", getenv("env"));
	return 0;
}
