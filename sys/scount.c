/* scount.c - scount */

#include <conf.h>
#include <kernel.h>
#include <sem.h>
#include<proc.h>
/*------------------------------------------------------------------------
 *  scount  --  return a semaphore count
 *------------------------------------------------------------------------
 */
extern int start_trace;
extern int count1[27][NPROC];
extern unsigned long time[][NPROC];
extern unsigned long ctr1000;
SYSCALL scount(int sem)
{time[10][currpid]=ctr1000;

extern	struct	sentry	semaph[];
if(start_trace)
count1[10][currpid]++;
	if (isbadsem(sem) || semaph[sem].sstate==SFREE)
	
{time[10][currpid]=ctr1000-time[10][currpid];

return(semaph[sem].semcnt);
}
}
