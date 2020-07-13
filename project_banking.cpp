// project banking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<iomanip>
using namespace std;

//Functions' declaration

//1
void add();
//2
void show(int a);
//3
void deposit();
//4
void withdrawal();
//5
void average();
//6
void total();
//7
void remove();
//8
void sortAZ();
//9
void sortZA();
//10
void menu();
//11
void viewSwitch();

//structure for sorting the data of particular one

union data
{
	int account;
	float balance;
	char name[40];
	char family_name[40];
};

union status
{
	int account;
	char available;
};


//global variables' declaration
int i = 0, acc = 10000; //i variable is used for total number of active accounts 
int lastAcc = 10099, flag = 0;
union data obj[100];
union status s[100];


//Main function
int main()
{
	cout << "------------------WELCOME TO THE BANKING WORLD-----------------\n               **********************************\n";
	
	for (int loo = 0; loo < 100; loo++)
	{
		s[loo].account = 10000 + loo;
		s[loo].available = 'Y';
		i++;
	}
	menu();

}

//Definition
//for 10
void menu()
{
	int op;

	//clrscr();
	do
	{
		cout << "\t\t\t Welcome To Bank Management System \n";
		cout << "1. Add new account.\n2. View Detail of Account.\n3. Average amount value of accounts.\n";
		cout << "4. Total amount value of accounts.\n5. Remove an account.\n6. Deposit.\n7. Withdrawal.\n8. Exit\n";
		cin >> op;
		switch (op)
		{
		case 1:
			//clrscr();
			add();
			menu();
			break;
		case 2:
			//clrscr();
			viewSwitch();
			break;
		case 3:
			//clrscr();
			average();
			menu();
			break;
		case 4:
			//clrscr();
			total();
			menu();
			break;
		case 5:
			//clrscr();
			remove();
			menu();
			break;
		case 6:
			//clrscr();
			deposit();
			menu();
			break;
		case 7:
			//clrscr();
			withdrawal();
			menu();
			break;
		case 8:
			break;
		default:
			cout << "Please Enter Available Option.";

			menu();
		}
		cin.ignore();
		cin.get();
	} while (op != '8');
	
	


}

//for 11
void viewSwitch()
{
	int op, tempAcc;
	//clrscr();
	cout << "1. Particular One's Detail.\n2. All Accounts Detail Serially.\n3. Name wise sorted Account Detail A to Z.\n4. Name wise sorted Account Detail Z to A.\n";
	cin >> op;
	switch (op)
	{
	case 1:
		//clrscr();
		cout << "Enter Account Number: ";
		cin >> tempAcc;
		if (tempAcc >= 10000 && tempAcc < 10100)
		{
			show(tempAcc);
		}
		else
		{
			cout << "Wrong Account Number.";
		}
		//getch();
		menu();
		break;
	case 2:
		//clrscr();
		for (int c = 10000; c <= c + 3; c++)
		{
			show(c);
		}
		//getch();
		menu();
		break;
	case 3:
		//clrscr();
		sortAZ();
		menu();
		break;
	case 4:
		sortZA();
		menu();
		break;
	default:
		cout << "Enter Valid Option.";
		//getch();
		menu();
		break;
	}

}

//for 1
void add()
{
	int temp;
	char chk;
	cout << "\n\t\t\tList of unreserved account numbers\n";
	for (int loop1 = 10000; loop1 < 10100; loop1++)
	{

		if (s[loop1].available == 'Y')
		{
			cout << s[loop1].account << endl;
			chk = 'y';
		}
	}
	if (chk == 'y')
	{
		cout << "Enter account number: ";
		cin >> temp;
		if (temp >= 10000 && temp < 10100 && s[temp].available == 'Y')
		{
			cout << "Enter first name: ";
			cin >> obj[temp].name;
			cout << "Enter your Family Name: ";
			cin >> obj[temp].family_name;
			obj[temp].balance = 0.00;
			obj[temp].account = temp;
			cout << "\nNew Account of " << obj[temp].name << " " << obj[temp].family_name << " has been created with Account no.: " << obj[temp].account << "\nOpening Balance is $" << obj[temp].balance << "\n";
			i++;
			s[temp].available = 'N';
		}
		else
		{
			cout << "Account Number Not Available.";
		}
	}
	else
	{
		cout << "No Account number is available for creating new account.";
	}
}

