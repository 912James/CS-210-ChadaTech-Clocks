#include<iostream>
#include<ctime> 
#include<iomanip> 
#pragma warning(disable:4996) // searched google to find this to remove the error warning to run program

using namespace std;

class Clock { //created a main class and included variables
public:
    int hour;
    int minute;
    int seconds;
};

class displayHour_12 :public Clock { // created a class for the 12 hour clock that inherits the variables from my main class clocks
public:
    string period;
    displayHour_12() {
        //The following code allows for the current time to display. found the code on https://www.cplusplus.com/reference/ctime/time/
        time_t now = time(0);
        tm* ltm = localtime(&now);
        hour = ltm->tm_hour;
        minute = ltm->tm_min;
        seconds = ltm->tm_sec;

        if (hour >= 12)  //sets period to AM and PM
        {
            period = "PM";
            hour -= 12;
        }
        else
            period = "AM";

    }

    void add_hour(int h) // function to add an hour with if and else if statements
    {
        hour += h;
        if (hour > 12) {
            hour -= 12;
        }
        else if (hour >= 12) {
            if (period == "AM") {
                period = "PM";
            }
            else if (period == "PM") {
                period = "AM";
            }
        }

    }
    
    void add_minute(int min) // function to add minutes including an if statement
    {
        minute += min;
        if (minute >= 60) {
            int h = minute / 60;
            minute -= 60 * h;
            add_hour(h);
        }
    }
    
    void add_seconds(int sec) { // function to add seconds with an if statement
        seconds += sec;
        if (seconds >= 60) {
            int m = seconds / 60;
            seconds -= 60 * m;
            add_minute(m);
        }
    }
};


class displayHour_24 :public Clock { // created a class for the 24 hour clock that inherits the variables from my main class clocks. very similar to displayHour 12 so copy pasted and made neccessary changes
public:
    int hour;
    int minute;
    int seconds;
    displayHour_24() { // this code is to get the current time in miliatry form from <ctime>
        time_t now = time(0);
        tm* ltm = localtime(&now);
        hour = ltm->tm_hour;
        minute = ltm->tm_min;
        seconds = ltm->tm_sec;
    }
    
    void add_hour(int h) { // this function adds an hour to the miltary clock
        hour += h;
        if (hour >= 24) {
            hour -= 24;
        }
    }
  
    void add_minute(int min) { // this function adds a minute to the miltary clock
        minute += min;
        if (minute >= 60) {
            int h = minute / 60;
            minute -= 60 * h;
            add_hour(h);
        }
    }

    void add_seconds(int sec) { // this function adds a second to the miltary clock
        seconds += sec;
        if (seconds >= 60) {
            int m = seconds / 60;
            seconds -= 60 * m;
            add_minute(m);
        }
    }
};

void timeDisplay(displayHour_12 clock12, displayHour_24 clock24) { // used the included worksheet to create the look of the clocks. this displays both clocks neatly
    cout << "**************************" << "     " << "**************************" << endl;
    cout << "*      12-Hour Clock     *" << "     " << "*       24-Hour Clock    *" << endl;
    cout  <<"*       " << setw(2) << setfill('0') << clock12.hour << ":" << setw(2) << setfill('0') << clock12.minute << ":" << setw(2) <<
        setfill('0') << clock12.seconds << " " << clock12.period;
    cout << "      *     *         ";
    cout  << setw(2) << setfill('0') << clock24.hour << ":" << setw(2) << setfill('0') << clock24.minute << ":" << setw(2) <<
        setfill('0') << clock24.seconds << "       *" << endl;
    cout << "**************************" << "     " << "**************************" << endl;
}

int main() { // our main function that will run our program
    displayHour_12 clock12;
    displayHour_24 clock24;
   
    timeDisplay(clock12, clock24); // this code displays both clocks 
    
    int choice = 0;
    while (choice != 4) { // the menu displays here until our user enters the number 4 to exit the program
        cout << "**************************" << endl;
        cout << "* 1 - Add Hour           *" << endl;
        cout << "* 2 - Add Minute         *" << endl;
        cout << "* 3 - Add Second         *" << endl;
        cout << "* 4 - Exit Program       *" << endl;
        cout << "**************************" << endl;
        cin >> choice;

        switch (choice) { // switch function with 4 cases and default
        case 1: clock12.add_hour(1);
            clock24.add_hour(1);
            break;
        case 2: clock12.add_minute(1);
            clock24.add_minute(1);
            break;
        case 3: clock12.add_seconds(1);
            clock24.add_seconds(1);
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid Selection - Make a selection from 1 through 4" << endl;
        }


        timeDisplay(clock12, clock24); // this displays the clocks after the user selection


    }
}