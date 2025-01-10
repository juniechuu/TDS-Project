#include "../headers/User.h"

User::User(const std::string &id, const std::string &pass) : userId(id), password(pass) {}

std::string User::getUserId() const { return userId; }
std::string User::getPassword() const { return password; }

std::ostream& operator<<(std::ostream& os, const User& user) {
    os << user.getUserId() << ' ' << user.getPassword();
    return os;
}
