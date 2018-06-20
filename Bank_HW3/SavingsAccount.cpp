#include<iostream>
#include "SavingsAccount.h"

void SavingsAccount::setInterestRate(const int interestRate)
{
	if (interestRate < 0 || interestRate>100)// not a valid percentage
	{
		this->interestRate = 0;//by default
	}
	else 
	{
		this->interestRate = interestRate;
	}
}

SavingsAccount::SavingsAccount(const long iban, const int ownerId, const long amount, const int interestRate)
	:Account(iban, ownerId, amount)
{
	setInterestRate(interestRate);
}

int SavingsAccount::getInterestRate() const
{
	return this->interestRate;
}

void SavingsAccount::deposit(long add)
{
	Account::depositBase(add);
}

bool SavingsAccount::withdraw(long money)
{
	return Account::withdrawBase(money);
}

void SavingsAccount::display() const
{
	std::cout << "~ Savings Account ~" << std::endl;
	Account::displayBase();
	std::cout << "Interest rate:" << getInterestRate()<<std::endl;
}

Account * SavingsAccount::Clone() const
{
	return new SavingsAccount(*this);
}
