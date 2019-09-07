/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   User.h
 * Author: Jerry
 *
 * Created on June 28, 2019, 5:11 PM
 */

#ifndef USER_H
#define USER_H

#include <string.h>
#include <string>
#include<stdlib.h>
#include<stdio.h>
#include<iomanip>

using namespace std;

class User {
    int userID;
    string username;
    string password;
    string clearance;
    
public:
    User();
    User(int uID, string uname, string pass, string level);
    friend void CreateUser();
    friend void EditUser(User &user);
    friend void DeleteUser();
    virtual ~User();

};

#endif /* USER_H */

