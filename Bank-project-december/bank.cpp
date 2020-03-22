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

/**
 * *Macros area
 * ? Right percentage will be decided later
 */

#define CHARGE_PER_WITHDRAW 0.03

using namespace std;

/**
 * ! Future TODO list
 * TODO: Calculating interest for different classes differently
 * TODO: ..based on different annual interest rate for them.
 * 
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
	protected:
		double accountBalance;
		int depositCounter, withdrawCounter;
	private:
		
		double totalDeposit, totalWithdraws;
		double annualInterestRate, monthlyInterestRate;
		double monthlyInterest , monthlyCharges;
	public:
		/**
		 * @brief Construct a new bank account object
		 * Initializing all member variables to default
		 */
		Bank_account() {
			accountBalance = 0.0;
			totalDeposit , totalWithdraws = 0;
			depositCounter , withdrawCounter = 0;
			annualInterestRate = init();
			monthlyInterestRate = 0.0;
			monthlyInterest = 0, monthlyCharges = 0;
		}

		double init() {
			double getAnnualIntRate = 0.0;
			bool inputCheck = false;
			do {
				cout << "\nWelcome, Please enter current"
				 << " annual interest rate for this year: ";
				cin >> getAnnualIntRate;
				if ( getAnnualIntRate > 0 )
					return getAnnualIntRate;
				else {
					cout << "You must enter valid interest rate.\n";
					inputCheck = true;
				}
			} while ( inputCheck );
			
			/**
			 * TODO: Validate input
			 * TODO: Add loop to enforce user
			 * TODO: PRINT reason instead of just returning
			 * TODO: in deposit and withdraw methods.
			 */
			return getAnnualIntRate;
		}
		
		virtual bool deposit( double depositAmount ) {
			if ( depositAmount <= 0 ) {
					cout << "You've entered invalid deposit amount $." << endl;
					cout << "Exiting from the process, please redo if you wish $." << endl;
					return false;
			} else {
				accountBalance += depositAmount;
				totalDeposit += depositAmount;
				depositCounter++;
				cout << "Your account balance has been sucessfully updated $.\n";
			}		
			return true;
		}

		virtual bool withdraw ( double withdrawAmount ) {
			if ( withdrawAmount <= 0 ) {
					cout << "You've entered invalid withdraw amount $." << endl;
					cout << "Exiting from the process, please redo if you wish $." << endl;
					return false;
			} else if ( withdrawAmount > accountBalance ) {
				cout << "You don't have enough balance.\n";
				cout << "Action cannot be performed.\n";
				return false;
			} else {
				accountBalance -= withdrawAmount;
				totalWithdraws += withdrawAmount;
				withdrawCounter++;
				cout << "You've sucessfully withdrawed amount $.\n"
					 << "Amount has been deducted from your balance.\n";
			}
			return true;
		}

		void calculateInterest() {
			monthlyInterestRate = ( annualInterestRate / 12.0 );
			monthlyInterest = monthlyInterestRate * accountBalance;
			accountBalance += monthlyInterest;
		}
		
		double getMonthlyInterest() {
			return monthlyInterest;
		}

		double monthlyBill( double ChargesPerMonth ) {
			// *ChargesPerMonth actually denotes
			// *Charges per withdraw , like percent of amount
			// *withdrawed from account.
			monthlyCharges = totalWithdraws * ChargesPerMonth;
			accountBalance -=monthlyCharges;
			// Time for calculating monthly interest
			calculateInterest();
			reset_afterMonth();
			return monthlyCharges;
		}

		void monthlyReport( double monthlyCharges ) {
			cout << "\nYour current balance is: $" << accountBalance
				 << "\nTotal withdraws made : " << withdrawCounter
				 << "\nTotal amount withdrawed : $" << totalWithdraws
				 << "\nTotal Deposit made : " << depositCounter
				 << "\nTotal amount deposited : " << totalDeposit;
			
			cout << "\nYou've earned $" << getMonthlyInterest() << " for having $" << accountBalance << " balance.\n";
			cout << "\nMonthly charges for this month $" << /* monthlyBill(CHARGE_PER_WITHDRAW) */ monthlyCharges << ".";
			// *Charges per month for bank class are fixed.
		}

		// like month ended begin variables for
		// next month, resetting the previous month data
		void reset_afterMonth() {
			totalWithdraws = 0;
			totalDeposit = 0;
			depositCounter, withdrawCounter = 0;
			monthlyCharges = 0;
		}

};

class Saving_account : public Bank_account {
	private:
		double monthlyCharges, chargesPerWithdraw;
	public:
		Saving_account() {
			monthlyCharges = 0.0,
			chargesPerWithdraw = 0.03;
		}

