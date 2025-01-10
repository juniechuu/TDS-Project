#include <iostream>
#include "../headers/FileManager.h"
#include "../headers/FruitShop.h"
#include "../headers/Basket.h"
#include "../headers/Main.h"
#include <ctime>
#include <cstdlib>

using namespace std;



int main() {
    FileManager fileManager;
    int choice;
    do {
        displayHomePage("");
        cout << "\n\n";
        cout << "\t MENU\n";
        cout << "\t ______________________________________________\n\n";
        cout << "\t| LOGIN                        | Press 1       |\n";
        cout << "\t| NEW TO LFM? REGISTER NOW!    | Press 2       |\n";
        cout << "\t| FORGOT YOUR PASSWORD?        | Press 3       |\n";
        cout << "\t| RESET YOUR PASSWORD          | Press 4       |\n";
        cout << "\t| EXIT                         | Press 5       |\n";
        cout << "\t ______________________________________________\n";
        cout << "\n\t Press enter your choice       : ";
        cin >> choice;
        cout << endl;
        switch (choice) {
            case 1:
                login(fileManager);
                break;
            case 2:
                registration(fileManager);
                break;
            case 3:
                forgot(fileManager);
                break;
            case 4:
                edit(fileManager);
                break;
            case 5:
                cout << "\t See you next time!\n";
                break;
            default:
                cout << "\t Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
    return 0;
}

// The rest of the function definitions
