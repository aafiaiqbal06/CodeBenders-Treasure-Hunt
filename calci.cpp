#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// Function to display menu
void displayMenu() {
    cout << "\n=====================================" << endl;
    cout << "        SIMPLE CALCULATOR" << endl;
    cout << "=====================================" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;
    cout << "5. Power (^)" << endl;
    cout << "6. Square Root (√)" << endl;
    cout << "7. Percentage (%)" << endl;
    cout << "8. Clear Screen" << endl;
    cout << "9. Exit" << endl;
    cout << "=====================================" << endl;
    cout << "Enter your choice (1-9): ";
}

// Function to get valid number input
double getNumber(string prompt) {
    double num;
    cout << prompt;
    while (!(cin >> num)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a number: ";
    }
    return num;
}

// Function to perform calculation based on choice
void performCalculation(int choice) {
    double num1, num2, result;
    
    switch(choice) {
        case 1: // Addition
            cout << "\n--- ADDITION ---" << endl;
            num1 = getNumber("Enter first number: ");
            num2 = getNumber("Enter second number: ");
            result = num1 + num2;
            cout << "\nResult: " << num1 << " + " << num2 << " = " << result << endl;
            break;
            
        case 2: // Subtraction
            cout << "\n--- SUBTRACTION ---" << endl;
            num1 = getNumber("Enter first number: ");
            num2 = getNumber("Enter second number: ");
            result = num1 - num2;
            cout << "\nResult: " << num1 << " - " << num2 << " = " << result << endl;
            break;
            
        case 3: // Multiplication
            cout << "\n--- MULTIPLICATION ---" << endl;
            num1 = getNumber("Enter first number: ");
            num2 = getNumber("Enter second number: ");
            result = num1 * num2;
            cout << "\nResult: " << num1 << " × " << num2 << " = " << result << endl;
            break;
            
        case 4: // Division
            cout << "\n--- DIVISION ---" << endl;
            num1 = getNumber("Enter dividend: ");
            num2 = getNumber("Enter divisor: ");
            
            if (num2 == 0) {
                cout << "\nError: Division by zero is not allowed!" << endl;
            } else {
                result = num1 / num2;
                cout << "\nResult: " << num1 << " ÷ " << num2 << " = " << result << endl;
            }
            break;
            
        case 5: // Power
            cout << "\n--- POWER ---" << endl;
            num1 = getNumber("Enter base number: ");
            num2 = getNumber("Enter exponent: ");
            result = pow(num1, num2);
            cout << "\nResult: " << num1 << " ^ " << num2 << " = " << result << endl;
            break;
            
        case 6: // Square Root
            cout << "\n--- SQUARE ROOT ---" << endl;
            num1 = getNumber("Enter number: ");
            
            if (num1 < 0) {
                cout << "\nError: Cannot calculate square root of negative number!" << endl;
            } else {
                result = sqrt(num1);
                cout << "\nResult: √" << num1 << " = " << result << endl;
            }
            break;
            
        case 7: // Percentage
            cout << "\n--- PERCENTAGE ---" << endl;
            num1 = getNumber("Enter value: ");
            num2 = getNumber("Enter percentage (e.g., 15 for 15%): ");
            result = (num1 * num2) / 100;
            cout << "\nResult: " << num2 << "% of " << num1 << " = " << result << endl;
            break;
            
        case 8: // Clear Screen
            system("clear || cls");
            break;
            
        case 9: // Exit
            cout << "\nThank you for using the calculator. Goodbye!" << endl;
            break;
            
        default:
            cout << "\nInvalid choice! Please try again." << endl;
    }
}

int main() {
    int choice;
    bool running = true;
    
    cout << "Welcome to the Simple Calculator!" << endl;
    
    while (running) {
        displayMenu();
        
        // Get user choice with validation
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number (1-9): ";
        }
        
        if (choice >= 1 && choice <= 9) {
            performCalculation(choice);
            
            if (choice == 9) {
                running = false;
            } else if (choice != 8) { // Don't wait after clear screen
                cout << "\nPress Enter to continue...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
            }
        } else {
            cout << "\nPlease enter a valid choice (1-9)!" << endl;
            cout << "Press Enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
    }
    
    return 0;
}
