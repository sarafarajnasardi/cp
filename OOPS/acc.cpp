#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Account {
protected:
    int account_number;
    string account_holder;
    double balance;

public:
    Account() : account_number(0), balance(0.0) {}

    Account(int acc_num, string holder, double initial_balance) 
        : account_number(acc_num), account_holder(holder), balance(initial_balance) {}

    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (balance >= amount)
            balance -= amount;
        else
            cout << "Insufficient funds!" << endl;
    }

    virtual void displayDetails() const {
        cout << "Account Number: " << account_number << endl;
        cout << "Account Holder: " << account_holder << endl;
        cout << "Balance: " << balance << endl;
    }

    friend void compare(Account& a, Account& b);
    
    virtual ~Account() {}
};

void compare(Account& a, Account& b) {
    if (a.balance > b.balance)
        cout << a.account_holder << " has more balance than " << b.account_holder << endl;
    else if (a.balance < b.balance)
        cout << b.account_holder << " has more balance than " << a.account_holder << endl;
    else
        cout << "Both accounts have the same balance." << endl;
}

class SavingsAccount : public Account {
private:
    double interest_rate;

public:
    SavingsAccount(int acc_num, string holder, double initial_balance, double rate)
        : Account(acc_num, holder, initial_balance), interest_rate(rate) {}

    void applyInterest() {
        balance += balance * (interest_rate / 100);
    }

    void displayDetails() const override {
        Account::displayDetails();
        cout << "Interest Rate: " << interest_rate << "%" << endl;
    }

    ~SavingsAccount() {}
};

class CheckingAccount : public Account {
private:
    double overdraft_limit;

public:
    CheckingAccount(int acc_num, string holder, double initial_balance, double limit)
        : Account(acc_num, holder, initial_balance), overdraft_limit(limit) {}

    void withdraw(double amount) override {
        if (balance + overdraft_limit >= amount) {
            balance -= amount;
        } else {
            cout << "Withdrawal exceeds overdraft limit!" << endl;
        }
    }

    void displayDetails() const override {
        Account::displayDetails();
        cout << "Overdraft Limit: " << overdraft_limit << endl;
    }

    ~CheckingAccount() {}
};

// Operator Overloading for easy output of account details
ostream& operator<<(ostream& os, const Account& account) {
    os << "Account Number: " << account.account_number << endl;
    os << "Account Holder: " << account.account_holder << endl;
    os << "Balance: " << account.balance << endl;
    return os;
}

// File Handling Functions
void saveAccountsToFile(const Account* accounts[], int count, const string& filename) {
    ofstream fout(filename);
    if (!fout) {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    for (int i = 0; i < count; ++i) {
        fout << accounts[i]->account_number << ","
             << accounts[i]->account_holder << ","
             << accounts[i]->balance << endl;
    }
    fout.close();
    cout << "Accounts saved to file successfully!" << endl;
}

void loadAccountsFromFile(Account* accounts[], int& count, const string& filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "File not found!" << endl;
        return;
    }

    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        int acc_num;
        string holder;
        double balance;
        getline(ss, holder, ',');
        ss >> acc_num >> balance;
        accounts[count++] = new Account(acc_num, holder, balance);
    }
    fin.close();
    cout << "Accounts loaded from file successfully!" << endl;
}

int main() {
    Account* accounts[100];
    int count = 0;

    // Create accounts
    accounts[count++] = new SavingsAccount(1001, "John Doe", 1000.0, 5.0);
    accounts[count++] = new CheckingAccount(1002, "Alice Smith", 500.0, 200.0);

    // Deposit, Withdraw and Apply Interest
    accounts[0]->deposit(500.0);
    accounts[1]->withdraw(100.0);
    dynamic_cast<SavingsAccount*>(accounts[0])->applyInterest();

    // Display details
    for (int i = 0; i < count; ++i) {
        accounts[i]->displayDetails();
    }

    // Compare Accounts
    compare(*accounts[0], *accounts[1]);

    // File handling
    saveAccountsToFile(accounts, count, "accounts.txt");
    loadAccountsFromFile(accounts, count, "accounts.txt");

    // Cleanup dynamically allocated memory
    for (int i = 0; i < count; ++i) {
        delete accounts[i];
    }

    return 0;
}
