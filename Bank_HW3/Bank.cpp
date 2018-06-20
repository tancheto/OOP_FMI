#include <iostream>
#include "Bank.h"
#include"CurrentAccount.h"
#include"SavingsAccount.h"
#include"PrivilegeAccount.h"

//funtion that clones vector A in accounts vector
void Bank::Clone(const vector<Account*> &A)
{
	for (int i=0; i < (int)A.size(); i++)//casting to int
	{
		this->accounts.push_back(A[i]->Clone());
	}
}

Bank::Bank(const vector<Customer> customers, const vector<Account*> accounts, const string name, const string address)
{
	this->name = name;
	this->address = address;
	this->customers = customers;	
	Clone(accounts);
}

Bank::Bank(const Bank& B)
{
		Clone(B.accounts);
		this->name = B.name;
		this->address = B.address;
		this->customers = B.customers;
}

Bank & Bank::operator=(const Bank & B)
{
	if (this != &B)
	{
		vector<Account*>::iterator iter;

		//deleting all the dynamic memory pointers in vector accounts point to
		for (iter = accounts.begin(); iter != accounts.end(); ++iter)
		{
			delete *iter;
		}

		//clearing vector accounts 
		this->accounts.clear();

		Clone(B.accounts);
		this->name = B.name;
		this->address = B.address;
		this->customers = B.customers;
	}

	return *this;
}

Bank::~Bank()
{
	
	vector<Account*>::iterator iter;

	for (iter = accounts.begin(); iter != accounts.end(); ++iter) 
	{
		delete *iter;
	}

	accounts.clear();
	
}

string Bank::getName() const
{
	return this->name;
}

string Bank::getAddress() const
{
	return this->address;
}

//returning the index of the customer in vector customers if ID is found
//and -1 otherwise
int Bank::findCustomer(int id)
{
	for (int i = 0; i < (int)customers.size(); i++)//casting to int
	{
		if (customers[i].getId() == id)
		{
			return i;
		}
	}
	return -1;//error- no such a customer with this ID
}

//returning the index of the account in the vector accounts if IBAN is found
//and -1 otherwise
int Bank::findAccount(long iban)
{
	for (int i = 0; i < (int)accounts.size(); i++)//casting to int
	{
		if (accounts[i]->getIban() == iban)
		{
			return i;
		}
	}
	return -1;//error- no such an account with this IBAN
}

void Bank::addCustomer(const int customerId, const string name, const string address)
{
	int index = -1;
	index=findCustomer(customerId);

	if (index == -1)//if customer with such an ID is not found
	{
		Customer newCustomer(customerId, name, address);
		//making a copy of newCustomer in the vector, 
		//so the scope doesn't matter in that case
		this->customers.push_back(newCustomer);
		std::cout << "Successfully added customer!" << std::endl;
	}
	else
	{
		std::cout << "Error! Customer with this ID already exists!" << std::endl;
	}
}

void Bank::listCustomers() const
{
	for (int i = 0; i < (int)customers.size(); i++)//cast to int
	{
		customers[i].display();
	}
}

void Bank::deleteCustomer(const int customerId)
{
	int index = -1;
	index = findCustomer(customerId);

	if (index == -1)//if customer is nor found
	{
		std::cout << "No customer with such an ID!" << std::endl;
	}
	else
	{
		for (int s = 0; s < (int)accounts.size(); s++)//cast
		{
			if (accounts[s]->getOwnerId() == customerId)
			{
				delete accounts[s];
				accounts.erase(accounts.begin() + s);
				// after erasing an element, next one gets to his place, 
				//so we have to check it too
				s--;// that is why we decrement the iterator index
			}
		}
		customers.erase(customers.begin()+index);		
		std::cout << "Successfully deleted customer!" << std::endl;
	}

}