//for 2
void show(int n)
{
	int a = n;
	if (s[a].available == 'Y')
	{
		cout << "\nAccount doesn't exist.";
		flag = 1;
	}
	else
	{
		cout << "\n-------------------------------------------------";
		cout << "\nAccount No.: " << obj[a].account;
		cout << "\nName: " << obj[a].name;
		cout << "\nFamily Name: " << obj[a].family_name;
		cout << "\nBalance Available: " << obj[a].balance;
		flag = 0;
	}
}

//for 3
void deposit()
{
	int tempAcc;
	float tempA;
	cout << "Enter Account Number: ";
	cin >> tempAcc;
	if (tempAcc >= 10000 && tempAcc < 10100)
	{
		show(tempAcc);
		if (flag == 0)
		{
			cout << "\nEnter amount to Deposit: $";
			cin >> tempA;
			obj[tempAcc].balance = obj[tempAcc].balance + tempA;
			cout << "Closing amount in account no. " << tempAcc << " is $" << obj[tempAcc].balance << "\n";
		}
	}
	else
	{
		cout << "Wrong Account Number.";
	}
}
//for 4
void withdrawal()
{
	int tempAcc;
	float tempA;
	cout << "Enter Account Number: ";
	cin >> tempAcc;
	if (tempAcc >= 10000 && tempAcc < 10100)
	{
		show(tempAcc);
		if (flag == 0)
		{
			cout << "\nEnter amount to withdrawal: $";
			cin >> tempA;
			obj[tempAcc].balance = obj[tempAcc].balance - tempA;
			cout << "Closing amount in account no. " << tempAcc << " is $" << obj[tempAcc].balance << "\n";
		}
	}
	else
	{
		cout << "Wrong Account Number.";
	}
}

//for 5
void average()
{
	float temp = 0.00;
	for (int loop = 10000; loop < 10100; loop++)
	{
		if (s[loop].available == 'N')
			temp = temp + obj[loop].balance;
	}
	cout << "Total amount available in bank is $" << temp << "/- \n";
}

//for 6
void total()
{
	float temp = 0.00;

	for (int loop = 10000; loop < 10100; loop++)
	{
		if (s[loop].available == 'N')
			temp = temp + obj[loop].balance;
	}
	temp = temp / i;
	cout << "Average amount available in bank is $" << temp << "/- \n";
}

//for 7
void remove()
{
	int tempAcc;
	float tempA;
	char op;
	cout << "Enter Account Number: ";
	cin >> tempAcc;
	if (tempAcc >= 10000 && tempAcc < 10100 && s[tempAcc].available == 'N')
	{
		show(tempAcc);
		cout << "Enter amount to withdrawal: $";
		cin >> tempA;
		obj[tempAcc].balance = obj[tempAcc].balance - tempA;
		cout << "Closing amount in account no. " << tempAcc << " is $" << obj[tempAcc].balance << "\n";
		cout << "Delete this Account? (y/n) ";
		cin >> op;
		if (op == 'y' || op == 'Y')
		{
			s[tempAcc].available = 'Y';
			i--;
			cout << "Account deleted successfully.";
		}
		else if (op == 'n' || op == 'N')
		{
			menu();
		}
		else
		{
			cout << "Wrong Input.";
			remove();
		}
	}
	else
	{
		cout << "Wrong Account Number.";
	}
}

//for 8
void sortAZ()
{
	int tempAcc;
	float tempA;
	char op;
	cout << "Enter Account Number: ";
	cin >> tempAcc;
	if (tempAcc >= 10000 && tempAcc < 10100 && s[tempAcc].available == 'N')
	{
		show(tempAcc);
		cout << "Enter amount to withdrawal: $";
		cin >> tempA;
		obj[tempAcc].balance = obj[tempAcc].balance - tempA;
		cout << "Closing amount in account no. " << tempAcc << " is $" << obj[tempAcc].balance << "\n";
		cout << "Delete this Account? (y/n) ";
		cin >> op;
		if (op == 'y' || op == 'Y')
		{
			s[tempAcc].available = 'Y';
			i--;
			cout << "Account deleted successfully.";
		}
		else if (op == 'n' || op == 'N')
		{
			menu();
		}
		else
		{
			cout << "Wrong Input.";
			remove();
		}
	}
	else
	{
		cout << "Wrong Account Number.";
	}
}

//for 9
void sortZA()
{

}

//for 
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
