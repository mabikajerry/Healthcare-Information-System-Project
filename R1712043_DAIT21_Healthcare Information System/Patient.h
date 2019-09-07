/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Patient.h
 * Author: Jerry
 *
 * Created on June 28, 2019, 5:13 PM
 */

#ifndef PATIENT_H
#define PATIENT_H

#include <string.h>
//#include <cstring>
#include <string>
#include<stdlib.h>
#include<stdio.h>
#include<iomanip>

using namespace std;

class Patient {
    int p_ID;
    int p_age;
    string fname;
    string lname;
    string occupation;
    string p_city;
    string dis;
    string addDate;
    string relDate;
    long double phnumber;
    long double bill;
public:
    Patient();
    Patient(int pId, string name, string sname, string pOccu, string pCity, string disease, string admission, string discharge, long double phone, long double charge);
    string getDept();
    friend void NewPatient();
    friend void EditPatient(Patient &pat);
    friend void ViewPatient();
    friend void DeletePatient();
    friend void ViewAllPatients();
    friend void NurseMenu();
    virtual ~Patient();
};

#endif /* PATIENT_H */

