#include <stdio.h>
int main(void)
{
    FILE *fp;
    if((fp=fopen(".makefile/BUILD","r"))==NULL)
    {
        fclose(fp);
        fp=fopen(".makefile/BUILD","w");
        fprintf(fp,"1");
        fclose(fp);
        fp=fopen(".makefile/BUILD","r");
    }
    int build;
    fscanf(fp,"%d",&build);
    fclose(fp);
    return build;
}