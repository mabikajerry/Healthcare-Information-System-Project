/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Patient.cpp
 * Author: Jerry
 * 
 * Created on June 28, 2019, 5:13 PM
 */

#include "Patient.h"
#include <iostream>
#include <fstream>
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

Patient::Patient() {
}

Patient::Patient(int pId, string name, string sname, string pOccu, string pCity, string disease, string admission, string discharge, long double phone, long double charge) {
    p_ID = pId;
    fname = name;
    lname = sname;
    occupation = pOccu;
    p_city = pCity;
    dis = disease;
    addDate = admission;
    relDate = discharge;
    phnumber = phone;
    bill = charge;
}

Patient::~Patient() {
}

string Patient::getDept() {
    string sp;
    cout << "1.CASUALTY" << endl;
    cout << "2.INPATIENT" << endl;
    cout << "3.OUTPATIENT" << endl;
    cout << "4.X-RAY" << endl;
    cout << "5.SURGERY" << endl;
    cout << "6.MARTENITY " << endl << endl;
    int s;
    cin>>s;
    switch (s) {

        case 1:
        {
            sp = "CASUALTY";
            break;
        }
        case 2:
        {
            sp = "INPATIENCE";
            break;
        }
        case 3:
        {
            sp = "OUTPATIENCE";
            break;
        }
        case 4:
        {
            sp = "X-RAY";
            break;
        }
        case 5:
        {
            sp = "SURGERY";
            break;
        }
        case 6:
        {
            sp = "MARTENITY ";
            break;
        }
        default:
        {
            cout << "\nEnter a valid option." << endl;
        }
    }
    return sp;
}

// function for adding a new patient

void NewPatient() {
    Patient p; //ID,firstname,lastname,age,phnumber,occupation,city,disease,Adate,Rdate,bill,spec
    cout << "Fill up the following details" << endl;
    cout << "ID:" << endl;
    cin >> p.p_ID;
    cout << "First Name:" << endl;
    cin >> p.fname;
    cout << "Last Name:" << endl;
    cin >> p.lname;
    cout << "Age:" << endl;
    cin >> p.p_age;
    cout << "Phone No.:" << endl;
    cin >> p.phnumber;
    cout << "Occupation:" << endl;
    cin >> p.occupation;
    cout << "City:" << endl;
    cin >> p.p_city;
    cout << "Disease/Symptoms:" << endl;
    cin >> p.dis;
    cout << "Admission date  (DD/MM/YYYY):" << endl;
    cin >> p.addDate;
    cout << "Release date  (DD/MM/YYYY):" << endl;
    cin >> p.relDate;
    cout << "Total Bill generated:" << endl;
    cin >> p.bill;
    cout << "Kind of Specialization required:" << endl;
    string dept = p.getDept();
    system("cls");

    fstream patObj;
    patObj.open("patient.txt", ios::app);
    //ID,firstname,lastname,age,phnumber,occupation,city,disease,Adate,Rdate,bill,dept

    patObj.seekp(0, ios::end);
    patObj << p.p_ID << endl << p.fname << endl << p.lname << endl << p.p_age << endl << p.phnumber << endl << p.occupation << endl << p.p_city << endl << p.dis << endl << p.addDate << endl << p.relDate << endl << p.bill << endl << dept << endl;
    patObj.close();

    cout << "\n\t\tNew Patient record created successfully!" << endl << endl << endl;
    cout << "\n\n\n\nEnter 1 to return to Menu\nEnter 2 to Exit." << endl;
    int c;
    cin>>c;
    if (c == 1) {
        system("cls");
        NurseMenu(); //backtoPatientMenu
    } else
        exit(0);
}

//Function for editing a patient 

