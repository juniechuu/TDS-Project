#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Utility functions
void cls() {
    system("cls");
}

void ccolor(int clr) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
}

void loadingbar(void) {
    for (int i = 15; i <= 100; i += 5) {
        cls();
        printf("\n\n\n\n\n\n\n\t\t\t\t");
        printf("%d %% Loading...\n\n\t\t", i);

        for (int j = 0; j < i; j += 2) {
            ccolor(160 + j);
            printf(" ");
            ccolor(26); // Reset color
        }
        Sleep(100);
        if (i == 90 || i == 50 || i == 96 || i == 83) {
            Sleep(100);
        }
    }
}