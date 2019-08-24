#ifndef LOG_HPP
#define LOG_HPP
#include <stdio.h>
const char *LOG_FILENAME="objsh.log";
void ClearLogFile(void)
{
    FILE *logfile_fp=fopen(LOG_FILENAME,"w");
    fclose(logfile_fp);
}

#define LOGINFO_ERROR "Error"
#define LOGINFO_WARNING "Warning"
#define LOGINFO_NOTE "Note"
#define LOGINFO_OPERATION "Operation"

void WriteLogInfo(char *i_type,char *log_msg)
{
    FILE *logfile_fp=fopen(LOG_FILENAME,"a");
    fprintf(logfile_fp,"[%s]%s\n",i_type,log_msg);
    fclose(logfile_fp);
}

void OutputAllLog(void)
{
    FILE *logfile_fp;
    if((logfile_fp=fopen(LOG_FILENAME,"r"))==NULL)
    {
        fclose(logfile_fp);
        return;
    }
    char current_log[256];
    while(fgets(current_log,256,logfile_fp)!=(char *)EOF)
        puts(current_log);
    fclose(logfile_fp);
}
#endif