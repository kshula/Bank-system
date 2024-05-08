#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a Customer class to represent bank customers
class Customer {
private:
    string name;
    string address;
    string phoneNumber;

public:
    Customer(const string& n, const string& addr, const string& phone)
        : name(n), address(addr), phoneNumber(phone) {}

    const string& getName() const { return name; }
    const string& getAddress() const { return address; }
    const string& getPhoneNumber() const { return phoneNumber; }
};

// Define an Account class to represent bank accounts
class Account {
private:
    int accountNumber;
    Customer owner;
    double balance;

public:
    Account(int accNum, const Customer& cust)
        : accountNumber(accNum), owner(cust), balance(0.0) {}

    int getAccountNumber() const { return accountNumber; }
    const Customer& getOwner() const { return owner; }
    double getBalance() const { return balance; }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited $" << amount << " into account " << accountNumber << endl;
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn $" << amount << " from account " << accountNumber << endl;
            return true;
        } else {
            cout << "Insufficient funds in account " << accountNumber << endl;
            return false;
        }
    }

    bool transfer(Account& toAccount, double amount) {
        if (withdraw(amount)) {
            toAccount.deposit(amount);
            cout << "Transferred $" << amount << " from account " << accountNumber
                 << " to account " << toAccount.getAccountNumber() << endl;
            return true;
        } else {
            cout << "Transfer failed from account " << accountNumber << " to account "
                 << toAccount.getAccountNumber() << endl;
            return false;
        }
    }
};

int main() {
    // Create customers
    Customer customer1("John Doe", "123 Main St", "555-1234");
    Customer customer2("Jane Smith", "456 Oak Ave", "555-5678");

    // Create accounts for customers
    Account account1(1001, customer1);
    Account account2(2002, customer2);

    // Perform transactions
    account1.deposit(1000);
    account1.withdraw(200);
    account1.transfer(account2, 300);

    // Display account information
    cout << "Account " << account1.getAccountNumber() << " balance: $" << account1.getBalance() << endl;
    cout << "Account " << account2.getAccountNumber() << " balance: $" << account2.getBalance() << endl;

    return 0;
}