void EditPatient(Patient &pat) {
    int x;
    cout << "\nEnter the ID of the Patient whose record you want to Edit:" << endl;
    cin>>x;
    fstream patObj("patient.txt");
    patObj.seekg(0);
    //ID,firstname,lastname,age,phnumber,occupation,city,disease,Adate,Rdate,bill,dept
    string fname, lname, occupation, p_city, dis, addDate, relDate, dept;
    int p_age, p_ID, count = 0;
    long double phnumber, bill;
    while (patObj >> p_ID >> fname >> lname >> p_age >> phnumber >> occupation >> p_city >> dis >> addDate >> relDate >> bill >> dept) {
        if (p_ID == x) {
            cout << "1.ID:" << p_ID << endl << "2.First Name:" << fname << endl << "3.Last Name:" << lname << endl << "4.Age" << p_age << endl << "5.Phone No.:" << phnumber << endl << "6.Occupation:" << occupation << endl << "7.City:" << p_city << endl << "8.Disease/Symptoms:" << dis << endl << "9.Admission date(DD/MM/YYYY):" << addDate << endl << "10.Release date(DD/MM/YYYY):" << relDate << endl << "11.Total Bill generated:" << bill << endl << "12.Kind of Specialization required:" << dept << endl;
            count++;
            break;
        }
    }

    patObj.close();
    if (count == 0) {
        cout << "\nNo matching records found!" << endl;
        exit(0);
    }

    //data transfer begins
    fstream file("patient.txt");
    file.seekg(0, ios::beg);
    file.seekg(0);
    int line;
    ofstream tempObj;
    tempObj.open("copy2.txt");
    tempObj.seekp(0);
    int skip = 0;
    string fname1, lname1, occupation1, p_city1, dis1, addDate1, relDate1, dept1;
    int p_age1;
    long double phnumber1, bill1;
    file.seekg(0);
    file.seekg(0, ios::cur); //setting the pointer to beginning of file

    while (file >> line >> fname1 >> lname1 >> p_age1 >> phnumber1 >> occupation1 >> p_city1 >> dis1 >> addDate1 >> relDate1 >> bill1 >> dept1) {
        if (line != x) {
            tempObj << line << endl << fname1 << endl << lname1 << endl << p_age1 << endl << phnumber1 << endl << occupation1 << endl << p_city1 << endl << dis1 << endl << addDate1 << endl << relDate1 << endl << bill1 << endl << dept1 << endl;
        }
    }

    file.close();
    tempObj.close();
    remove("patient.txt");
    int result;
    char oldname[] = "copy2.txt";
    char newname[] = "patient.txt";
    result = rename(oldname, newname);
    //data transfer ends
    int edit;
    cout << "\nEnter number corresponding to the Field you want to Edit:" << endl << endl;
    cin>>edit; //ID,firstname,lastname,age,phnumber,occupation,city,disease,Adate,Rdate,bill,spec
    switch (edit) {
        case 1:
        {
            cout << "ID" << endl;
            cin>>p_ID;
            break;
        }
        case 2:
        {
            cout << "First Name:" << endl;
            cin>>fname;

            break;
        }
        case 3:
        {
            cout << "Last Name:" << endl;
            cin>>lname;

            break;
        }
        case 4:
        {
            cout << "Age:" << endl;
            cin>>p_age;
            break;
        }
        case 5:
        {
            cout << "Phone No.:" << endl;
            cin>>phnumber;
            break;
        }
        case 6:
        {
            cout << "Occupation:" << endl;
            cin>>occupation;
            break;
        }
        case 7:
        {
            cout << "City:" << endl;
            cin>>p_city;
            break;
        }

        case 8:
        {
            cout << "Disease/Symptoms:" << endl;
            cin>>dis;
            break;
        }
        case 9:
        {
            cout << "Admission date  (DD/MM/YYYY):" << endl;
            cin>>addDate;
            break;
        }
        case 10:
        {
            cout << "Release date  (DD/MM/YYYY):" << endl;
            cin>>relDate;
        }
        case 11:
        {
            cout << "Total Bill generated:" << endl;
            cin>>bill;
            break;
        }
        case 12:
        {
            cout << "Kind of Specialization required:" << endl;
            dept = pat.getDept();
            break;
        }
        default:
        {
            cout << "\nCome on!Enter a valid option." << endl;
            break;
        }
    }

    system("cls");
    cout << right << setw(50) << setfill(' ') << "--Updated Record--" << endl << endl;
    cout << "1.ID:" << p_ID << endl << "2.First Name:" << fname << endl << "3.Last Name:" << lname << endl << "4.Age" << p_age << endl << "5.Phone No.:" << phnumber << endl << "6.Occupation:" << occupation << endl << "7.City:" << p_city << endl << "8.Disease/Symptoms:" << dis << endl << "9.Admission date(DD/MM/YYYY):" << addDate << endl << "10.Release date(DD/MM/YYYY):" << relDate << endl << "11.Total Bill generated:" << bill << endl << "12.Kind of Specialization required:" << dept << endl;

    //updated data transfer
    fstream newObj;
    newObj.open("patient.txt", ios::app);
    newObj.seekp(0, ios::end);
    newObj << p_ID << endl << fname << endl << lname << endl << p_age << endl << phnumber << endl << occupation << endl << p_city << endl << dis << endl << addDate << endl << relDate << endl << bill << endl << dept << endl;
    newObj.close();

    //after completion
    cout << "\n\nEnter 1 to return to Menu\nEnter 2 to Exit." << endl;
    int c;
    cin>>c;
    if (c == 1) {
        system("cls");
        SupervisorMenu();
    } else
        exit(0);

}

