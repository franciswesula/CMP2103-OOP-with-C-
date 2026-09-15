// Write a program that outputs an acceptance letter for Makerere University. It should prompt a user to enter their first name, last name, study program, academic year.
// The program should have autodates

// Example:

// Date: 27th August 2026

// To: John Okello,

// Dear John,

// CONGRATULATIONS! I am pleased to inform you that the Makerere University 
// Admissions Board has approved your application for admission to the 
// 2027/2028 academic year.

// You have been offered a place for the following course:
// PROGRAM: Bachelor of Science in Computer and Communication Engineering

// As a student of Makerere University, you will be part of a historic 
// institution dedicated to academic excellence and innovation. Please ensure 
// that you report to the Academic Registrar's office with your original 
// academic documents for verification during the orientation week.

// We look forward to welcoming you to the Makerere University.

// Yours sincerely,


// John Doe
// Registra

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
    string firstName, lastName, program;
    int academicYear;

    
    time_t now = time(0);
    tm *ltm = localtime(&now);

    
    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your last name: ";
    cin >> lastName;
    cout << "Enter your study program: ";
    cin.ignore(); // Clear the newline character from the input buffer
    getline(cin, program);
    cout << "Enter your academic year (e.g., 2027): ";
    cin >> academicYear;

    
    cout << "\nDate: " << ltm->tm_mday << "th " 
         << setw(2) << setfill('0') << ltm->tm_mon + 1 << " "
         << ltm->tm_year + 1900 << endl;

    cout << "\nTo: " << firstName << " " << lastName << ",\n" << endl;

    cout << "Dear " << firstName << ",\n" << endl;

    cout << "CONGRATULATIONS! I am pleased to inform you that the Makerere University "
         << "Admissions Board has approved your application for admission to the "
         << academicYear + 1 << "/" << academicYear + 2 << " academic year.\n" << endl;

    cout << "You have been offered a place for the following course:\n"
         << "PROGRAM: " << program << "\n" << endl;

    cout << "As a student of Makerere University, you will be part of a historic "
         << "institution dedicated to academic excellence and innovation. Please ensure "
         << "that you report to the Academic Registrar's office with your original "
         << "academic documents for verification during the orientation week.\n" << endl;

    cout << "We look forward to welcoming you to the Makerere University.\n" << endl;

    cout << "Yours sincerely,\n\n";
    cout << "John Doe\n"; 
    cout << "Registra\n";

    return 0;
}