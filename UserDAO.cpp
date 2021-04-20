#include "UserDAO.h"

#include <stdexcept>

UserDAO::UserDAO()
{
    AddUser("user1", "112345");
    AddUser("user2", "212345");
    AddUser("user3", "312345");
    AddUser("user4", "412345");
}
UserDAO::~UserDAO() {

}

User& UserDAO::AddUser(const string& login, const  string& password) {
    User* user = new User();
    user->setLogin(login);
    user->setPassword(password);
    user->setId(nextUserId++);
    users.push_back(*user);
    return *user;
}

vector<User> UserDAO::GetAllUsers() {
    return users;
}

User UserDAO::GetUser(const int& id) {
    for(auto user: users) {
        if(user.getId() == id)
            return user;
    }
    throw logic_error("No user found!");
}
void UserDAO::DisplayAll() const {
    for(auto user: users) {
        user.Display();
    }
}