		bool accountStatus( double currentBalance ) {
			if ( currentBalance > 25 )
				return true;
			else
				return false;
		} 

		bool withdraw ( int withdrawAmount ) override {
			if ( accountStatus( accountBalance ) ) {
				if ( !Bank_account::withdraw( withdrawAmount )) {
					cout << "\nCouldn't process your request.";
					cout << "\nPlease try again.";
					return false;
				} 
			} else {
				cout << "\nYour account has been inactive, "
					 << "Due to lower balance than 25$.";
				cout << "\nPlease add some balance to re-"
					 << "activate your account.";
				return false;
			}
			return true;
		}

		/**
		 * *No need to make deposit method as it's just
		 * *Calling parent class deposit method doesn't 
		 * *make sense to just make function to call other
		 * *function. Will just directly call the parent
		 * *class method.
		 * ? Or make them virtual, let compiler call them
		 * ? based on account type. 
		 * ! Revise the concepts of virtual, polymorphism.
		 */

		/**
		 * ! No now it makes sense to create deposit function
		 * ! As parent class got virtual functions need to implement
		 * ! them here too. 
		 * *I'll add some different operations in deposit function
		 * * Later.
		 * TODO: Add some different functionality in deposit func
		 * TODO: of saving class.
		 */

		bool deposit( int depositAmount ) override {
			/**
			 * *Calling parent class function just now
			 * TODO: Some more actions for this function.
			 */
			if ( !Bank_account::deposit( depositAmount ) ) {
				cout << "\nCouldn't process the request.\n";
				return false;
			} else
				return true;
		}

		void saving_monthlyBill() {
			/**
			 * TODO: Think about solving monthlyReport function interjunction of monthlyBill function call in it.
			 * TODO: Think about why saved monthlyCharges of saving account? What's the use of it.
			 * 
			 */
			if ( withdrawCounter > 4 ) {
				cout << "\nYou've had four withdraws, "
					 << "You've 5th withdraw this month, "
					 << "service charges for each withdraw "
					 << "is now " << chargesPerWithdraw * 0.02 
					 << " percent.\n";
				chargesPerWithdraw *= 0.02;
				monthlyCharges = Bank_account::monthlyBill( chargesPerWithdraw );
				Bank_account::monthlyReport( monthlyCharges );
			}
		}
};

class Checking_account : public Bank_account {
	private:
		double serviceCharges, monthlyCharges;
		double checking_chargesPerWithdraw;
	public:
		Checking_account() {
			serviceCharges , monthlyCharges = 0.0;
			checking_chargesPerWithdraw = 0.10;
		}

		// *Below function doesn't make a still sense
		// *But as original author made it, I'd make it
		// *with some modifications ofcourse but logic
		// *of it still isn't clear to me
		// *I think i got what author wanted, 
		// *Service charges should be applied if withdraws
		// *made are more than current balance
		void deductServiceCharges( int withdrawCounter ) {
			//  ? if ( accountBalance - withdrawCounter < 0 )
				if ( withdrawCounter > accountBalance )
					accountBalance -= serviceCharges;
		}

		void checkingMonthlyReport() {
			monthlyCharges = Bank_account::monthlyBill( checking_chargesPerWithdraw );
			serviceCharges = monthlyCharges;
			/** 
			 * TODO: monthlyReport is calling monthlyBill in it
			 * TODO: think about how to resolve the conflicts
			 * TODO: when don't want it to be called in monthly report.
			*/
			Bank_account::monthlyReport( monthlyCharges );
			cout << "\nService Charges for this month : $" << serviceCharges;
		}

};

int main() {
	Bank_account* ptr = NULL;
	int accountType = 0;
	do {
		cout << "Please read account type and select one for your account.\n";
		cout << "1- Normal account\n2- Saving Account\n3- Checking Account\n";
		cout << "Enter account type please : ";
		cin >> accountType;
	} while ( accountType <= 0 || accountType > 3 );
	// Assigning bank class pointer object memory according to account type
	switch (accountType) {
	case 1:
		ptr = new Bank_account();
		break;
	case 2:
		ptr = new Saving_account();
		break;
	case 3:
		ptr = new Checking_account();
		break;
	default:
		break;
	}
	int userChoice = 0;
	bool validate_choice = false, exitSignal = true;
	/**
	 * TODO: Think about adjusting account type
	 * TODO: Creating appropriate class object through parent class
	 * TODO: Calling appropriate methods according to it
	 * TODO: Finishing things up, testing.
	 */
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