//the function for viewing a patient's details

void ViewPatient() {
    int x;
    cout << "\nEnter the ID of the Patient whose record you want to View:" << endl;
    cin>>x;
    fstream patObj("patient.txt");
    patObj.seekg(0);
    string fname, lname, occupation, p_city, dis, addDate, relDate, dept;
    int p_age, p_ID, count = 0;
    long double phnumber, bill;
    while (patObj >> p_ID >> fname >> lname >> p_age >> phnumber >> occupation >> p_city >> dis >> addDate >> relDate >> bill >> dept) {
        if (p_ID == x) {
            cout << "1.ID:" << p_ID << endl << "2.First Name:" << fname << endl << "3.Last Name:" << lname << endl << "4.Age" << p_age << endl << "5.Phone No.:" << phnumber << endl << "6.Occupation:" << occupation << endl << "7.City:" << p_city << endl << "8.Disease/Symptoms:" << dis << endl << "9.Admission date(DD/MM/YYYY):" << addDate << endl << "10.Release date(DD/MM/YYYY):" << relDate << endl << "11.Total Bill generated:" << bill << endl << "12.Kind of Specialization required:" << dept << endl;
            count++;
            break;
        }
    }

    patObj.close();
    if (count == 0) {
        cout << "\nNo matching records found!" << endl;
        exit(0);
    }

    cout << "\n\nEnter 1 to return to Menu\nEnter 2 to Exit." << endl;
    int c;
    cin>>c;
    if (c == 1) {
        system("cls");
        NurseMenu();
    } else
        exit(0);
}

//the Delete Patient function

