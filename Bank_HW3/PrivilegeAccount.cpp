#include<iostream>
#include "PrivilegeAccount.h"

void PrivilegeAccount::setOverdraft(const int overdraft)
{
	if (overdraft < 0)//invalid value of overdraft 
	{
		this->overdraft = 0;
	}
	else 
	{
		this->overdraft = overdraft;
	}
}

PrivilegeAccount::PrivilegeAccount(const long iban, const int ownerId, const long amount, const int overdraft)
	:Account(iban, ownerId, amount)
{
	setOverdraft(overdraft);
}

int PrivilegeAccount::getOverdraft() const
{
	return this->overdraft;
}

void PrivilegeAccount::deposit(long add)
{
	Account::depositBase(add);
}

bool PrivilegeAccount::withdraw(long money)//implementation is different from the default in base class
{
	if (getBalance() + getOverdraft() < money)
	{
		return false;
	}
	else
	{
		//setAmount() is not used because it does not get negative numbers
		amount -= money;
		return true;
	}
}

void PrivilegeAccount::display() const
{
	std::cout << "~ Privilege account ~" << std::endl;
	Account::displayBase();
	std::cout << "Overdraft:" << getOverdraft()<<std::endl;
}

Account * PrivilegeAccount::Clone() const
{
	return new PrivilegeAccount(*this);
}
