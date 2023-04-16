#include"header.h"

int main() {
	fstream f;
	AccountList accountlistGV,accountlistSV;
	InitAccountListGV(accountlistGV);
	InitAccountListSV(accountlistSV);
	saveAccountGV(accountlistGV);
	saveAccountSV(accountlistSV);
	login(accountlistGV,accountlistSV);
	return 0;
}