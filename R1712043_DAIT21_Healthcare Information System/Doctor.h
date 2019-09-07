/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Doctor.h
 * Author: Jerry
 *
 * Created on July 28, 2019, 2:59 PM
 */

#ifndef DOCTOR_H
#define DOCTOR_H

using namespace std;

class Doctor {
    int doctorId;
    char dName[40];
    char dGender[10];
    char dPhone[12];
    char dAddress[50];

public:
    Doctor();
    Doctor(int docId, char* docName, char* docGender, char* docPhone, char* docAddress);
    void GetDoctor();
    virtual ~Doctor();
private:

};

#endif /* DOCTOR_H */

