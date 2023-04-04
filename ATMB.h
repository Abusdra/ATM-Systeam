#pragma once
#include<iostream>
#include<string>
#include<fstream>;
#include"Bank.h";
using namespace std;
using namespace Allb;
enum enQuickWithdraw { e20 = 1, e50 = 2, e100 = 3, e200 = 4, e400 = 5, e600 = 6, e800 = 7, e1000 = 8 };
enum eATMoP { eQuickWithdraw = 1, eNormalWithdraw = 2, enDeposit = 3, eShowBalance = 4,eSignOut=5 };

sclient CurrentClient;
bool FindClientByAccountNumberAndPIN(string AccountNumber, string PIN, sclient& Client) {
	vector<sclient>Vclient = LoadClientFromFile(ClientFileTxt);
	for (sclient c : Vclient) {
		if (c.AccountNumber == AccountNumber && c.PinCode == PIN) {
			Client = c;
			return true;
		}
	}
	return false;
}
bool CheckAccountNumberAndPIN(string AccountNumber, string PIN, sclient& Client) {
	if (FindClientByAccountNumberAndPIN(AccountNumber, PIN, Client))
		return true;

	else
		return false;
}
void PrintBalance() {
	cout << "YourBalance is :";
	cout << CurrentClient.AccountBalance << endl;
}
void SaveChange(sclient CurrebtClient) {
	vector<sclient>Vclient = LoadClientFromFile(ClientFileTxt);
	for (sclient& c : Vclient) {
		if (c.AccountNumber == CurrentClient.AccountNumber)
			c = CurrentClient;
	}
	SaveDataToFile(Vclient);
}
void DrawMoney(int num) {
	char Y;
	cout << "Are You Sure Y|N :";
	cin >> Y;
	if (toupper(Y) != 'Y') {
		return;
	}
	if (num > stoi(CurrentClient.AccountBalance)) {
		cout << "You Dont Have This Money \n";
		return;
	}

	CurrentClient.AccountBalance = to_string(stoi(CurrentClient.AccountBalance) - num);
	SaveChange(CurrentClient);
	PrintBalance();
}

eATMoP ReadATMoption() {
	string Op;
	cout << "Inter From [1]to[4] :";
	cin >> Op;
	return (eATMoP)stoi(Op);
}

/*Quick Withdraw*/
enQuickWithdraw ReadQuickWithdraw() {
	int Wd;
	cout << "Choice What You Withdraw From [1][8] :";
	cin >> Wd;
	return  enQuickWithdraw(Wd);
}
void QuickWithdraw(enQuickWithdraw Withdraw) {
	switch (Withdraw)
	{
	case e20: {
		DrawMoney(20);
		break;
	}
	case e50: {
		DrawMoney(50);
		break;
	}
	case e100: {
		DrawMoney(100);
		break;
	}
	case e200: {
		DrawMoney(200);
		break;
	}
	case e400: {
		DrawMoney(400);
		break;
	}
	case e600: {
		DrawMoney(600);
		break;
	}
	case e800: {
		DrawMoney(800);
		break;
	}
	case e1000: {
		DrawMoney(1000);
		break;
	}
	default:
		break;
	}
}
/*Quick Withdraw*/

/*Normal Withdraw*/
void NormalWithdraw() {
	int Withdraw;
	cout << "Inter Withdraw Cach :";
	cin >> Withdraw;
	while(Withdraw %5 !=0){
		cout << "Inter Number 5v \n";
		cin >> Withdraw;
	}
	DrawMoney(Withdraw);
}
/*Normal Withdraw*/

/*Deposit Money*/
void DepositMoney2(int num) {
	char Y;
	cout << "Are You Sure Y|N :";
	cin >> Y;
	if (toupper(Y) != 'Y') {
		return;
	}
	CurrentClient.AccountBalance = to_string(stoi(CurrentClient.AccountBalance) + num);
	SaveChange(CurrentClient);
	PrintBalance();
}
void DepositMoney() {
	int num;
	cout << "Inter Deposit Money :";
	cin >> num;
	while (num % 5 != 0) {
		cout << "Inter 5v :";
		cin >> num;
	}
	DepositMoney2(num);
}
/*Deposit Money*/
