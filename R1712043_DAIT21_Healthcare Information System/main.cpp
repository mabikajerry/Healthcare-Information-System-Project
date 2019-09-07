/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jerry
 *
 * Created on June 28, 2019, 4:49 PM
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "Patient.h"
#include "Department.h"
#include "User.h"
#include <cstring>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>

using namespace std;

void AdminMenu();
void NurseMenu();
void SupervisorMenu();

void NewPatient();
void EditPatient();
void ViewPatient();
void DeletePatient();
void ViewAllPatients();

void CreateUser();
void DeleteUser();
void EditUser();

void AdminLogin();
void SuperLogin();
void NurseLogin();

void AdminLogin() {
    string pass;
    int uID;
    cout << "Enter User ID: "<<endl;
    cin>>uID;
    cout << endl << "Enter the password: ";
    cin>>pass;
    fstream userObj("user.txt");
    userObj.seekg(0);
   
    string clearance, username, password;
    int userID, ucheck = 1, count = 0;
    while (userObj >> userID >> clearance >> username >> password) {
        if (userID == ucheck && password == pass) {
            AdminMenu();
            count++;
            break;
        }
    }

    userObj.close();
    
    if (count == 0) {
        cout << "\nNo matching user found!" << endl;
        exit(0);
    }
}

void SuperLogin() {
    string pass;
    int uID;
    cout << "Enter User ID: "<<endl;
    cin>>uID;
    cout << endl << "Enter the password: ";
    cin>>pass;
    fstream userObj("user.txt");
    userObj.seekg(0);
   
    string clearance, username, password;
    int userID, ucheck = 2, count = 0;
    while (userObj >> userID >> clearance >> username >> password) {
        if (userID == ucheck && password == pass) {
            SupervisorMenu();
            count++;
            break;
        }
    }

    userObj.close();
    
    if (count == 0) {
        cout << "\nNo matching user found!" << endl;
        exit(0);
    }
}

void NurseLogin() {
    string pass;
    int uID;
    cout << "Enter User ID: "<<endl;
    cin>>uID;
    cout << endl << "Enter the password: ";
    cin>>pass;
    fstream userObj("user.txt");
    userObj.seekg(0);
   
    string clearance, username, password;
    int userID, ucheck = 3, count = 0;
    while (userObj >> userID >> clearance >> username >> password) {
        if (userID == ucheck && password == pass) {
            NurseMenu();
            count++;
            break;
        }
    }

    userObj.close();
    
    if (count == 0) {
        cout << "\nNo matching user found!" << endl;
        exit(0);
    }
}

//the Main Menu function

int MainMenu() {

    int choice2;
    cout << "                             " << "CENTURION HOSPITAL" << endl;
    cout << right << setw(80) << setfill('-') << "----------" << endl;
    cout << "                                 " << "MAIN MENU" << endl;
    cout << "                                 " << "---------" << endl << endl;
    cout << "			" << "1. Administrator's Menu" << endl;
    cout << "			" << "2. Supervisor's Menu" << endl;
    cout << "			" << "3. Nurse's Menu" << endl;
    cout << "			" << "4. Exit" << endl << endl;
    cout << right << setw(80) << setfill('-') << "----------" << endl;

    cout << "\nEnter the number corresponding to your choice:" << endl;
    cin>>choice2;
    switch (choice2) {
        case 1:
        {
            //Administrator's Menu
            AdminLogin();
            break;
        }

        case 2:
        {
            //Supervisor's Menu
            SuperLogin();
            break;
        }

        case 3:
        {
            //Nurse's Menu
            NurseLogin();
            break;
        }
        case 4:
        {
            //Exit
            exit(0);
            break;
        }
    }

}


// Admin Menu function

void AdminMenu() {
    int choice_adm;
    cout << "                            " << "CENTURION HOSPITAL" << endl;
    cout << right << setw(80) << setfill('-') << "----------" << endl;
    cout << "                            " << "ADMINISTRATOR'S MENU" << endl << endl;
    cout << "			" << "1. Create New User" << endl;
    cout << "			" << "2. Edit User" << endl;
    cout << "			" << "3. Delete User" << endl;
    cout << "			" << "4. Exit" << endl;   
    cout << right << setw(80) << setfill('-') << "----------" << endl;

    cout << right << setw(60) << setfill(' ') << "\nEnter the number corresponding to your choice:" << endl << endl;
    cin>>choice_adm;
    system("cls");
    switch (choice_adm) {
        case 1:
        {
            //Create User()
            CreateUser();
            break;
        }

        case 2:
        {
            //Edit User()
            User u;
            EditUser(u);
            break;
        }
        case 3:
        {
            //Delete User()
            DeleteUser();
            break;
        }

        case 4:
        {
            //Exit	
            exit(0);
            break;
        }
    }
}

//the Nurse Menu function

void NurseMenu() {
    int choice_nur;
    cout << "                            " << "CENTURION HOSPITAL" << endl;
    cout << right << setw(80) << setfill('-') << "----------" << endl;
    cout << "                            " << "NURSE'S MENU" << endl << endl;
    cout << "			" << "1. Add New Patient" << endl;
    cout << "			" << "2. View Patient" << endl;
    cout << "			" << "3. Exit" << endl;
    cout << right << setw(80) << setfill('-') << "----------" << endl;

    cout << right << setw(60) << setfill(' ') << "\nEnter the number corresponding to your choice:" << endl << endl;
    cin>>choice_nur;
    system("cls");
    switch (choice_nur) {
        case 1:
        {
            //Add a new Patient()
            NewPatient();
            break;
        }

        case 2:
        {
            //View a Patient()
            ViewPatient();
            break;
        }

        case 3:
        {
            //exit	
            exit(0);
            break;
        }
    }
}

void SupervisorMenu() {
    int choice_sup;
    cout << "                             " << "CENTURION HOSPITAL" << endl;
    cout << right << setw(80) << setfill('-') << "----------" << endl;
    cout << "                             " << "SUPERVISOR'S MENU" << endl << endl;
    cout << "			" << "1. Edit Patient" << endl;
    cout << "			" << "2. Delete Patient" << endl;
    cout << "			" << "3. Display All Patients" << endl;
    cout << "			" << "4. Exit" << endl;
    cout << right << setw(80) << setfill('-') << "----------" << endl;

    cout << right << setw(60) << setfill(' ') << "\nEnter the number corresponding to your choice:" << endl << endl;
    cin>>choice_sup;
    system("cls");
    switch (choice_sup) {
        case 1:
        {
            //Edit Patient()  
            Patient p;
            EditPatient(p);
            break;
        }
        case 2:
        {
            //Delete Patient()
            DeletePatient();
            break;
        }
        case 3:
        {
            //View All Patients()
            ViewAllPatients();
            break;
        }
        case 4:
        {
            //exit	
            exit(0);
            break;
        }
    }
}

//the main function

int main() {
    MainMenu();

    return 0;
}