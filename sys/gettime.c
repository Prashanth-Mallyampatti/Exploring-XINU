/* gettime.c - gettime */

#include <conf.h>
#include <kernel.h>
#include <date.h>
#include<proc.h>
extern int getutim(unsigned long *);

/*------------------------------------------------------------------------
 *  gettime  -  get local time in seconds past Jan 1, 1970
 *------------------------------------------------------------------------
 */
extern int start_trace;
extern int count1[27][NPROC];
extern unsigned long time[][NPROC];
extern unsigned long ctr1000;
SYSCALL	gettime(long *timvar)
{time[4][currpid]=ctr1000;

if(start_trace)
count1[4][currpid]++;
    /* long	now; */

	/* FIXME -- no getutim */
time[4][currpid]=ctr1000-time[4][currpid];

    return OK;
}
