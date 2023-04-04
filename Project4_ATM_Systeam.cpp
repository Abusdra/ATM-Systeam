#include <iostream>;
#include<fstream>;
#include<vector>;
#include<iomanip>;
#include<string>;
#include"Bank.h";
#include"ATMB.h";
using namespace std;
using namespace Allb;


void ShowATMScreen();
void LogInScreen();
void GobackToATMScreen() {
	system("pause");
	ShowATMScreen();
}

void ShowQuickWithdraw() {
	cout << "\n==================================================\n";
	cout << "\tQuich Withdraw \n";
	cout << "==================================================\n";
	cout << setw(10) << "[1]" << setw(3) <<right<<"20" << setw(11) << "[2]" << setw(4) << right << "50\n";
	cout << setw(10) << "[3]" << setw(4) << right << "100" << setw(10) << "[4]" << setw(5) << right << "200\n";
	cout << setw(10) << "[5]" << setw(4) << right << "400" << setw(10) << "[6]" << setw(5) << right << "600\n";
	cout << setw(10) << "[7]" << setw(4) << right << "800" << setw(10) << "[8]" << setw(6) << right << "1000\n";
	cout << "==================================================\n";
	PrintBalance();
	QuickWithdraw(ReadQuickWithdraw());
}
void ShowNormalWithdraw() {
	cout << "\n==================================================\n";
	cout << "\tNormal Withdraw \n";
	cout << "==================================================\n";
	PrintBalance();
	NormalWithdraw();
}
void ShowDepositATM() {
	cout << "\n==================================================\n";
	cout << "\tDeposit Screen\n";
	cout << "==================================================\n";
	PrintBalance();
	DepositMoney();
}
void ShowBalance() {
	cout << "\n==================================================\n";
	cout << "\tDeposit Screen\n";
	cout << "==================================================\n";
	PrintBalance();
}
void PerformATMOption(eATMoP Option) {
	switch (Option)
	{
	case eQuickWithdraw: {
		system("cls");
		ShowQuickWithdraw();
		GobackToATMScreen();
		break;
	}
	case eNormalWithdraw: {
		system("cls");
		ShowNormalWithdraw();
		GobackToATMScreen();
		break;
	}
	case enDeposit: {
		system("cls");
		ShowDepositATM();
		GobackToATMScreen();
		break;
	}
	case eShowBalance: {
		system("cls");
		ShowBalance();
		GobackToATMScreen();
		break;

	}
	case eSignOut: {
		LogInScreen();
		break;
	}
	}
}
void ShowATMScreen() {
	system("cls");
	cout << "==================================\n";
	cout << "\tATM Stander Screen \n";
	cout << "==================================\n";
	cout << "\t[1] Quick Withdraw.\n";
	cout << "\t[2] Normal Withdraw.\n";
	cout << "\t[3] Deposit.\n";
	cout << "\t[4] Check Balance.\n";
	cout << "\t[5] Log Out.\n";
	cout << "==================================\n";
	PerformATMOption(ReadATMoption());
}

void ShowLogInScreen() {
	system("cls");
	cout << "\n==============================\n";
	cout << "\tLogInScreen \n";
	cout << "===============================\n";
}
void LogInScreen() {
	bool LoginFaild = false;
	string AccountNumber, PIN;
	do {
		ShowLogInScreen();
		if (LoginFaild) {
			cout << "INvalid Account Number/PIN \n";
		}
		cout << "Inter Account Number :";
		cin >> AccountNumber;
		cout << "Inter PIN :";
		cin >> PIN;
		LoginFaild = !CheckAccountNumberAndPIN(AccountNumber, PIN, CurrentClient);
	} while (LoginFaild);
	ShowATMScreen();
}
int main()
{
	LogInScreen();
}
