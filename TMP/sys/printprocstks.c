#include<stdio.h>
#include<conf.h>
#include<kernel.h>
#include<proc.h>

void printprocstks(int priority)
{
int i;
struct pentry *p;
printf("\nvoid printprocstks(int priority)");

for(i=0;i<NPROC;i++)
{
p=&proctab[i];

if(p->pstate!='\002' && p->pprio>priority)
{
	printf("\nProcess [%s]\n",p->pname);
	printf("	pid: %d\n",i);
	printf("	priority: %d\n",p->pprio);
	printf("	base: 0x%08x\n",p->pbase);
	printf("	limit: 0x%08x\n",p->plimit);
	printf("	len: %d\n",p->pstklen);
	
	if(i==currpid)
	{
	register int *sp asm("esp");
	printf("	pointer: 0x%08x\n",sp);
	}
	else
	printf("	pointer: 0x%08x",p->pesp);
	}
}
}
