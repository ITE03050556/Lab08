#include<stdio.h>
#include<sys/types.h>

int main(void)
{
	int pid,i;
	int status=0;
	
	for(i=0;i<3;i++)
	{
		pid=fork();
		if(pid!=0)
		{
			/*parent*/
			//printf("child%d PID: %d\n",i,pid);
			pid=wait(&status);
			printf("child%d PID: %d\n",i,pid);
		}
		else
		{
			/*child*/
			printf("parent PID: %d,child%d PID: %d\n",getppid(),i,getpid());
			exit(status);
		}
	}
	
	return 0;
}

    Contact GitHub API Training Shop Blog About 


