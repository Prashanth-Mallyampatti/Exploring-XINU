/* getpid.c - getpid */

#include <conf.h>
#include <kernel.h>
#include <proc.h>

/*------------------------------------------------------------------------
 * getpid  --  get the process id of currently executing process
 *------------------------------------------------------------------------
 */
extern int start_trace;
int count1[27][NPROC];
extern unsigned long time[][NPROC];
extern unsigned long ctr1000;
//start_time=ctr1000;
SYSCALL getpid()
{time[2][currpid]=ctr1000;

if(start_trace)
{
	count1[2][currpid]++;
}
time[2][currpid]=ctr1000-time[2][currpid];

	return(currpid);
}
