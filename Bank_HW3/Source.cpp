#include<iostream>
#include<vector>
#include<string>
using std::string;
using std::vector;

#include"Customer.h"
#include"Account.h"
#include"CurrentAccount.h"
#include"PrivilegeAccount.h"
#include"SavingsAccount.h"
#include"Bank.h"

int main()
{
	vector <Customer> myCustomers;
	Customer Tanya(1, "Tanya", "Gabrovo");
	Customer Simeon(2, "Simeon", "Gabrovo");
	Customer Magdalena(3, "Magdalena", "Cherven bryag");
	Customer Radost(4, "Radost", "Svilengrad");
	Customer Viktoriya(5, "Viktoriya", "Stara Zagora");

	myCustomers.push_back(Tanya);
	myCustomers.push_back(Simeon);
	myCustomers.push_back(Magdalena);
	myCustomers.push_back(Radost);
	myCustomers.push_back(Viktoriya);

	vector<Account*> myAccounts;
	
	CurrentAccount* CurAc1=new CurrentAccount(1234, 1, 2000), 
				   *CurAc2 = new CurrentAccount(1998, 2, 8000),
				   *CurAc3 = new CurrentAccount(5678, 3, 10000);
	PrivilegeAccount* PrivAc1= new PrivilegeAccount(11698, 4, 2000,1000),
					 *PrivAc2 = new PrivilegeAccount(90368, 5, 9000,2000),
		             *PrivAc3 = new PrivilegeAccount(298710, 1, 100000,3000);
	SavingsAccount* SavAc1= new SavingsAccount(12467, 2, 370,20),
		           *SavAc2 = new SavingsAccount(1234567890, 3, 4000,40),
				   *SavAc3 = new SavingsAccount(65748298, 4, 5000,120);//experiment, interest rate should become 0 

	myAccounts.push_back(CurAc1);
	myAccounts.push_back(CurAc2);
	myAccounts.push_back(CurAc3);
	myAccounts.push_back(PrivAc1);
	myAccounts.push_back(PrivAc2);
	myAccounts.push_back(PrivAc3);
	myAccounts.push_back(SavAc1);
	myAccounts.push_back(SavAc2);
	myAccounts.push_back(SavAc3);

	Bank myBank(myCustomers, myAccounts, "TANYA's BANK", "Sofia");

	vector <Customer> otherCust;
	otherCust.push_back(Simeon);
	otherCust.push_back(Magdalena);
	otherCust.push_back(Radost);

	vector<Account*> otherAcc;

	otherAcc.push_back(CurAc2);
	otherAcc.push_back(PrivAc1);
	otherAcc.push_back(SavAc2);

	Bank anotherBank(otherCust, otherAcc, "ANOTHER BANK", "Dreamlandia");

	//testing the operator = 
	anotherBank = myBank;

	anotherBank.display();

	//testing the 'virtual' copy constructor
	Bank onemoreBank(anotherBank);

	onemoreBank.display();

	std::cout << "---------------------" << std::endl;

	//main menu
	int num;
	do
	{
		std::cout << std::endl;
		std::cout << "~ MAIN MENU ~\n";
		std::cout << "1 List customers\n";
		std::cout << "2 Add new customer\n";
		std::cout << "3 Delete customer\n";
		std::cout << "4 List all accounts\n";
		std::cout << "5 List customer accounts\n";
		std::cout << "6 Add new account\n";
		std::cout << "7 Delete account\n";
		std::cout << "8 Withdraw from account\n";
		std::cout << "9 Deposit to account\n";
		std::cout << "10 Transfer\n";
		std::cout << "11 Display info for the bank\n";
		std::cout << "12 Quit\n";

		std::cout << std::endl << "Enter a number from 1 to 12:";
		std::cin >> num;

		if (num == 1)
		{
			myBank.listCustomers();
		}

		else if (num == 2)
		{
			int id;
			string name, address;

			//input the data of the new customer
			std::cout << "Enter the ID of the new customer:";
			std::cin >> id;
			std::cout << "Enter the name of the new customer:";
			std::cin >> name;
			std::cout << "Enter the address of the new customer:";
			std::cin >> address;
			myBank.addCustomer(id,name,address);
		}

		else if (num == 3)
		{
			int id;
			std::cout << "Enter the ID of the customer to delete:";
			std::cin >> id;
			myBank.deleteCustomer(id);
		}

		else if (num == 4)
		{
			myBank.listAccounts();
		}

		else if (num == 5)
		{
			int id;
			std::cout << "Enter the ID of the customer to show his/her accounts:";
			std::cin >> id;
			myBank.listCustomerAccount(id);
		}

		else if (num == 6)
		{
			int type;

			std::cout << "Choose account type:\n";
			std::cout << "Enter 1 for current account\n";
			std::cout << "Enter 2 for savings account\n";
			std::cout << "Enter 3 for privilege account\n";

			std::cin >> type;

			if (type< 1 && type>3) 
			{ 
				std::cout << "Error! No such an option.\n";  
			}
			else
			{
				long iban, amount;
				int id;

				std::cout << "Enter IBAN:";
				std::cin >> iban;
				std::cout << "Enter customer's ID:";
				std::cin >> id;
				std::cout << "Enter amount of money:";
				std::cin >> amount;
			
				switch (type)
				{
				case 1:
					myBank.addAccount(Current, iban, id, amount);
					break;
				case 2:
					myBank.addAccount(Savings, iban, id, amount);
					break;
				case 3:
					myBank.addAccount(Privilege, iban, id, amount);
					break;
				}
			}
		}

		else if (num == 7)
		{
			long iban;
			std::cout << "Enter the IBAN of the account to delete:";
			std::cin >> iban;

			myBank.deleteAccount(iban);
		}

		else if (num == 8)
		{
			long iban, money;
			std::cout << "Enter the IBAN of the account you would like to withdraw from:";
			std::cin >> iban;
			std::cout << "Enter the amount the money you want to withdraw:";
			std::cin >> money;

			myBank.withdraw(iban, money);
		}

		else if (num == 9)
		{
			long iban, money;
			std::cout << "Enter the IBAN of the account you would like to deposit in:";
			std::cin >> iban;
			std::cout << "Enter the amount the money you want to deposit:";
			std::cin >> money;

			myBank.deposit(iban, money);
		}

		else if (num == 10)
		{
			long from,to, money;
			std::cout << "Enter the IBAN of the account you would like to transfer from:";
			std::cin >> from;
			std::cout << "Enter the IBAN of the account you would like to transfer to:";
			std::cin >> to;
			std::cout << "Enter the amount the money you want to transfer:";
			std::cin >> money;

			myBank.transfer(from, to, money);
		}

		else if (num == 11)
		{
			myBank.display();
		}

		else if (num == 12)
		{
			break;//exits the do while loop 
		}

		else//if the number is not in the main menu
		{
			std::cout << "Invalid number!" << std::endl;
		}

	} while (true);// it will stop looping when 12 is entered

	return 0;
}