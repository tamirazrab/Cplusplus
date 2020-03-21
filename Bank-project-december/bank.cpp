/**
 * @file bank.cpp
 * @author Unknown
 * @improved by: Tamir
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

class Bank_account {
	/** 
	 * TODO: deposit and withdraw methods
	 * TODO: validation of arguments
	 * TODO: deposit and withdraw counters
	 * TODO: hold total deposited and withdrawed amount
	 * TODO: Calculate interest and monthly charges
	 * TODO: Display account summary for this month
	 * 
	*/
	private:
		double accountBalance;
		double totalDeposit, totalWithdraws;
		int depositCounter, withdrawCounter;
		double annualInterestRate, monthlyInterestRate;
	public:
		/**
		 * @brief Construct a new bank account object
		 * Initializing all member variables to default
		 */
		bank_account() {
			accountBalance = 0.0;
			totalDeposit , totalWithdraws = 0;
			depositCounter , withdrawCounter = 0;
			annualInterestRate = init();
		}

		double init() {
			double getAnnualIntRate = 0.0;
			cout << "\nWelcome, Please enter current"
				 << " annual interest rate for this year: ";
			cin >> getAnnualIntRate;
			if ( getAnnualIntRate > 0 )
				return getAnnualIntRate;
			else {
				cout << "You must enter valid interest rate.";
			}
			/**
			 * TODO: Validate input
			 * TODO: Add loop to enforce user
			 */
		}
		
		bool deposit( double depositAmount ) {
			if ( depositAmount <= 0 )
				return false;
			else {
				accountBalance += depositAmount;
				totalDeposit += depositAmount;
				depositCounter++;
			}		
			return true;
		}

		bool withdraw ( double withdrawAmount ) {
			if ( withdrawAmount <= 0 )
				return false;
			else if ( withdrawAmount > accountBalance ) {
				cout << "You don't have enough balance.\n";
				return false;
			} else {
				accountBalance -= withdrawAmount;
				totalWithdraws += withdrawAmount;
				withdrawCounter++;
			}
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
	bool validate_choice = false, exitSignal = true;
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
				exitSignal = false;
				break;
			default:
				break;
		}
	} while ( exitSignal );
	return 0;
}