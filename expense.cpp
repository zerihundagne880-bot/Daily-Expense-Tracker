#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip> // For better currency formatting

using namespace std;

struct Expense {
    string item;
    float amount;
};

// Function to record a new expense
void addExpense() {
    Expense e;
    ofstream outFile("expenses.txt", ios::app);
    
    cout << "Enter Item/Service Name: ";
    cin.ignore();
    getline(cin, e.item);
    cout << "Enter Amount ($): ";
    cin >> e.amount;
    
    // Saving with a delimiter (|) to handle item names with spaces
    outFile << e.item << "|" << e.amount << endl;
    outFile.close();
    cout << "Expense recorded successfully!\n";
}

// Function to calculate and display the total
void showTotal() {
    ifstream inFile("expenses.txt");
    string line;
    float total = 0;

    if (!inFile) {
        cout << "\nNo expenses found yet.\n";
        return;
    }

    cout << "\n--- Expense Summary ---\n";
    cout << left << setw(20) << "Item" << "Amount" << endl;
    cout << "---------------------------------" << endl;

    string itemName;
    string amountStr;
    
    // Reading line by line and splitting by the delimiter
    while (getline(inFile, line)) {
        size_t pos = line.find('|');
        if (pos != string::npos) {
            itemName = line.substr(0, pos);
            amountStr = line.substr(pos + 1);
            float amount = stof(amountStr);
            
            cout << left << setw(20) << itemName << "$" << fixed << setprecision(2) << amount << endl;
            total += amount;
        }
    }

    cout << "---------------------------------" << endl;
    cout << "TOTAL EXPENSES: $" << fixed << setprecision(2) << total << endl;
    inFile.close();
}

int main() {
    int choice;
    while (true) {
        cout << "\n--- Personal Expense Tracker ---";
        cout << "\n1. Add New Expense";
        cout << "\n2. View Total Summary";
        cout << "\n3. Exit";
        cout << "\nYour Choice: ";
        cin >> choice;

        if (choice == 1) {
            addExpense();
        } else if (choice == 2) {
            showTotal();
        } else if (choice == 3) {
            cout << "Closing program. Goodbye!\n";
            break;
        } else {
            cout << "Invalid selection. Please try again.\n";
        }
    }
    return 0;
}
