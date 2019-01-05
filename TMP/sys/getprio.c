/* getprio.c - getprio */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 * getprio -- return the scheduling priority of a given process
 *------------------------------------------------------------------------
 */
extern int start_trace;
extern int count1[27][NPROC];
extern unsigned long time[][NPROC];
extern unsigned long ctr1000;
SYSCALL getprio(int pid)
{time[3][currpid]=ctr1000;

if(start_trace)
	count1[3][currpid]++;
	STATWORD ps;    
	struct	pentry	*pptr;

	disable(ps);
	if (isbadpid(pid) || (pptr = &proctab[pid])->pstate == PRFREE) {
		restore(ps);
		return(SYSERR);
	}
	restore(ps);
time[3][currpid]=ctr1000-time[3][currpid];

	return(pptr->pprio);
}