void DeletePatient() {
    int x;
    cout << "\nEnter the ID of the Patient whose record you want to Delete:" << endl;
    cin>>x;
    fstream patObj("patient.txt");
    patObj.seekg(0);
    //ID,firstname,lastname,age,phnumber,occupation,city,disease,Adate,Rdate,bill,dept
    string fname, lname, occupation, p_city, dis, addDate, relDate, dept;
    int p_age, p_ID, count = 0;
    long double phnumber, bill;
    while (patObj >> p_ID >> fname >> lname >> p_age >> phnumber >> occupation >> p_city >> dis >> addDate >> relDate >> bill >> dept) {
        if (p_ID == x) {
            cout << "1.ID:" << p_ID << endl << "2.First Name:" << fname << endl << "3.Last Name:" << lname << endl << "4.Age" << p_age << endl << "5.Phone No.:" << phnumber << endl << "6.Occupation:" << occupation << endl << "7.City:" << p_city << endl << "8.Disease/Symptoms:" << dis << endl << "9.Admission date(DD/MM/YYYY):" << addDate << endl << "10.Release date(DD/MM/YYYY):" << relDate << endl << "11.Total Bill generated:" << bill << endl << "12.Kind of Specialization required:" << dept << endl;
            count++;
            break;
        }
    }

    patObj.close();
    if (count == 0) {
        cout << "\nNo matching records found!" << endl;
        exit(0);
    }
    cout << "Are you sure you want to delete this record?\n1.YES\n2.NO" << endl;
    int n;
    cin>>n;
    if (n == 1) {
        fstream file("patient.txt");
        file.seekg(0, ios::beg);
        file.seekg(0);
        int line;
        ofstream tempObj;
        tempObj.open("copy2.txt");
        tempObj.seekp(0);
        int skip = 0;
        string fname1, lname1, occupation1, p_city1, dis1, addDate1, relDate1, dept1;
        int p_age1;
        long double phnumber1, bill1;
        file.seekg(0);
        file.seekg(0, ios::cur); //setting the pointer to beginning of file

        while (file >> line >> fname1 >> lname1 >> p_age1 >> phnumber1 >> occupation1 >> p_city1 >> dis1 >> addDate1 >> relDate1 >> bill1 >> dept1) {
            if (line != x) {
                tempObj << line << endl << fname1 << endl << lname1 << endl << p_age1 << endl << phnumber1 << endl << occupation1 << endl << p_city1 << endl << dis1 << endl << addDate1 << endl << relDate1 << endl << bill1 << endl << dept1 << endl;
            }
        }

        file.close();
        tempObj.close();
        remove("patient.txt");
        int result;
        char oldname[] = "copy2.txt";
        char newname[] = "patient.txt";
        result = rename(oldname, newname);
        system("cls");
        cout << "\n\t\tRecord successfully deleted" << endl;
    }

    cout << "\n\nEnter 1 to return to Menu\nEnter 2 to Exit." << endl;
    int c;
    cin>>c;
    if (c == 1) {
        system("cls");
        SupervisorMenu();
    } else
        exit(0);
}

//the function to View All Patients 

void ViewAllPatients() {
    fstream Obj("patient.txt");
    Obj.seekg(0);
    cout << right << setw(70) << setfill(' ') << "ALL PATIENTS IN THE DATABASE" << endl << endl;
    string fname, lname, occupation, p_city, dis, addDate, relDate, dept;
    int p_age, p_ID, count = 0;
    long double phnumber, bill;
    while (Obj >> p_ID >> fname >> lname >> p_age >> phnumber >> occupation >> p_city >> dis >> addDate >> relDate >> bill >> dept) {
        count++;
        cout << right << setw(50) << setfill(' ') << "Patient Record:" << count << endl;
        cout << "1.ID:" << p_ID << endl << "2.First Name:" << fname << endl << "3.Last Name:" << lname << endl << "4.Age" << p_age << endl << "5.Phone No.:" << phnumber << endl << "6.Occupation:" << occupation << endl << "7.City:" << p_city << endl << "8.Disease/Symptoms:" << dis << endl << "9.Admission date(DD/MM/YYYY):" << addDate << endl << "10.Release date(DD/MM/YYYY):" << relDate << endl << "11.Total Bill generated:" << bill << endl << "12.Kind of Specialization required:" << dept << endl << endl;
    }

    Obj.close();

    if (count == 0) {
        cout << "\nNo matching records found!" << endl;
        exit(0);
    }

    cout << "\n\nEnter 1 to return to Menu\nEnter 2 to Exit." << endl;
    int c;
    cin>>c;
    if (c == 1) {
        system("cls");
        SupervisorMenu();
    } else
        exit(0);
}
