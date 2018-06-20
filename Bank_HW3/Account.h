#pragma once
class Account
{
protected://derived classes should have visibility to these parameters and methods
	long iban;
	int ownerId;
	long amount;

	void setIban(const long iban);
	void setOwnerId(const int ownerId);
	
	//functions that implement the things that pure virtual functions can't
	void depositBase(long add);
	bool withdrawBase(long money);
	void displayBase()const;

public:
	Account(const long iban=0, const int ownerId=0, const long amount=0);
	
	//pure virtual functions
	virtual void deposit(long add) = 0;
	virtual bool withdraw(long money) = 0;
	virtual void display() const = 0;

	virtual Account* Clone() const = 0;

	long getBalance() const;
	int getOwnerId()const;
	long getIban()const;

	void setAmount(const long amount);//need it in Bank class, so it's public method
	
};

