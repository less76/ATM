// firstVr.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

class ATM {
	private:
		float money;
		int account_size;
		string *account_status;

	public:
		ATM();
		~ATM();
		ATM(const ATM& copy);
		void setmoney(const float newmoney);
		float getmoney() const;
		void setaccount_size(const int newaccountsize);
		int getaccount_size();
		void addEntry(string newEntry);
		void removeEntry(string newEntry);
		string getEntry();

		friend ostream& operator << (ostream& os, const ATM& output);
		friend istream& operator >> (istream& is, ATM& input);

		ATM operator +(const ATM& plus);
		ATM operator +=(const ATM& plus_equal);
		ATM operator -(const ATM& minus);
		int operator !=(const ATM& equal_equal);
};

ostream& operator << (ostream& os, const ATM& output);
istream& operator >> (istream& is, ATM& input);

void ATM::removeEntry(string newEntry) {

	int found = 0;
	string *new_array = new string[getaccount_size()];

	for (int i = 0; i < getaccount_size() - 1; i++) {
		*new_array = *account_status++;

		if (*new_array == newEntry) {
			*new_array = *account_status++;
			found = 1;
		}

		new_array++;
	}

	if (found == 0) {
		cout << "Can not find string in list" << endl;
		
		account_status -= getaccount_size() - 1;

		for (int i = 0; i < getaccount_size() - 1; i++) {
			cout << *account_status++ << endl;
		}

		cout << *account_status << endl;

		account_status -= getaccount_size() - 1;

	}

	else {
		new_array -= getaccount_size() - 1;

		account_status = new_array;

		for (int i = 0; i < getaccount_size() - 1; i++) {
			cout << *account_status++ << endl;
		}

		account_status -= getaccount_size() - 1;

		account_size--;

	}

}

void ATM::addEntry(string newEntry) {
	
	int size = getaccount_size() + 1;
	string *new_array = new string[size];

	if (size == 1) {
		*new_array = newEntry;
		account_status = new_array;
		cout << *account_status << endl;
	}

	else {

		for (int i = 0; i < size - 1; i++) {
			*new_array++ = *account_status++;
		}

		*new_array = newEntry;
		new_array -= size - 1;

		account_status = new_array;

		for (int i = 0; i < size - 1; i++) {
			cout << *account_status++ << endl;
		}

		cout << *account_status << endl;

		account_status -= size - 1;

	}

	account_size++;
}

string ATM::getEntry() {
	return *account_status;
}

ATM::~ATM() {
	delete []account_status;
}

ATM::ATM() {
	money = 0.0;
	account_size = 0;
	account_status = NULL;
}

ATM::ATM(const ATM& copy) {
	account_status = copy.account_status;
	account_size = copy.account_size;
	money = copy.money;
}

istream& operator >> (istream& is, ATM& input) {
	is >> input.money;
	return is;
}

ostream& operator << (ostream& os, const ATM& output) {
	os << output.money;
	return os;
}

ATM ATM::operator +(const ATM& plus) {

	ATM temp;
	temp.money = money + plus.money;

	return temp;
}

ATM ATM::operator +=(const ATM& plus_equal) {

	ATM temp;
	temp.money = money + plus_equal.money;
	money = temp.money;
	return temp;
}

int ATM::operator !=(const ATM& equal_equal) {

	int temp;

	if (equal_equal.money == 0) {
		temp = 1;
	}

	else {
		temp = 0;
	}

	return temp;
}

ATM ATM::operator -(const ATM& minus) {
	ATM temp;

	temp.money = money - minus.money;

	return temp;
}
void ATM::setmoney(const float money) {
	this->money = money;
}

float ATM::getmoney() const {
	return money;
}

void ATM::setaccount_size(const int account_size) {
	this->account_size = account_size;
}

int ATM::getaccount_size() {
	return account_size;
}

int main()
{
	ATM money, money1;
	string name;
	string newEntry;
	char word;
	int leave = 0;

	cout << "Whats your name" << endl;
	cin >> name;

	cout << "Hello " << name << " welcome to your first ATM what would you like to view " << endl;

	cin >> newEntry;
	money.addEntry(newEntry);

	while (leave == 0) {
		
		cout << "Press a to add another entry. \n";
		cout << "Press b to delete an entry. \n";
		cout << "Press c to start adding money." << endl;
		cin >> word;

		switch (toupper(word)) {
		case 'A':
			cout << "What would you like to add" << endl;
			cin >> newEntry;
			money.addEntry(newEntry);

			break;

		case 'B':
			cout << "What would you like to delete" << endl;
			cin >> newEntry;
			money.removeEntry(newEntry);
			break;

		case 'C':
			leave = 1;

			break;
		}
		
	}

	cout << "How much money would you like to add to your account? " << endl;
	cin >> money;
	

	while (1) {

		ATM money2 = money += money1;
		cout << "Well " << name <<" You currently have " << money2 << " in your account" << endl;

		cout << "Type in another amount \n";
		cin >> money1;

		if (money != money1) {
			
			break;
		}

	}

}
