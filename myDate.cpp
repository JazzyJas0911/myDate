//
//  myDate.cpp
//  CECS282_Program2
//
//  Created by Jasmin Agustin on 2/13/17.
//  Copyright © 2017 Jasmin Agustin. All rights reserved.
//

#include "myDate.hpp"
#include <iostream>
using namespace std;


int Greg2Julian(int M, int D, int Y){
    int JD, I, J, K;
    
    I = Y;
    J = M;
    K = D;
    
    JD = K-32075+1461*(I+4800+(J-14)/12)/4+367*(J-2-(J-14)/12*12)/12-3*((I+4900+(J-14)/12)/100)/4;
    
    return JD;
}

void Julian2Greg(int JD, int & M, int & D, int & Y){
    int L, N, I, J, K;
    
    L = JD+68569;
    N = 4*L/146097;
    L = L-(146097*N+3)/4;
    I = 4000*(L+1)/1461001;
    L = L-1461*I/4+31;
    J = 80*L/2447;
    K = L-2447*J/80;
    L = J/11;
    J = J+2-12*L;
    I = 100*(N-49)+I+L;
    
    Y = I;
    M = J;
    D = K;
}


myDate:: myDate(){
    month = 5;
    day = 11;
    year = 1959;
}

myDate:: myDate(int M, int D, int Y){
    int tempM = M;
    int tempD = D;
    int tempY = Y;
    if((tempM > 0 && tempM < 13) && (tempD > 0 && tempD <= daysInMonth(tempM)) && (tempY > 0 && tempY < 32768)){
        month = M;
        day = D;
        year = Y;
    }
    else{
        month = 5;
        day = 11;
        year = 1959;
    }
}

bool myDate:: isLeapYear(){
    if(year % 400 == 0)
        return true;
    else if(year % 100 == 0)
        return false;
    else if(year % 4 == 0)
        return true;
    else
        return false;
}

int myDate:: daysInMonth(int M){
    int temp = M;
    int nDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(isLeapYear() == true)
        nDays[2] = 29;
    return nDays[temp];
}

void myDate:: display(){
    string months[13] = {"error", "January", "Feburary", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};
    cout << months[month] << " " << day << ", " << year;
}

void myDate:: incrDate(int N){
    int nDays = N;
    int dateG2J = Greg2Julian(month, day, year);
    int incrementDate = dateG2J + nDays;
    int m, d, y;
    Julian2Greg(incrementDate, m, d, y);
    month = m;
    day = d;
    year = y;
}

void myDate:: decrDate(int N){
    int nDays = N;
    int dateG2J = Greg2Julian(month, day, year);
    int decrementDate = dateG2J - nDays;
    int m, d, y;
    Julian2Greg(decrementDate, m, d, y);
    month = m;
    day = d;
    year = y;
}

int myDate:: daysBetween(myDate D){
    int JD1 = Greg2Julian(D.getMonth(), D.getDay(), D.getYear());//passed in from main
    int JD2 = Greg2Julian(month, day, year);//private variables in class
    int nDaysBetween = JD1 - JD2;
    return nDaysBetween;
}

int myDate:: getMonth(){
    return month;
}

int myDate:: getDay(){
    return day;
}

int myDate:: getYear(){
    return year;
}

int myDate:: dayOfYear(){
    int firstDay = Greg2Julian(1, 1, year);
    int newDay = Greg2Julian(month, day, year);
    int dayOfYear = newDay - firstDay + 1;
    return dayOfYear;
}

string myDate:: dayOfWeek(){
    string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int dateG2J = Greg2Julian(month, day, year);
    int weekday = dateG2J % 7;
    return days[weekday];
}
