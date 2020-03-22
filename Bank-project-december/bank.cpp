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
		double chargesPerWithdraw;
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
			chargesPerWithdraw = 0.04;
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
				printCurrentBalance();
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
				printCurrentBalance();
			}
			return true;
		}

		void calculateInterest() {
			monthlyInterestRate = ( annualInterestRate / 12.0 );
			monthlyInterest = monthlyInterestRate * accountBalance;
		}
		
		double getMonthlyInterest() {
			return monthlyInterest;
		}

		virtual double getMonthlyCharges() {
			return monthlyCharges;
		}

		virtual double getChargesPerMonth() {
			return chargesPerWithdraw;
		}

		virtual double monthlyBill( double ChargesPerMonth ) {
			// *ChargesPerMonth actually denotes
			// *Charges per withdraw , like percent of amount
			// *withdrawed from account.
			monthlyCharges = totalWithdraws * ChargesPerMonth;
			// Time for calculating monthly interest
			calculateInterest();
			return monthlyCharges;
		}

		void printCurrentBalance() {
			cout << "\nYour new balance is : $" << accountBalance << "\n";
		}

		virtual void monthlyReport( double monthlyCharges ) {
			cout << "\nYour current balance is: $" << accountBalance
				 << "\nTotal withdraws made : " << withdrawCounter
				 << "\nTotal amount withdrawed : $" << totalWithdraws
				 << "\nTotal Deposit made : " << depositCounter
				 << "\nTotal amount deposited : $" << totalDeposit;
			
			cout << "\nYou've earned $" << getMonthlyInterest() << " for having $" << accountBalance << " balance.\n";
			accountBalance += monthlyInterest;
			cout << "\nMonthly charges for this month $" << /* monthlyBill(CHARGE_PER_WITHDRAW) */ monthlyCharges << ".\n";
			// *Charges per month for bank class are fixed.
			accountBalance -=monthlyCharges;
			printCurrentBalance();
		}

		// like month ended begin variables for
		// next month, resetting the previous month data
		virtual void reset_afterMonth() {
			totalWithdraws = 0;
			totalDeposit = 0;
			depositCounter, withdrawCounter = 0;
			monthlyCharges = 0;
		}

};

/**
 * TODO: Implementation of reset account function for
 * TODO: other saving and checking accounts too.
 * 
 */

class Saving_account : public Bank_account {
	private:
		double monthlyCharges, chargesPerWithdraw;
	public:
		Saving_account() {
			monthlyCharges = 0.0,
			chargesPerWithdraw = 0.03;
		}

		double getMonthlyCharges() {
			return monthlyCharges;
		}

		double getChargesPerMonth() {
			return chargesPerWithdraw;
		}

		void reset_afterMonth() {
			monthlyCharges = 0;
		}
	
		bool accountStatus( double currentBalance ) {
			if ( currentBalance > 25 )
				return true;
			else
				return false;
		} 

		bool withdraw ( double withdrawAmount ) /* override */ {
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

		bool deposit( double depositAmount ) /* override */ {
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

		double monthlyBill( double currentChargesPerWithdraw) {
			/**
			 * TODO: Think about solving monthlyReport function interjunction of monthlyBill function call in it.
			 * TODO: Think about why saved monthlyCharges of saving account? What's the use of it.
			 * *Saved because it is required in generating monthly report got answer while making implementation
			 * *of main func.
			 * 
			 */
			if ( withdrawCounter > 4 ) {
				cout << "\nYou've had four withdraws, "
					 << "You've 5th withdraw this month, "
					 << "service charges for each withdraw "
					 << "is now " << chargesPerWithdraw * 0.2 
					 << " percent.\n";
				// doubling charge fee
				currentChargesPerWithdraw *= 0.2;
				monthlyCharges = Bank_account::monthlyBill( currentChargesPerWithdraw );
				// Bank_account::monthlyReport( monthlyCharges );
			}

			return monthlyCharges;
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

		double getMonthlyCharges() {
			return monthlyCharges;
		}

		void reset_afterMonth() {
			serviceCharges = 0;
			monthlyCharges = 0;
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

		double getChargesPerMonth() {
			return checking_chargesPerWithdraw;
		}

		void monthlyReport ( double checkingMonthlyCharges ) {
			serviceCharges = checkingMonthlyCharges;
			/** 
			 * TODO: monthlyReport is calling monthlyBill in it
			 * TODO: think about how to resolve the conflicts
			 * TODO: when don't want it to be called in monthly report.
			*/
			Bank_account::monthlyReport( checkingMonthlyCharges );
			cout << "\nService Charges for this month : $" << serviceCharges;
		}

};

/**
 * @brief Making problems
 * ! It got problems not assigning the memory to ptr
 * ! Works if concluded from function and directly implement
 * ! it in main func.
 * *Need to look solution for it.
 * TODO: Find solution and reason of problem occuring.
 * @param ptr 
 * @return Bank_account 
 */
/*
Bank_account getAccountType( Bank_account* ptr ) {
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
	}
}
*/
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
	}
	int userChoice = 0;
	bool validate_choice = false, exitSignal = true;
	bool tryAgain = false;
	char tryAgainChoice = '\0';
	double monthlyCharges;
	int depositAmount = 0 , withdrawAmount = 0;
	/**
	 * TODO: Think about adjusting account type
	 * TODO: Creating appropriate class object through parent class
	 * TODO: Calling appropriate methods according to it
	 * TODO: Finishing things up, testing.
	 */
	// Basic Menu
	do {	
		do {
			cout << "\n\tBank System - Menu\n" <<
				"\n\t1- Deposit\n" << "\t2- Withdraw\n" <<
				"\t3- Account Summary\n" 
				<< "\t4- Reset Status\n" << "\t5- Exit\n"
				<< "\t6- Clear Screen\n";
			cout << "\nEnter your choice: ";
			cin >> userChoice;
			// Validation of user choice
			if (userChoice <= 0 || userChoice > 6) {
				cout << "Error: You've entered invalid choice.\n" <<
					"Please enter correct choice.\n";
				validate_choice = true;
			} else
				validate_choice = false;

		} while (validate_choice);
		// methods call based on input
		switch ( userChoice ) {
			case 1:
			do {
				cout << "\nEnter amount to deposit $: ";
				depositAmount = 0;
				cin >> depositAmount;
				if (!ptr->deposit( depositAmount )) {
					cout << "\nCouldn't deposit, Do you want to try again? Y/N :";
					cin >> tryAgainChoice;
					if ( tryAgainChoice == 'n' || tryAgainChoice == 'N')
						tryAgain = false;
					else
						tryAgain = true;
				}
			} while( tryAgain );
				
			break;
			case 2:
				do {
				cout << "Enter amount to withdraw $: ";
				withdrawAmount = 0;
				cin >> withdrawAmount;
				if (!ptr->withdraw(withdrawAmount)) {
					cout << "\nCouldn't withdraw, Do you want to try again? Y/N :";
					cin >> tryAgainChoice;
					if ( tryAgainChoice == 'n' || tryAgainChoice == 'N')
						tryAgain= = false;
					else
						tryAgain= = true;
				}
			} while( tryAgain );
			
			break;

			case 3:
				monthlyCharges = ptr->monthlyBill( ptr->getChargesPerMonth() );
				ptr->monthlyReport( monthlyCharges );
			break;

			case 4:
				ptr->reset_afterMonth();
			break;

			case 5:
				cout << "\n Thank you for using \n" <<
					"Have a good day.\n";
				exitSignal = false;
				break;
			default:
				system("cls");
				break;
		}
	} while ( exitSignal );
	return 0;
}