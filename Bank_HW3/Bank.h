#pragma once
#include"Customer.h"
#include"Account.h"
#include<string>
#include<vector>
using std::string;
using std::vector;

//determines the type of account wanted
enum accountType
{
	Current,
	Savings,
	Privilege
};

class Bank
{
private:
	string name;
	string address;
	vector<Customer> customers;
	vector<Account*> accounts;//abstract class Account which cannot be instantiate, so we make a ponter vector

	int findCustomer(int id);
	int findAccount(long iban);

public:
	
	//big 4 and Clone funcion 
	Bank(const vector<Customer>customers, const vector<Account*> accounts, const string name = "", const string address = "");
	void Clone(const vector<Account*> &A);
	Bank(const Bank& B);
	Bank& operator=(const Bank& B);
	virtual ~Bank();

	string getName() const;
	string getAddress() const;
	void addCustomer(const int customerId, const string name, const string address);
	void listCustomers() const;
	void deleteCustomer(const int customerId);
	void addAccount(accountType accountType, long iban, int ownerId, long amount);
	void deleteAccount(long iban);
	void listAccounts() const;
	void listCustomerAccount(int customerId);
	void transfer(long fromIBAN, long toIBAN, long amount);
	void display()const;
	void withdraw(long iban, long money);
	void deposit(long iban, long money);
};

