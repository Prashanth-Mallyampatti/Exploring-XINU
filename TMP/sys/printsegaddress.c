#include <stdio.h>

int etext, edata, end;

void printsegaddress()
{
    printf("void printsegaddress()\n\n");
    printf("Current: etext[0x%08x]=0x%08x, edata[0x%08x]=0x%08x, ebss[0x%08x]=0x%08x\n", &etext,etext,&edata,edata,&end,end);

printf("Preceding: etext[0x%08x]=0x%08x, edata[0x%08x]=0x%08x, ebss[0x%08x]=0x%08x\n",&etext-1,*(&etext-1),&edata-1,*(&edata-1),&end-1,*(&end-1));

printf("After: etext[0x%08x]=0x%08x, edata[0x%08x]=0x%x, ebss[0x%08x]=0x%08x\n",&etext+1,*(&etext+1),&edata+1,*(&edata+1),&end+1,*(&end+1));

}
