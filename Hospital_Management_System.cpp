// Hospital_Management_System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include "patient_doctor.h"
using namespace std;

void Options();

//To get the Patient's Age
int patients_Age(int current_month, int current_year, int birth_month, int birth_year) {

    if (birth_month > current_month) {
        current_year = current_year - 1;
    }

    int calculated_year = current_year - birth_year;

    return calculated_year;
}

//displaying goodbye
void goodbye() {
    
    cout << "\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "\t\t@@                                                                 @@\n";
    cout << "\t\t@@                                                                 @@\n";
    cout << "\t\t@@                                                                 @@\n";
    cout << "\t\t@@                           GOODBYE!                              @@\n";
    cout << "\t\t@@                                                                 @@\n";
    cout << "\t\t@@                                                                 @@\n";
    cout << "\t\t@@                                                                 @@\n";
    cout << "\t\t@@                         Logging off ...                         @@\n";
    cout << "\t\t@@                                                                 @@\n";
    cout << "\t\t@@                                                                 @@\n";
    cout << "\t\t@@                                                                 @@\n";
    cout << "\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
}

//Adding Patients into the management system
void add_patient() {

    Patient patient;
    int months_30[4] = { 4,6,9,11 };
    int feb = 2;
    int y;

    cout << "\n---------------------------------------\n";
    cout << "\nPlease Enter today's month, day, and year\n";
    cout << "Today's month: ";
    cin >> patient.admit.month;
    cout << "\n";
    cout << "Today's day: ";
    cin >> patient.admit.day;
    cout << "\n";
    cout << "Today's year: ";
    cin >> patient.admit.year;
    cout << "\n";


    cout << "\n---------------------------------------\n";
    cout << "\nPlease Enter first name of the patient\n";
    cout << "First name: ";
    cin >> patient.first_name;
    cout << "\n";

    cout << "\n---------------------------------------\n";
    cout << "\nPlease Enter last name of the patient\n";
    cout << "Last name: ";
    cin >> patient.last_name;
    cout << "\n";


    cin.ignore(); // to allow the getline() fucntion to get the address information
    cout << "\n---------------------------------------\n";
    cout << "\nPlease enter the address of the patient\n";
    cout << "Address: ";
    getline(cin, patient.address);
    cout << "\n";

    cout << "\n---------------------------------------\n";
    cout << "\nPlease enter the month of birth of the patient\n";
    cout << "Birth Month : ";
    cin >> patient.birth.month;
    cout << "\n";

    cout << "\n---------------------------------------\n";
    cout << "\nPlease enter the day of birth of the patient\n";
    cout << "Birth Day : ";
    cin >> patient.birth.day;

    //if the month is one of them months with 31 days, it will not be able to go over 30 days  
    for (int i = 0; i <= size(months_30); i++) {
        if (patient.birth.month == months_30[i]) {
            if (patient.birth.day > 30 || patient.birth.day <= 0) {
                cout << "\nInvalid Day of Birth, please try again\n";
                cout << "\n---------------------------------------\n";
                cout << "\nPlease enter the day of birth of the patient\n";
                cout << "Birth Day : ";
                cin >> patient.birth.day;
            }

        }
    }
    if (patient.birth.month == feb) {
        if (patient.birth.day > 29 || patient.birth.day <= 0) {
            cout << "\nInvalid Day of Birth, please try again\n";
            cout << "\n---------------------------------------\n";
            cout << "\nPlease enter the day of birth of the patient\n";
            cout << "Birth Day : ";
            cin >> patient.birth.day;
        }
    }
    else if (patient.birth.day > 30 || patient.birth.day <= 0) {
        cout << "\nInvalid Day of Birth, please try again\n";
        cout << "\n---------------------------------------\n";
        cout << "\nPlease enter the day of birth of the patient\n";
        cout << "Birth Day : ";
        cin >> patient.birth.day;
    }
    cout << "\n---------------------------------------\n";
    cout << "\nPlease enter the year of birth of the patient\n";
    cout << "Birth Year : ";
    cin >> patient.birth.year;

    cout << "\n---------------------------------------\n";
    cout << "\nAny Allergies?(yes/no)\n";
    string in;

    cin >> in;
    if (in.find("no")) {
        patient.allergies.push_back("None");
    } //else if 
    

    system("CLS");

    cout << "Patient's Name: " << patient.first_name << " " << patient.last_name << "\n";
    cout << "Patient's Address: " << patient.address << "\n";
    cout << "Patient's Birthday: ";
    print_date(patient.birth);
    cout << "\n";
    int age = patients_Age(patient.admit.month, patient.admit.year, patient.birth.month, patient.birth.year);
    cout << "Patient's Age: " << age;
    cout << "\nPatient Admitted on:"; 
    print_date(patient.admit);
    cout << "\n\nTo continue press 1, or any other number to leave: ";
    cin >> y;
    if (y == 1) {
        system("CLS");
        Options();
    }
    else {
        system("CLS");
        goodbye();
        Sleep(5000);
    }
}

//displaying options
void Options() {

    cout << "\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "\t\t@@                                                                 @@\n";
    cout << "\t\t@@              Please enter the number for your choice:           @@\n";
    cout << "\t\t@@                                                                 @@\n";
    cout << "\t\t@@                     1 >> Add Patient                            @@\n";
    cout << "\t\t@@                                                                 @@\n";
    cout << "\t\t@@                     2 >> Add Diagnosis to Patient               @@\n";
    cout << "\t\t@@                                                                 @@\n";
    cout << "\t\t@@                     3 >> Show Patients                          @@\n";
    cout << "\t\t@@                                                                 @@\n";
    cout << "\t\t@@                     4 >> Doctor's Prescription Portal           @@\n";
    cout << "\t\t@@                                                                 @@\n";
    cout << "\t\t@@                     5 >> Exit Program                           @@\n";
    cout << "\t\t@@                                                                 @@\n";
    cout << "\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

    //entering the user's choice
    int x;
    cout << "Enter your choice: ";
    cin >> x;

    switch (x) {
    case 1:
        system("CLS");
        add_patient();
    case 2:
        system("CLS");
        //Adds Diagnosis to Patient
    case 3:
        system("CLS");
        //Show Patients
    case 4:
        system("CLS");
        //Doctor Prescription Portal
    case 5:
        system("CLS");
        goodbye();
        Sleep(5000);
        break;
    default:
        Options();

    }
}

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
