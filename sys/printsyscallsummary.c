#include<conf.h>
#include<kernel.h>

#include<proc.h>
#include<stdio.h>
char sys[27][10]={"freemem","chprio","getpid","getprio","getttime","kill","recieve","recvclr","recvtim","resume","scount","sdelete","send","setdev","setnoc","screate","signal","signaln","sleep","sleep10","sleep100","sleep1000","sreset","stacktrace","suspend","unsleep","wait"};

int count1[][NPROC]={{0}};
int start_trace=0;
unsigned long time[][NPROC]={{0}};
int a=0,c=0;
extern unsigned long ctr1000;
//unsigned long start_time[]={0};
unsigned long t;
void syscallsummary_start()
{
start_trace=1;
t=ctr1000;
//start_time=ctr1000;
}
void syscallsummary_stop()
{
start_trace=0;

}
void printsyscallsummary()
{
int i,j;
struct pentry *p;
printf("\nvoid printsyscallsummary()");
for(i=0;i<NPROC;i++)
{
p=&proctab[i];
if(p->pstate!='\002')
{
	for(j=0;j<27;j++)
	{
	if(count1[j][i]==0)
		c++;
	}
	if(c==27)
		continue;

	printf("\nProcess: [pid:%d]",i);
j=0;
	for(j=0;j<27;j++)
	{
	if(count1[j][i]==0)
	{
	continue;
	}
	else
	{

		printf("\n	Syscall: sys_%s, count:%d",sys[j],count1[j][i]);
//		printf(", average execution time: %lu (ms)",ctr1000-t);
		printf(", average execution time: %lu (ms)",(time[j][i])/count1[j][i]);
		t=ctr1000;
	}
	}
}
}
}
