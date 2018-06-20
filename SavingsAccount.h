#pragma once
#include "Account.h"
class SavingsAccount:public Account
{
private:
	int interestRate;
	void setInterestRate(const int interestRate);//only used in this class

public:
	SavingsAccount(const long iban = 0, const int ownerId = 0, const long amount = 0, const int interestRate=0);

	int getInterestRate() const;
	virtual void deposit(long add)override;
	virtual bool withdraw(long money) override;
	virtual void display() const override;

	virtual Account*Clone()const override;
};

