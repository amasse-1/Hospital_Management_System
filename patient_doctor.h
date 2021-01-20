#ifndef PATIENT_DOCTOR
#define PATIENT_DOCTOR

#include <string>
#include <vector>
using namespace std;


struct Doctor
{
	string first_name;
	string last_name;
	string depart;

};

struct Date {
	int month;
	int day;
	int year;
};

void print_date(const Date& d) {
	cout << d.month << "/" << d.day << "/" << d.year;
}

struct Patient
{
	string first_name;
	string last_name;
	string address;
	int age;
	Date birth;
	Date admit;
	string diag;
	vector<string> allergies;
	
};


void print_patient(const Patient& p) {
	//print patient information
};

void print_all_patients() {
	//printing all the patients
};

#endif
