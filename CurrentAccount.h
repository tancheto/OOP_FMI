#pragma once
#include "Account.h"
class CurrentAccount:public Account
{
public:

	CurrentAccount(const long iban = 0, const int ownerId = 0, const long amount = 0);
	
	virtual void deposit(long add)override;
	virtual bool withdraw(long money) override;
	virtual void display() const override;

	virtual Account* Clone()const override;
};

