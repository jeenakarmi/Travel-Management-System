#ifndef function_h
#define function_h
#endif // function_h
#include <iostream>
#include <ctime>

//this function checks date and time
int date_check(int year, int month, int day){
    int cur_year, cur_month, cur_day;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cur_year = 1900 + ltm->tm_year;//current year
    cur_month = 1 + ltm->tm_mon;//current month
    cur_day = ltm->tm_mday;//current day

    int year_num = year, temp_year = 0;
    while(year_num != 0){
        year_num = year_num/10;
        temp_year++;
    }
    if(temp_year != 4|| month > 12 || day > 32){
        return 0;
    }else{
        if(year < cur_year){
            return 0;
        }else if(year == cur_year && month < cur_month){
            return 0;
        }else if(year == cur_year && month == cur_month&& day< cur_day){
            return 0;
        }else{
            return 1;
        }
    }
}

//this function check phone number and returns
int phone_check(long long int phone_number){
    long long int num = phone_number, temp = 0;
    long long int first = phone_number;
    while (first > 10){
        first /= 10;
    }
    while(num != 0){
        num = num/10;
        temp++;
    }
    if(temp != 10 || first != 9){
        return 0;
    }else{
        return 1;
    }
}
