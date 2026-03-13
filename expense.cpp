#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Expense {
    string item;
    float amount;
};

void addExpense() {
    Expense e;
    ofstream outFile("expenses.txt", ios::app);
    cout << "የእቃው/አገልግሎቱ ስም: ";
    cin.ignore();
    getline(cin, e.item);
    cout << "ዋጋ (በብር): ";
    cin >> e.amount;
    
    outFile << e.item << " " << e.amount << endl;
    outFile.close();
    cout << "ተመዝግቧል!\n";
}

void showTotal() {
    ifstream inFile("expenses.txt");
    string item;
    float amount, total = 0;
    cout << "\n--- የዝርዝር መግለጫ ---\n";
    while (inFile >> item >> amount) {
        cout << item << " : " << amount << " ብር" << endl;
        total += amount;
    }
    cout << "--------------------\n";
    cout << "ጠቅላላ ወጪ: " << total << " ብር\n";
    inFile.close();
}

int main() {
    int choice;
    while (true) {
        cout << "\n1. ወጪ መመዝገብ\n2. ጠቅላላ ወጪ ማየት\n3. ዝጋ\nምርጫዎ: ";
        cin >> choice;
        if (choice == 1) addExpense();
        else if (choice == 2) showTotal();
        else if (choice == 3) break;
    }
    return 0;
}
