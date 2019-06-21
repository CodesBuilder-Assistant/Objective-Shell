#ifndef GOTOFUNC_HPP
#define GOTOFUNC_HPP
#include <math.h>
#include <stdio.h>
void ShowRandomContent(void)
{
    srand(65535);
    unsigned short random_id=rand();
}
void ASCIITable(void)
{
    for(char i=0;i<127;i++)
    {
        printf(" Character  Value");
        printf(" %c         %d\n",i,(int)i);
    }
}
#endif