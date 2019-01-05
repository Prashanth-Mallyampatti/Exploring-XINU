/* user.c - main */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 *  main  --  user main program
 *------------------------------------------------------------------------
 */
/*extern long zfunction(long param);*/
int main()
{
kprintf("\n\nHello World, Xinu lives\n\n%x",zfunction(0xaabbccdd));
	printf("\n\n");

	printsegaddress();

printtos();
printprocstks(0);
syscallsummary_start();        
kill(4);
getprio(1);

//	getpid(3);
	gettime(6);
	sleep(10);
	//kill(4);
	signal(4);
kill(4);
	syscallsummary_stop();
	printsyscallsummary();

return 0;
}
