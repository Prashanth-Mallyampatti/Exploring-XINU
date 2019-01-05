#include<stdio.h>
void printtos()
{      

register int *bpa asm ("bp");
printf("\nvoid printtos()\n");
printf("Before[0x%08x]: 0x%08x",bpa+2,*(bpa+2));
printf("\nAfter[0x%08x]: 0x%08x\n",bpa,*(bpa));

register int *spa asm ("sp");
int i;
int a,b,c,d;
a=1;
b=2;
c=3;
d=4;
/*
__asm__("push $1;");*/

for(i=1;i<=4;i++)
	printf("	elements[0x%08x]: 0x%08x\n",spa+i,*(spa+i));
}
