#ifndef cusgraphics_h
#define cusgraphics_h
#endif // mygraphics
#include <iostream>
#include <windows.h>

void gotoxy(int x, int y){
    COORD c;
    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

class mygraphics{
public:
    void hr(int,int,int, char c=196);
    void vr(int,int,int, char c=179);
    void box(int, int, int, int);
};

void mygraphics::box(int x1, int x2, int y1, int y2){
    char ch1, ch2, ch3, ch4, l1,l2;
    ch1=218;//topleft
    ch2=192;//bottomleft
    ch3=191;//topright
    ch4=217;//bottomright
    l1 = 196;
    l2 = 179;
    gotoxy(x1, y1);
    std::cout<<ch1;
    gotoxy(x1, y2);
    std::cout<<ch2;
    gotoxy(x2, y1);
    std::cout<<ch3;
    gotoxy(x2, y2);
    std::cout<<ch4;
    hr(x1, x2, y1, l1);
    hr(x1, x2, y2, l1);
    vr(x1, y1, y2, l2);
    vr(x2, y1, y2, l2);
}

void mygraphics::hr(int x1, int x2, int y, char c){
    for(int i=x1+1; i<x2; i++){
        gotoxy(i, y);
        std::cout<<c;
    }
}

void mygraphics::vr(int x1, int y1, int y2, char c){
    for(int i=y1+1; i<y2; i++){
        gotoxy(x1, i);
        std::cout<<c;
    }
}
