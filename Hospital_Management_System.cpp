// Hospital_Management_System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <windows.h>
#include "patient_doctor.h"
using namespace std;


int main()
{

    //printing the welcome menu
    cout << "\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "\t\t@@                                                                 @@\n";
    cout << "\t\t@@                                                                 @@\n";
    cout << "\t\t@@                                                                 @@\n";
    cout << "\t\t@@                           Welcome to the                        @@\n";
    cout << "\t\t@@                    Hospital Management System                   @@\n";
    cout << "\t\t@@                   (Press the 1 key to continue)                 @@\n";
    cout << "\t\t@@                                                                 @@\n";
    cout << "\t\t@@                                                                 @@\n";
    cout << "\t\t@@                                                                 @@\n";
    cout << "\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

    int key;
    cin >> key;


    //if any key is pressed, clear the terminal and then go to the next page. 
    if (key == 1) {
        system("CLS");
        Options();
    }
    else {
        system("CLS");
        goodbye();
        Sleep(5000);
    }
}
