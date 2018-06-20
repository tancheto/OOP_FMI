#pragma once
#include "Account.h"
class PrivilegeAccount:public Account
{
private:
	long overdraft;
	void setOverdraft(const int overdraft);//only used in this class

public:
	PrivilegeAccount(const long iban = 0, const int ownerId = 0, const long amount = 0,const int overdraft=0);
	int getOverdraft()const;
	virtual void deposit(long add)override;
	virtual bool withdraw(long money) override;
	virtual void display() const override;

	virtual Account*Clone()const override;
};

