//BILLS. Program stores client's account requisites and outputs by request.

#include <iostream>
#include <string>

struct Account {
	int Account_Number = 0;
	std::string Full_Name;
	double Balance = 0.0;
};

std::string toUpper(std::string& name) {
	for (char& chr : name) {
		if (chr >= 'a' && chr <= 'z') {
			chr = 'A' + (chr - 'a');
		}
	}
	return name;
}

Account createAccount() {
	Account client_account;
	std::cout << "Enter your Bank Account Number: #";
	std::cin >> client_account.Account_Number;
	std::cout << "Enter your Full Name: ";
	std::string first_name, second_name;
	std::cin >> first_name >> second_name;
	client_account.Full_Name = toUpper(first_name) + ' ' + toUpper(second_name);
	std::cout << "Enter your Balance: $";
	std::cin >> client_account.Balance;
	return client_account;
}

double getBalance() {
	std::cout << "\nEnter your new balance: $";
	double new_balance = 0;
	std::cin >> new_balance;
	return new_balance;
}

void updateBalance(Account& client_account, double new_balance) {
	client_account.Balance = new_balance;
	return;
}

void printAccount(Account& client_account) {
	std::cout << "\nAccount Number:\t#" << client_account.Account_Number << std::endl;
	std::cout << "Account Owner:\t" << client_account.Full_Name << std::endl;
	std::cout << "Account Funds:\t$" << client_account.Balance << std::endl;
	return;
}

int main(int argc, char** argv) {

	Account client_account = createAccount();
	double new_balance = getBalance();
	updateBalance(client_account, new_balance);
	printAccount(client_account);

	return 0;
}