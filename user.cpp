#include "user.h"
#include <iostream>
#include <iomanip>
User::User()
{

}
string User::getLogin() const
{
    return login;
}

inline void User::setLogin(const string &value)
{
    login = value;
}

inline string User::getPassword() const
{
    return password;
}

inline void User::setPassword(const string &value)
{
    password = value;
}

inline int User::getId() const
{
    return id;
}

inline void User::setId(int value)
{
    id = value;
}
string User::ToString()
{
    return  "Login " + getLogin() + "\n";
}
void User::Display()
{
    cout<<this->ToString();
}
