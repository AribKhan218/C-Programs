#include <stdio.h>
#define PIN 1234  // Define a fixed PIN for simplicity

// Function to clear the console by printing new lines
void clrscreen() {
    system("cls");  // Clear the screen for Windows
}
void displayMenu() {
    printf("\t\t\t\t*****************************************\n");
    printf("\t\t\t\t*          Falcon's ATM MACHINE         *\n");
    printf("\t\t\t\t*****************************************\n");
    printf("\t\t\t\t*  1. Check Balance                     *\n");
    printf("\t\t\t\t*  2. Deposit Money                     *\n");
    printf("\t\t\t\t*  3. Withdraw Money                    *\n");
    printf("\t\t\t\t*  4. Exit                              *\n");
    printf("\t\t\t\t*****************************************\n");
    printf("\t\t\t\tPlease select an option: ");
}

int login() {
    int enteredPin, attempts = 0;

    printf("\n\n\t\t\t\t\tWelcome to Falcon's ATM Machine...");
	// Allow up to 3 attempts to enter the correct PIN
    while (attempts < 3) {
        printf("\n\n\t\t\t\t\tPlease enter your PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == PIN) {
            return 1; // Successful login
        } else {
            attempts++;
            printf("\n\n\t\t\t\t\tIncorrect PIN. Please try again.\n");
        }
    }
    printf("\n\n\t\t\t\t\tToo many incorrect attempts. Exiting...\n");
    return 0; // Login failed
}

int main() {
    int choice;
    float balance = 1000.0; // Initial balance
    float deposit, withdraw;

    // Perform login
    if (!login()) {
        return 0; // Exit if login failed
    }
    
    while (1) {
        clrscreen(); // Clear console for better UX
        displayMenu(); // Display the menu at the top
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                clrscreen();
                printf("*****************************************\n");
                printf("* Your current balance is: $%.2f       *\n", balance);
                printf("*****************************************\n");
                break;
            case 2:
                clrscreen();
                printf("*****************************************\n");
                printf("* Enter amount to deposit: $");
                scanf("%f", &deposit);
                if (deposit > 0) {
                    balance += deposit;
                    printf("* You have deposited: $%.2f            *\n", deposit);
                } else {
                    printf("* Invalid deposit amount.               *\n");
                }
                printf("*****************************************\n");
                break;
            case 3:
                clrscreen();
                printf("*****************************************\n");
                printf("* Enter amount to withdraw: $");
                scanf("%f", &withdraw);
                if (withdraw > 0 && withdraw <= balance) {
                    balance -= withdraw;
                    printf("* You have withdrawn: $%.2f           *\n", withdraw);
                } else {
                    printf("* Invalid withdraw amount or insufficient funds. *\n");
                }
                printf("*****************************************\n");
                break;
            case 4:
                clrscreen();
                printf("*****************************************\n");
                printf("* Thank you for using the ATM. Goodbye! *\n");
                printf("*****************************************\n");
                return 0;
            default:
                clrscreen();
                printf("*****************************************\n");
                printf("* Invalid option. Please try again.     *\n");
                printf("*****************************************\n");
        }
        
        printf("Press Enter to continue...");
        getchar(); // Clear newline character from input buffer
        getchar(); // Wait for user to press Enter
    }

    return 0;
}
