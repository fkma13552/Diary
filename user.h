#pragma once
#ifndef USER_H
#define USER_H
#include<string>
using namespace std;
class User {
public:
    User();
private:
    string login;
    string password;
    int id;
};

#endif // USER_H

