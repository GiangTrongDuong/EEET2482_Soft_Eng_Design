/*
  RMIT University Vietnam
  Course: EEET2482/COSC2082
  Semester: 2023-2
  Lab Assessment: 1
  Author: Giang Trong Duong
  ID: s3926135
  Compiler used: 8.1.0
  Created  date: 8/5/2023
  Acknowledgement: Previous tutorial exercise
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

class Time{
    private:
    int hour, minute;
    public:

    Time(){
        this->hour = 0;
        this->minute  = 0;
    }

    Time(int hour, int minute){
        if(hour <= 23){
            this->hour = hour;
        } else {
            this->hour = 0;
        }
        this->minute = minute;
    }

    int hours(){
        return this->hour;
    }

    int minutes(){
        return this->minute;
    }

    void toString(){
        cout << setfill('0') << setw(2) << this->hour << ":" << setw(2)<< this->minute;
    }

    friend ostream &operator >> (ostream &output, Time &time);

    Time &operator + (Time &time){
        int Ahour = 0;
        this->minute += time.minute;

        if(this->minute >= 60){
            this->minute -= 60;
            Ahour++;
        }

        this->hour += time.hour + Ahour;
        if(this->hour > 23){
            this->hour -= 23;
        }
    }
};

ostream &operator << (ostream &output, Time &time){
    time.toString();
    return output;
};

int main(){
    //First part
    Time time1(5,23), time2(23,42);
    cout << time1 << " + " << time2 << " = " << time1 + time2 << endl;

    //part D

    ifstream datafile;
    stringstream ss;
    Time timearr[4];
    string Stime, Sminute;
    int iTime, iMinute, maxtime = 0, maxminute = 0;

    datafile.open("data2.dat",std::ios::out);

    for(int i = 0; i < 4; i++){
        ss.clear();
        getline(datafile,Stime);
        ss << Stime;
        ss >> iTime;
        ss.clear();
        getline(datafile,Sminute,'\n');
        ss << Sminute;
        ss >> iMinute;

        timearr[i] = Time(iTime,iMinute);
        cout << timearr[i] << endl;
    }



    for(int i = 0; i < 4; i++){
        for(int y = 1; y < 4; y++){
            if(timearr[i].hours() < timearr[y].hours()){
                maxtime = y;
                
            } else if (timearr[i].hours() == timearr[y].hours()){
                if(timearr[i].minutes() < timearr[y].minutes()){
                    maxtime = y;
                }
            }
        }
    }

    cout << timearr[maxtime];
    datafile.close();
}