void Bank::addAccount(accountType accountType, long iban, int ownerId, long amount)
{
	if (findCustomer(ownerId) == -1)//if customer is not found
	{
		std::cout << "Error! No such a customer in the bank!" << std::endl;
	}

	if (findAccount(iban) != -1)//if account with this ID already exists
	{
		std::cout << "Error! Account with this IBAN already exists!" << std::endl;
	}
	
	if(findCustomer(ownerId) != -1 && findAccount(iban) == -1)
	{
		switch (accountType)
		{
		case Current:
		{			
			accounts.push_back(new CurrentAccount(iban, ownerId, amount));//polymorphism
			//pushing a dynamic object in the vector 
			//object will be deleted with the whole vector at the end 
			std::cout << "Successfully added account!" << std::endl;
		}
			break;		
		case Savings:
		{
			int interestRate;
			std::cout << "You chose to add savings account. Please enter interest rate(>0 && <100):";
			std::cin >> interestRate;
			
			accounts.push_back(new SavingsAccount(iban, ownerId, amount, interestRate));//polymorphism
			std::cout << "Successfully added account!" << std::endl;
		}
			break;
		case Privilege:
		{
			int overdraft;
			std::cout << "You chose to add privilege account. Please enter overdraft:";
			std::cin >> overdraft;
			
			accounts.push_back(new PrivilegeAccount(iban, ownerId, amount, overdraft));//polymorphism
			std::cout << "Successfully added account!" << std::endl;
		}
			break;
		default:
			std::cout << "Error! There is no such a type of accounts!" << std::endl;
		}//end of switch
	}//end of the last if
}

void Bank::deleteAccount(long iban)
{
	int index = -1;
	index=findAccount(iban);

	if (index == -1)//account not found
	{
		std::cout << "Error! No such an account with this IBAN!" << std::endl;
	}

	else
	{
		delete accounts[index];
		accounts.erase(accounts.begin() + index);
		std::cout << "Successfully deleted account!" << std::endl;
	}
}

void Bank::listAccounts() const
{
	std::cout << "~ ACCOUNTS ~" << std::endl;
	for (int i = 0; i < (int)accounts.size(); i++)//cast to int
	{
		accounts[i]->display();
	}
}

void Bank::listCustomerAccount(int customerId)
{
	int index = -1;
	index = findCustomer(customerId);

	if (index == -1)//customer not found
	{
		std::cout << "Error! No customer with such an ID!" << std::endl;
	}
	else
	{
		std::cout << "Accounts of customer with ID:" << customerId << std::endl;
		for (int i = 0; i < (int)accounts.size(); i++)//cast to int
		{
			if (accounts[i]->getOwnerId() == customerId)
			{
				accounts[i]->display();
			}
		}
	}
}

void Bank::transfer(long fromIBAN, long toIBAN, long amount)
{
	int fromIndex = -1, toIndex = -1;
	int fromBalance, toBalance;

	if (findAccount(fromIBAN) == -1) { std::cout << "Error! No account to transfer from!"; }
	if (findAccount(toIBAN) == -1) { std::cout << "Error! No account to transfer to!"; }
	
	if (findAccount(fromIBAN) != -1 && findAccount(toIBAN) != -1)
	{
		fromIndex = findAccount(fromIBAN);//index in the vector of the account to transfer from
		toIndex = findAccount(toIBAN);//index in the vector of the account to transfer to
		fromBalance = accounts[fromIndex]->getBalance();//balance of the account to transfer from
		toBalance = accounts[toIndex]->getBalance();//balance of the account to transfer to

		if (fromBalance<amount)
		{
			std::cout << "Error! Account to transfer from hasn't got enough money!";
		}
		else
		{
			accounts[fromIndex]->setAmount(fromBalance - amount);
			accounts[toIndex]->setAmount(toBalance + amount);
			std::cout << "Successful transfer!" << std::endl;
		}
	}
}

void Bank::display() const
{
	std::cout << "~ BANK INFO ~" << std::endl;
	std::cout << "Name:" << getName() << std::endl;
	std::cout << "Address:" << getAddress() << std::endl;
	std::cout << "Number of customers:" << customers.size() << std::endl;
	std::cout << "Number of accounts:" << accounts.size() << std::endl;
}

void Bank::withdraw(long iban, long money)
{
	int index = -1;
	index=findAccount(iban);

	if (index == -1)//account not found
	{
		std::cout << "Error! No account with such an IBAN!" << std::endl;
	}
	else
	{
		if (accounts[index]->withdraw(money))
		{
			std::cout << "Success in withdrawint the money!" << std::endl;
		}
		else
		{
			std::cout << "Failure in withdrawing the money!" << std::endl;
		}
	}
}

void Bank::deposit(long iban, long money)
{
	int index = -1;
	index = findAccount(iban);

	if (index == -1)//account not found
	{
		std::cout << "Error! No account with such an IBAN!" << std::endl;
	}
	else
	{
		accounts[index]->deposit(money);
	}
}
