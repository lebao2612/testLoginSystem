#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct Account {
	string user;
	string pass;
	Account* pnext;
};

struct AccountList {
	Account* Head;
	Account* Tail;
};

bool checkLoginGV(string a, string b);
bool checkLoginSV(string a, string b);
void login(AccountList& accountlistGV, AccountList& accountlistSV);
void InitAccountListGV(AccountList& accountlistGV);
void InitAccountListSV(AccountList& accountlistSV);
Account* CreateAccount(string a, string b);
bool checkAccountListGV(AccountList accountlistGV);
bool checkAccountListSV(AccountList accountlistSV);
void saveAccountGV(AccountList& accountlistGV);
void saveAccountSV(AccountList& accountlistSV);
void changePass(string a,string c, AccountList& accountlist);