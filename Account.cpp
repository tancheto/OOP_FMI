#include<iostream>
#include "Account.h"

void Account::setIban(const long iban)
{
	if (iban <=0) { this->iban = 0; }
	else { this->iban = iban; }
}

void Account::setOwnerId(const int ownerId)
{
	if (ownerId <= 0) { this->ownerId = 0; }
	else { this->ownerId = ownerId; }
}

void Account::setAmount(const long amount)
{
	if (amount <= 0) { this->amount = 0; }
	else { this->amount = amount; }
}

Account::Account(const long iban, const int ownerId, const long amount)
{
	setIban(iban);
	setOwnerId(ownerId);
	setAmount(amount);
}

long Account::getBalance() const
{
	return this->amount;
}

int Account::getOwnerId() const
{
	return this->ownerId;
}

long Account::getIban() const
{
	return this->iban;
}

void Account::depositBase(long add)
{
	if (add > 0)
	{
		this->amount += add;
	}
	else
	{
		std::cout << "You can't deposit negative amount of money!" << std::endl;
	}
}

bool Account::withdrawBase(long money)
{
	if (this->amount >= money)
	{
		this->amount -= money;
		return true;
	}
	return false;
}

void Account::displayBase() const
{
	std::cout << "IBAN:" << this->iban << std::endl;
	std::cout << "Owner's ID:" << this->ownerId << std::endl;
	std::cout << "Balance:" << this->getBalance() << std::endl;
}
