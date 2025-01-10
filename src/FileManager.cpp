#include "../headers/FileManager.h"
#include <fstream>
#include <iostream>

void FileManager::addUser(const User &newUser) {
    std::ofstream output(filename, std::ios::app);
    if (!output.is_open()) {
        std::cout << "\t Error opening file for writing: " << filename << std::endl;
        return;
    }
    output << newUser << std::endl;
    output.close();
}

void FileManager::viewUsers() {
    std::ifstream input(filename);
    if (!input.is_open()) {
        std::cout << "\t Error opening file for reading: " << filename << std::endl;
        return;
    }
    std::string id, pass;
    while (input >> id >> pass) {
        std::cout << "\t Username: " << id << std::endl;
        std::cout << "\t Password: " << pass << std::endl << std::endl;
    }
    input.close();
}

const User* FileManager::searchUser(const std::string &userId) {
    std::ifstream input(filename);
    if (!input.is_open()) {
        std::cout << "Error opening file for reading: " << filename << std::endl;
        return nullptr;
    }
    std::string id, pass;
    while (input >> id >> pass) {
        if (id == userId) {
            input.close();
            return new User(id, pass);
        }
    }
    input.close();
    return nullptr;
}

bool FileManager::editUser(const std::string &userId, const std::string &newPassword) {
    std::ifstream inputFile(filename);
    std::ofstream tempFile("temp.txt", std::ios::app);
    std::string id, pass;
    bool userFound = false;
    while (inputFile >> id >> pass) {
        if (id == userId) {
            tempFile << id << ' ' << newPassword << std::endl;
            userFound = true;
        } else {
            tempFile << id << ' ' << pass << std::endl;
        }
    }
    inputFile.close();
    tempFile.close();
    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
    return userFound;
}
