#ifdef loadingfnc_h
#define loadingfnc_h
#endif // loading
#include <iostream>
#include<windows.h>

void firstload(){
    char msg[40] = "WELCOME TO TRAVEL MANAGEMENT SYSTEM";
    for(int i=0;i<40;i++){
        std::cout<<msg[i];
        Sleep(50);
    }
}

void admindashboardload(){
    char msg[30] = "WELCOME TO ADMIN DASHBOARD";
    for(int i=0;i<30;i++){
        std::cout<<msg[i];
        Sleep(50);
    }
}

void loading(){
    std::cout<<"Loading";
    for(int i = 0; i<3; i++){
        std::cout<<".";
        Sleep(500);
    }
    system("cls");
}
