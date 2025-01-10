#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <cstdlib>   // For system("cls")
#include <cctype>    // For toupper()
#include <ctime>


#include "../headers/FileManager.h"
#include "../headers/User.h"

using namespace std;


void displayHomePage(const string &username) {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "\t____________________________________________________________\n\n";
    cout << "\t\t\t L      FFFFF    M       M                             \n";
    cout << "\t\t\t L      F        MM     MM                             \n";
    cout << "\t\t\t L      FFFFF    M M   M M                             \n";
    cout << "\t\t\t L      F        M  M M  M                             \n";
    cout << "\t\t\t LLLLL  F        M   M   M                             \n\n";
    cout << "\t____________________________________________________________\n\n";
    cout << "\t                Welcome to Local Fruit Mall                 \n";
    cout << "\t                Today's Date : " << ltm->tm_mday << "/" << 1+ ltm->tm_mon << "/" << 1900 + ltm->tm_year <<"\n";
    cout << "\t____________________________________________________________\n";
}


void shop(FileManager &fileManager, const string &username) {
    FruitShop fruitShop;  // Assuming FruitShop is a defined class with necessary methods
    Basket basket;
    int choice, index, quantity;

    displayHomePage(username);

    do {
         // Ensure this function is defined elsewhere
        cout << "\nMenu:\n";
        cout << "1. Display Available Fruits\n";
        cout << "2. Add Fruit to Basket\n";
        cout << "3. Edit Basket Item\n";
        cout << "4. Delete Basket Item\n";
        cout << "5. Checkout (Display Total)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                displayHomePage(username);
                fruitShop.displayFruits();
                break;

            case 2:
                displayHomePage(username);
                fruitShop.displayFruits();
                cout << "Enter the index of the fruit to add to basket: ";
                cin >> index;
                cout << "Enter the quantity: ";
                cin >> quantity;
                if (index >= 1 && index <= fruitShop.getFruitCount()) {
                    const FruitShop::Fruit &selectedFruit = fruitShop.getFruit(index - 1); // Access the fruit
                    basket.addItem(selectedFruit.name, selectedFruit.price, quantity);
                    cout << "Item added to basket!" << endl;
                } else {
                    cout << "Invalid index!" << endl;
                }
                break;

            case 3:
                displayHomePage(username);
                basket.displayBasket();
                cout << "Enter the index of the item to edit: ";
                cin >> index;
                cout << "Enter the new quantity: ";
                cin >> quantity;
                basket.editItem(index, quantity);
                cout << "Item updated!" << endl;
                break;

            case 4:
                displayHomePage(username);
                basket.displayBasket();
                cout << "Enter the index of the item to delete: ";
                cin >> index;
                basket.deleteItem(index);
                cout << "Item deleted from basket!" << endl;
                break;

            case 5:
                displayHomePage(username);
                cout << "\nCheckout\n";
                basket.displayBasket();
                cout << "Total amount to pay: RM" << basket.getTotal() << endl;
                break;

            case 6:
                cout << "Exiting the shop. Thank you for visiting!" << endl;
                return;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);  // Exit loop when choice is 7
};



void login(FileManager &fileManager) {
    int attempts = 0;
    const int maxAttempts = 3;
    do {
        string userId, password;
        cout << "\t Please enter your USERNAME and PASSWORD. " << endl;
        cout << "\t USERNAME : ";
        cin >> userId;
        cout << "\t PASSWORD : ";
        cin >> password;
        system("cls");
        const User *user = fileManager.searchUser(userId);
        if (user && user->getPassword() == password) {
            system("cls");
            cout << "\n\t Login successful!\n\n";

            // Call the shop function after successful login
            shop(fileManager, userId);  // Passing the username to the shop function

            delete user;
            return;  // Exit after entering the shop
        } else {
            system("cls");
            cout << "\n\t The login attempt was unsuccessful. PLEASE TRY AGAIN\n" << endl;
            attempts++;
        }
        delete user;
    } while (attempts < maxAttempts);

    system("cls");
    cout << "\n\t Maximum login attempts reached. Returning to the main menu.\n" << endl;
}


void registration(FileManager& fileManager) {
    string userId, password;
    cout << "\t Enter new USERNAME (without space): ";
    cin >> userId;
    cout << "\t Enter new PASSWORD: ";
    cin >> password;
    fileManager.addUser(User(userId, password));
    system("cls");
    cout << "\n\t Registration is successful! \n\n\n";
}


void forgot(FileManager& fileManager) {
    int option;
    system("cls");
    cout << "\t Forgot your password? \n";
    cout << "\t ____________________________________________________\n\n";
    cout << "\t| Search your PASSWORD by USERNAME   | Press 1       |" << endl;
    cout << "\t| Main Menu                          | Press 2       |" << endl;
    cout << "\t ____________________________________________________\n\n";
    cout << "\n\t Press enter your choice         : ";
    cin >> option;
    switch (option) {
        case 1: {
            string userId;
            cout << "\n\t Enter the existing USERNAME : ";
            cin >> userId;
            const User* foundUser = fileManager.searchUser(userId);
            if (foundUser != nullptr) {
                cout << "\n\t Thank God! Fpund your account!";
                cout << "\n\t USERNAME : " << foundUser->getUserId() << endl;
                cout << "\t PASSWORD : " << foundUser->getPassword() << endl;
                char choice;
                cout << "\n\t Continue your journey! (C): ";
                cin >> choice;
                if (toupper(choice) == 'C') {
                    system("cls");
                    return;
                }
            } else {
                system("cls");
                cout << "\n\t Sorry! Your account is not found! \n\n";
            }
            delete foundUser;
            break;
        }
        case 2:
            system("cls");
            break;
        default:
            cout << "\n\t Wrong choice! Please try again.\n";
    }
}


void edit(FileManager& fileManager) {
    string userId, newPassword;
    cout << "\t Enter USERNAME for reset: ";
    cin >> userId;
    cout << "\t Enter new PASSWORD: ";
    cin >> newPassword;
    if (fileManager.editUser(userId, newPassword)) {
        system("cls");
        cout << "\n\t Password updated successfully!\n\n";
    } else {
        system("cls");
        cout << "\n\t User not found. Resetting failed.\n\n";
    }
}

#endif
