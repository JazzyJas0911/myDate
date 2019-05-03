//
//  myDate.hpp
//  CECS282_Program2
//
//  Created by Jasmin Agustin on 2/13/17.
//  Copyright © 2017 Jasmin Agustin. All rights reserved.
//

#ifndef myDate_hpp
#define myDate_hpp
#include <string>
using namespace std;

int Greg2Julian(int M, int D, int Y);
void Julian2Greg(int JD, int & M, int & D, int & Y);

class myDate{
    
private:
    int month;
    int day;
    int year;

public:
    myDate();
    myDate(int M, int D, int Y);
    void display();
    void incrDate(int N);
    void decrDate(int N);
    int daysBetween(myDate D);
    int getMonth();
    int getDay();
    bool isLeapYear();
    int daysInMonth(int M);
    int getYear();
    int dayOfYear();
    string dayOfWeek();
    
};

#endif

