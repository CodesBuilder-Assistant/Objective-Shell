#ifndef LOG_HPP
#define LOG_HPP
#include <stdio.h>
constexpr char *LOG_FILENAME="objsh.log";
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
#endif