#include <stdio.h>
extern int etext, edata, end;

void x()
{
    printf("First address past:\n");
    printf("    program text (etext)      %8x\n", &etext);
    printf("    initialized data (edata)  %8x\n", &edata);
    printf("    uninitialized data (end)  %8x\n", &end);

}
