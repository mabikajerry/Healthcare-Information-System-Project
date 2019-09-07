/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Users.cpp
 * Author: Jerry
 * 
 * Created on June 28, 2019, 5:11 PM
 */

#include "User.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>

using namespace std;

void AdminMenu();

User::User() {
}


User::User(int uID, string uname, string pass, string level) {
    userID = uID;
    username = uname;
    password = pass;
    clearance = level;
}

User::~User() {
}

// function for adding a new patient

void CreateUser() {
    User u;
    cout << "Fill up the following details" << endl;
    cout << "User ID:" << endl;
    cin >> u.userID;
    cout << "User Clearance:" << endl;
    cin >> u.clearance;
    cout << "Username:" << endl;
    cin >> u.username;
    cout << "Password:" << endl;
    cin >> u.password;
    system("cls");

    fstream userObj;
    userObj.open("user.txt", ios::app);

    userObj.seekp(0, ios::end);
    userObj << u.userID << u.clearance << endl << u.username << endl << u.password << endl;
    userObj.close();

    cout << "\n\t\tNew User created successfully!" << endl << endl << endl;
    cout << "\n\n\n\nEnter 1 to return to Menu\nEnter 2 to Exit." << endl;
    int c;
    cin>>c;
    if (c == 1) {
        system("cls");
        AdminMenu(); //backtoPatientMenu
    } else
        exit(0);
}

void EditUser(User &user) {
    int x;
    cout << "\nEnter the name of the user you want to Edit:" << endl;
    cin>>x;
    fstream userObj("user.txt");
    userObj.seekg(0);
    string clearance, username, password;
    int userID, count = 0;
    while (userObj >> userID >> clearance >> username >> password) {
        if (userID == x) {
            cout << "1.User ID:"<< userID << endl << "2.Clearance:" << clearance << endl << "3.Username:" << username << endl << "4.password:" << password << endl;
            count++;
            break;
        }
    }

    userObj.close();
    if (count == 0) {
        cout << "\nNo matching records found!" << endl;
        exit(0);
    }

    //data transfer begins
    fstream file("user.txt");
    file.seekg(0, ios::beg);
    file.seekg(0);
    int line;
    ofstream tempObj;
    tempObj.open("copy2.txt");
    tempObj.seekp(0);
    int skip = 0;
    int userID1;
    string clearance1, username1, password1;
    file.seekg(0);
    file.seekg(0, ios::cur); //setting the pointer to beginning of file

    while (file >> line >> userID1 >> clearance1 >> username1 >> password1) {
        if (line != x) {
            tempObj << line << endl << userID1 << clearance1 << endl << username1 << endl << password1 << endl;
        }
    }

    file.close();
    tempObj.close();
    remove("user.txt");
    int result;
    char oldname[] = "copy2.txt";
    char newname[] = "user.txt";
    result = rename(oldname, newname);
    //data transfer ends
    int edit;
    cout << "\nEnter number corresponding to the Field you want to Edit:" << endl << endl;
    cin>>edit;
    switch (edit) {
        case 1:
        {
            cout << "User ID:" << endl;
            cin>>userID;
            break;
        }
        case 2:
        {
            cout << "Clearance" << endl;
            cin>>clearance;
            break;
        }
        case 3:
        {
            cout << "Username:" << endl;
            cin>>username;

            break;
        }
        case 4:
        {
            cout << "Password:" << endl;
            cin>>password;

            break;
        }
        default:
        {
            cout << "\nCome on!Enter a valid option." << endl;
            break;
        }
    }

    system("cls");
    cout << right << setw(50) << setfill(' ') << "--User Record--" << endl << endl;
    cout << "1.User ID:" <<userID << "2.Clearance:" << clearance << endl << "3.Username:" << username << endl << "4.Password:" << password << endl;

    //updated data transfer
    fstream newObj;
    newObj.open("user.txt", ios::app);
    newObj.seekp(0, ios::end);
    newObj << userID << clearance << endl << username << endl << password << endl;
    newObj.close();

    //after completion
    cout << "\n\nEnter 1 to return to Menu\nEnter 2 to Exit." << endl;
    int c;
    cin>>c;
    if (c == 1) {
        system("cls");
        AdminMenu();
    } else
        exit(0);

}

void DeleteUser() {
    int x;
    cout << "\nEnter the name of the user you want to Delete:" << endl;
    cin>>x;
    fstream userObj("user.txt");
    userObj.seekg(0);
   
    string clearance, username, password;
    int userID, count = 0;
    while (userObj >> userID >> clearance >> username >> password) {
        if (userID == x) {
            cout << "1.User ID:" << userID << "2.Clearance:" << clearance << endl << "3.Username:" << username << endl << "4.Password:" << password << endl;
            count++;
            break;
        }
    }

    userObj.close();
    
    if (count == 0) {
        cout << "\nNo matching records found!" << endl;
        exit(0);
    }
    cout << "Are you sure you want to delete this user?\n1.YES\n2.NO" << endl;
    int n;
    cin>>n;
    if (n == 1) {
        fstream file("user.txt");
        file.seekg(0, ios::beg);
        file.seekg(0);
        int line;
        ofstream tempObj;
        tempObj.open("copy2.txt");
        tempObj.seekp(0);
        int skip = 0;
        string clearance1, username1, password1;
        int userID1;
        file.seekg(0);
        file.seekg(0, ios::cur); //setting the pointer to beginning of file

        while (file >> line >> userID1 >> clearance1 >> username1 >> password1) {
            if (line != x) {
                tempObj << line << endl << userID1 << clearance1 << endl << username1 << endl << password1 << endl;
            }
        }

        file.close();
        tempObj.close();
        remove("user.txt");
        int result;
        char oldname[] = "copy2.txt";
        char newname[] = "user.txt";
        result = rename(oldname, newname);
        system("cls");
        cout << "\n\t\tUser successfully deleted" << endl;
    }

    cout << "\n\nEnter 1 to return to Menu\nEnter 2 to Exit." << endl;
    int c;
    cin>>c;
    if (c == 1) {
        system("cls");
        AdminMenu();
    } else
        exit(0);
}