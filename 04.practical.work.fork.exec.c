#include<stdio.h>
#include<unistd.h>
int main(){
printf("main before fork()");
int pid1 = fork();
	if (pid1 == 0){
		printf("lauching ps -ef\n");
		char *args[]= { "/bin/ps", "-ef" , NULL};
		execvp("/bin/ps", args);
		}
	else { 
	printf("This is Parent, Child = %d\n", pid1);
	int pid2 = fork();
	if (pid2 == 0){
		printf("lauching free -h\n");
		char *args[] = {"/bin/free","-h",NULL};
		execvp("/usr/bin/free",args);
		}
	else {
	printf("This is Parent, Child = %d\n", pid2);}
	}
return 0;
}
