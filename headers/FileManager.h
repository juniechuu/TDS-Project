#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "User.h"
#include <string>

class FileManager {
private:
    const std::string filename = "logins.txt";

public:
    void addUser(const User &newUser);
    void viewUsers();
    const User* searchUser(const std::string &userId);
    bool editUser(const std::string &userId, const std::string &newPassword);
};

#endif 
