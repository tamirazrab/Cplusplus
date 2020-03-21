/**
 * @file bank.cpp
 * @author Unknown
 * @improved by Tamir
 * @brief - Simple bank proejct with basic deposit 
 *  and withdrawal operations nothing special really.
 * @version 0.1
 * @date 2020-03-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include<iostream>

using namespace std;
int w_inc = 0, t_w = 0;
int d_inc = 0;
int t_d = 0;
/*
 	t_d -> Total deposit, contains amount deposited in total
 	t_w -> Total withdraw, holds amount withdrawed from bank
 	d_inc -> Deposit increment, increments every time deposit
		  	*is made.
	w_inc -> Withdraw increment, increments every time withdraw
			*is made.
	
	*Why they made globally? Why not inside parent class and use
	 them in class inheriting from parent class.
	*Why is it necessary to track these records?
	*If it is, why does there is a need for storing total amount
	 deposited and withdrawed? Why is it benefical?
 */
class bank_account {
	protected:
		int monthly_services_charge;
	int monthly_fee;
	int status;
	static int balances;
	int no_of_deposite_this_month;
	int no_of_withdraw;
	int annual_interest_rate;
	public:
		bank_account() {}
	bank_account(int b, int a) {
		balances = b;
		annual_interest_rate = a;
	}
	void deposite(int amount_of_deposite) {

		balances = amount_of_deposite + balances;
		d_inc++;
		t_d = t_d + amount_of_deposite;
	}
	int withdraw(int amount_of_withdraw) {
		balances = balances - amount_of_withdraw;
		w_inc++;
		t_w = t_w + amount_of_withdraw;
		return t_w;
	}
	virtual void calclnt() {
		int monthly_interest_rate = (annual_interest_rate / 12);
		int monthly_interest = (balances * monthly_interest_rate);
		balances = balances + monthly_interest;
	}
	virtual void monthlyproc() {
		balances = monthly_services_charge - balances;
		calclnt();
		w_inc = 0;
		d_inc = 0;
		monthly_services_charge = 0;
	}
	void summary() {
		cout << "balance =" << balances << endl;
		cout << "no. of width draws =" << w_inc << endl;
		cout << "no.of deposit =:" << d_inc << endl;
	}
};
int bank_account::balances = 0;
class saving_account: public bank_account {
	public: saving_account() {}
	int withdraw() {
		if (balances < 25) {
			status = 0;
		} else {
			status = 1;
		}


		if (status == 1) {
			bank_account::withdraw(no_of_withdraw);
			/*
				withdraw function is returning t_w
				if none catching it why bother return 
				it in first place?
			*/
		} else {
			cout << "account is inactive";
		}
	}
	void deposite(int amount) {
		//balances=balances+amount;
		//cout<<balances;
		bank_account::deposite(amount);
	}
	void monthlyproc() {
		if (w_inc > 4) {
			cout << "u have 5th withdraw in this month :: service charges for each withdraw";
			monthly_services_charge = 1;
			if (balances < 25) {
				status = 0;
				cout << "account inactive";
			} else {
				status = 1;
			}
		}
	}
};

class checking_account: public saving_account {

	protected: int monthly_fee;
	int withdraw_fee;
	int services_charge;

	public: checking_account() {

		monthly_fee = 5;
		withdraw_fee = 0.10;
		// withdraw_fee is int , but floating value is being stored
		services_charge = 15;
	}
	int withdraw(int w_inc) {
		if ((balances - w_inc) < 0) {
			balances = balances - services_charge;

		}
	}
	void monthlyproc() {
		services_charge = monthly_fee + (w_inc * withdraw_fee);
		bank_account::monthlyproc();
		cout << "services charges=" << services_charge;
	}

};

int main() {
	int userChoice = 0;
	bool validate_choice = false;
	// Basic Menu
	do {
		
		do {
			cout << "\tBank System - Menu\n" <<
				"1- Deposit" << "2- Withdraw" <<
				"3- Account Summary" << "4- Exit\n";
			cout << "Enter your choice: ";
			cin >> userChoice;
			// Validation of user choice
			if (userChoice <= 0 || userChoice > 4) {
				cout << "Error: You've entered invalid choice.\n" <<
					"Please enter correct choice.\n";
				validate_choice = true;
			} else
				validate_choice = false;

		} while (validate_choice);
		// methods call based on input
		switch (expression) {
			case /* constant-expression */ :
			/* code */
			break;
			case /* constant-expression */ :
			/* code */
			break;

			case /* constant-expression */ :
			/* code */
			break;

			case 4:
				cout << "\n Thank you for using \n" <<
					"Have a good day.\n";
				// exiting program
				exit(EXIT_SUCCESS);
				break;
			default:
				break;
		}
	} while ();


	return 0;
}