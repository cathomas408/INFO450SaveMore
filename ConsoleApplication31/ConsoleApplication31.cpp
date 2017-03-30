
// ConsoleApplication31.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class AccountGen
{
protected:
	int ID;
	int Account;
	char ans;
	float Balance = 0;
	float iRate;
	string userName;


public:
	struct gAccount
	{
		char Type[1];
		int Account_Number;
	} gAccount;
public:
	AccountGen() {};
	AccountGen(int i, string n, char t, float b, float r)
	{
		gAccount.Account_Number = i;
		userName = n;
		gAccount.Type[1] = t;
		Balance = b;

		iRate = r;

	}

	virtual void Display() = 0;
	virtual void ShowInfo();
	virtual void CaptureData() {};
	
	virtual void Withdraw();
	virtual void Deposit();

	int Menu();

};
int AccountGen::Menu() {
	char ch;
	cout << "Select an option";
	cin >> ch;
	return ch;
}


class Account : public AccountGen
{
public:
	Account() {};
	Account(int i, string n, char t, float b, float r)
	{}
	void Display();
	void CaptureData();

};
void AccountGen::Deposit()
{
	int actNum;
	double amount;
	cout << "Enter Account Number that you wish to deposit: ";
	cin >> actNum;
	if (actNum == gAccount.Account_Number)
	{
		cout << "Enter Amount you wish to deposit:";
		cin >> amount;
		Balance = Balance + amount;
	}
	else if (actNum != gAccount.Account_Number)
		cout << "No account found under that number. Try again ";

}


void AccountGen::Withdraw()
{
	int actNum;
	float amount;
	float sFee = 2;

	cout << "Enter Account you wish to withdraw from";
	cin >> actNum;
	 
	if (actNum == gAccount.Account_Number)
	{

		cout << "Enter amount you wish to withdraw: ";
		cin >> amount;
		if (gAccount.Type == "S")
		{
			amount = amount + sFee;
		}
		else
		{
			Balance = Balance - (amount);
		}
			
			
			

	}

	else if (actNum != gAccount.Account_Number)
	{
		cout << "No account found, Try Again";
	}
}

void Account::CaptureData()
{
	do {
		cout << "Enter account number:";
		cin >> gAccount.Account_Number;
		cout << "What is your Name:";
		getline(cin, userName);
		cout << endl << "What type of account do you wish to open? (S)avings, (C)hecking, Certificate (D)eposite" << endl;
		cin >> gAccount.Type;
		cout << "Enter the initial balance of the account: ";
		cin >> Balance;
		cout << "Account Created.";
		cout << "Create new account? (Y/N) : ";
		cin >> ans;

		while (ans != 'Y' && ans != 'N')
		{
			cout << "Invalid input. Create new account? (Y/N) : ";
			cin >> ans;
		}
		cout << endl;
	} while (ans != 'N');





}

void Account::Display()
{
	int actNum;
	cout << "Enter account number that you wish to display: ";
	cin >> actNum;
	if (actNum == gAccount.Account_Number)
	{
		cout << "AccountID : " << gAccount.Account_Number << endl;
		cout << "Customer Name: " << userName << endl;
		cout << "Account Type: " << gAccount.Type << endl;
		cout << "Balance:" << Balance << endl;
		if ((gAccount.Type == "S") && (Balance < 10000))
		{
			iRate = 0.01;
		}
		else if ((gAccount.Type == "S") && (Balance >= 10000))
		{
			iRate = 0.02;
		};
		if (gAccount.Type == "C")
		{
			iRate = 0.00;
		}
		cout << "Current Rate:" << endl; std::cout << std::fixed << std::setprecision(2) << iRate << endl;
	}
	else if (actNum != gAccount.Account_Number)
	{
		cout << "No account found under that number. Try Again";
	}

}

void AccountGen::ShowInfo()
{
	cout << "Account details for " << userName << "'s account: " << endl;
	cout << "Account Number: " << gAccount.Account_Number << endl;
	cout << "Account Type (Checking / Savings/CD): " << gAccount.Type << endl;
	cout << "Account Balance:  $" << Balance << endl;
}

int main(int argc, char *argv)
{
	Account ob;
	char ch;

	AccountGen **tlist;
	int count = 100;

	bool isOver = false;

	tlist = new AccountGen*[count];

	do
	{

		cout << "\n\n A. Create Account \n B. Withdraw \n C. Deposit \n D. Show Account Details \n\n Q. Exit Application\n\n";
		ch = ob.Menu();
		switch (ch) {
		case 'A':
		case 'a': ob.CaptureData();
			ob.ShowInfo();

			break;


		case 'B':
		case 'b': ob.Withdraw();
			
			
			break;

		case 'C':
		case 'c': ob.Deposit();
			break;
		case 'D':
		case 'd': ob.Display();
			break;
		case 'Q':
		case'q': ob.ShowInfo();
			exit(1);
			break;

		}

	} while (1);

	for (int i = 0; i < count; i++)
	{
		delete tlist[i];
	}

	return 0;

}
