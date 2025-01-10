#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

class User {
private:
    std::string userId;
    std::string password;

public:
    User(const std::string &id, const std::string &pass);
    std::string getUserId() const;
    std::string getPassword() const;
    friend std::ostream& operator<<(std::ostream& os, const User& user);
};

#endif 