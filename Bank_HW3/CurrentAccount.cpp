#include<iostream>
#include "CurrentAccount.h"

CurrentAccount::CurrentAccount(const long iban, const int ownerId, const long amount)
	:Account(iban,ownerId,amount)
{
}

void CurrentAccount::deposit(long add)
{
	Account::depositBase(add);//calling function from the base class which is not virtual
}

bool CurrentAccount::withdraw(long money)
{
	return Account::withdrawBase(money);
}

void CurrentAccount::display() const
{

	std::cout << "~ Current account ~" << std::endl;
	Account::displayBase();
}

Account * CurrentAccount::Clone() const
{
	return new CurrentAccount(*this);
}
