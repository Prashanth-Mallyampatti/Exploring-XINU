/* setdev.c - setdev */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
extern int start_trace;
extern int count1[27][NPROC];
extern unsigned long time[][NPROC];
extern unsigned long ctr1000;
/*------------------------------------------------------------------------
 *  setdev  -  set the two device entries in the process table entry
 *------------------------------------------------------------------------
 */
SYSCALL	setdev(int pid, int dev1, int dev2)
{time[13][currpid]=ctr1000;

if(start_trace)
count1[13][currpid]++;
	short	*nxtdev;

	if (isbadpid(pid))
		return(SYSERR);
	nxtdev = (short *) proctab[pid].pdevs;
	*nxtdev++ = dev1;
	*nxtdev = dev2;
time[13][currpid]=ctr1000-time[13][currpid];
	
return(OK);
}
