#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *fp;
    int build=system("readbuild");
    build++;
    fp=fopen(".makefile/BUILD","w");
    fprintf(fp,"%d",build);
    fclose(fp);
    return 0;
}