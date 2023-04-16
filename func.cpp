#include"header.h"

bool checkLoginGV(string a, string b) {
	fstream f;
	string c, d;
	f.open("AccountGV.txt", ios::in);
	if (f.fail())
		return false;
	while (!f.eof()){
		getline(f, c, ',');
		getline(f, d,'\n');
		if (a == c && b == d) {
			f.close();
			return true;
		}
	}
	f.close();
	return false;
}

bool checkLoginSV(string a, string b) {
	fstream f;
	string c, d;
	f.open("AccountSV.txt", ios::in);
	if (f.fail())
		return false;
	while (!f.eof()) {
		getline(f, c, ',');
		getline(f, d, '\n');
		if (a == c && b == d) {
			f.close();
			return true;
		}
	}
	f.close();
	return false;
}

void changePass(string a, string c, AccountList& accountlist) {
	fstream f;
	f.open(c,ios::out);
	if (f.fail())
		return;
	Account* t = accountlist.Head;
	while (a != t->user) {
		t = t->pnext;
	}
	if (t == NULL)
		return;
	cout << "Nhap mat khau moi: ";
	cin >> t->pass;
	for (Account* temp = accountlist.Head; temp!=NULL; temp = temp->pnext) {
		f << temp->user << "," << temp->pass << endl;
	}
	cout << "Thay doi thanh cong" << endl;
	f.close();
}


void InitAccountListGV(AccountList& accountlistGV) {
	accountlistGV.Head = accountlistGV.Tail = NULL;
}

void InitAccountListSV(AccountList& accountlistSV) {
	accountlistSV.Head = accountlistSV.Tail = NULL;
}

Account* CreateAccount(string a, string b) {
	Account* newAccount = new Account;
	newAccount->user = a;
	newAccount->pass = b;
	newAccount->pnext = NULL;
	return newAccount;
}

bool checkAccountListGV(AccountList accountlistGV) {
	if (accountlistGV.Head == NULL)
		return true;
	return false;
}

bool checkAccountListSV(AccountList accountlistSV) {
	if (accountlistSV.Head == NULL)
		return true;
	return false;
}

void saveAccountGV(AccountList &accountlistGV) {
	fstream f;
	f.open("AccountGV.txt");
	while (!f.eof()) {
		string a, b;
		getline(f, a, ',');
		getline(f, b, '\n');
		Account* temp = CreateAccount(a, b);
		if (checkAccountListGV(accountlistGV)) {
			accountlistGV.Head = temp;
			accountlistGV.Tail = temp;
		}
		else {
			accountlistGV.Tail->pnext = temp;
			accountlistGV.Tail = temp;
		}
	}
}

void saveAccountSV(AccountList& accountlistSV) {
	fstream f;
	f.open("AccountSV.txt");
	while (!f.eof()) {
		string a, b;
		getline(f, a, ',');
		getline(f, b, '\n');
		Account* temp = CreateAccount(a, b);
		if (checkAccountListGV(accountlistSV)) {
			accountlistSV.Head = temp;
			accountlistSV.Tail = temp;
		}
		else {
			accountlistSV.Tail->pnext = temp;
			accountlistSV.Tail = temp;
		}
	}
}

void login(AccountList& accountlistGV, AccountList& accountlistSV){
	fstream f1, f2;
	f1.open("AccountGV.txt", ios::in | ios::out);
	f2.open("AccountSV.txt", ios::in | ios::out);
	string a, b;
	int t;
	cout << "1. Giao Vien" << endl;
	cout << "2. Sinh Vien" << endl;
	cout << "Ban dang nhap voi tu cach: ";
	cin >> t;
	cout << "Nhap tai khoan: ";
	cin >> a;
	cout << "Nhap mat khau: ";
	cin >> b;
	if (t == 1) {
		if (checkLoginGV(a, b)) {
			cout << "Dang nhap thanh cong" << endl;
			string c = "AccountGV.txt";
			changePass(a,c,accountlistGV);
		}
		else
			cout << "Dang nhap that bai" << endl;
	}
	if (t == 2) {
		if (checkLoginSV(a, b)) {
			cout << "Dang nhap thanh cong" << endl;
			string c = "AccountSV.txt";
			changePass(a,c,accountlistSV);
		}
		else
			cout << "Dang nhap that bai" << endl;
	}
}
