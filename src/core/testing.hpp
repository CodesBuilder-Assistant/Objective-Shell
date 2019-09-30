#ifndef TESTING_HPP
#define TESTING_HPP
#include <stdio.h>
#include <time.h>
typedef struct
{
    short y;
    short m;
    short d;
}expiration_date;
expiration_date GenerateExpirationDate(unsigned short year,unsigned short month,unsigned short day)
{
    expiration_date return_struct;
    return_struct.y=~year+~month;
    return_struct.m=~month;
    return_struct.d=~year-~month;
    return return_struct;
}

void IsExpired(void)
{
    time_t time_original=time(NULL);
    tm *time_struct;

}
#endif