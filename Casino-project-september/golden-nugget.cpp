#include <iostream>

#include <stdlib.h>

#include <time.h>

#include <string.h>

using namespace std;

#
define MAX_BET_AMT 700 // Dice Roll max bet amount
# define MIN_BET_AMT 5 // Dice Roll min bet amount
# define PC_FIRST_DICE 0# define PC_SECOND_DICE 1# define USER_FIRST_DICE 2# define USER_SECOND_DICE 3# define PC_DICE_SUM 0# define USER_DICE_SUM 1

// Function Declaration area
/*
	Draw line function draws a line of special
	character specified in it's parameters to a
	given length
*/
void drawLine(int length, char character);
/ one to how many
	times move cursor to next line and second how many
	times should it give spaces
*/
vo, int tab_length = 0);

/*
 * Dice roll function works with by taking user starting amount, asking user to bet some money
 * then proceed to game. It contains all the validation of user input so user input can't be wrong
 * It proceeds by rolling two dices of Computer first then adding their sum and displaying it to the screen
 * then asks the player or user to press a special relevant key to proceed rolling user or player dice
 * then it's compare who got the greater number and declares that player as winner
 * If computer or player dice sum equals to 2 -> then they will be automatically declared as loser
 * If computer or player dice sum equals to 12 -> then they will automatically be declared as winner
 */

int diceRoll();

/*
 * Number Guessing function generates a random number in range of 1 - 10
 * And ask user to bet any amount > 0 and < maximum bet amount
 * then asks user for guess, if user somehow guesses correctly
 * then he gets x10 amount back which he bett, if player guesses wrong then
 * he loses money
 */

void NumberGuessing();

/*
 * High and low function proceed by generating two random numbers,
 * it shows first random generated number to user then asks user to guess
 * whether second random generated number is higher ( greater ) or lower ( lesser)
 * then previously generated number. ( Second number isn't shown to user )
 * Awards x2 money back if user guesses right.
 */

void High_and_Low();

/*
 * back to main function as name suggest directs user back to main() function when user is done
 * playing one game and wants to play another game or to close program.
 * It is called on every function end before asking whether user want to play again or not.
 */

void backToMain();

/*
 * Ask user bet gets user bet ( validated ) and stores it in global variable so that all functions
 * can access it properly, it is called on every function start. Returns true after it's get valid bet amount/
 */

bool askUserBet(int maxBet, int minBet);

/*
 * Play again gets user choice ( validated ) whether he wants to play again or not.
 * then returns true if user presses Y or y and returns false if user enters n or N
 */

bool playAgain();

/*
 * Check user money functions checks whether user starting balance reached zero or not
 * if it reached zero it redirects user back to main function so user can deposit some new amount
 * and can enjoy game again. If it doesn't reached zero then it asks user whether he wants to play again
 * or not.
 */

bool checkUserMoney();

/*
 * game Greetings function basically takes game name as argument and display it in a fancy way
 * in a starting of every game function.
 */

void gameGreetings(string gameName);

/**
 * @brief Simple function to validate starting balance entered by user
 * 
 * @param getStartingBalance 
 * @return true
 * @return false 
 */

bool v_startingBalance(int getStartingBalance);

// Global variables area
/*
	direct back to main() function
	in a way that avoids asking user name again
	and let user deposit some new amount to play some
	more games.
*/
bool g_getBackToMain = true;
/*
	Made g_userName variable to global to avoid
	un-necessary passing to back to back to
	functions and let ease our work
*/
string g_userName;
/*
	g_startingBalanceOfUser variable holds the starting money that user
	deposits and let it change through every function
	required it
*/
int g_startingBalanceOfUser = 0;

/*
 * g_userBettingAmount is the variable which holds the amount user bets
 * before playing any game.
 */
int g_userBettingAmount = 0;

int main() {
    system("cls"); // Clear Screen
    srand(time(NULL)); // calls only once seeding rand()

    void( * gameFunctions[])() = {
        NumberGuessing,
        High_and_Low,
        diceRoll,
        /**
         * TODO: Not sure if exit function will fit in anyway
         * TODO: will take that headache on testing times.
         * ! It won't because it expects argument.
         */
    };

    if (g_getBackToMain) {
        cout << "Golden Nuggets Casino" << endl;
        cout << "Enter your name please : ";
        getline(cin, g_userName);
    } else {
        cout << "Your balance is " << g_startingBalanceOfUser << "$ from previous games.";
        cout << " Please Deposit some new amount to play more games.";
    }

    bool validateUserStartingAmount = false;
    do {
        cout << "Enter your starting betting amount in $ : ";
        cin >> g_startingBalanceOfUser;
    } while (v_startingBalance(g_startingBalanceOfUser));

    cout << "Welcome to Golden Nugget Casino, " << g_userName << endl;
    cout << "Please Choose from the list below, Which game you want to play ? "
    cout << " 1 - Number Guessing ( Win amount x10) " << endl
    cout << " 2 - High and Low ( Win amount x2) " << endl
    cout << " 3 - Dice Roll ( Win amount x2)" << endl
    cout << " 4 - To Exit Program." << end
    cout << "Enter your choice below ( in numbers ) : ";
    int gameSelection = 0;
    cin >> gameSelection
    /*
    switch ( gameSelection ) {
        case 1: NumberGuessing(); break;
        case 2: High_and_Low(); break;
        case 3: diceRoll(); break;
        case 4: exit( 0 ); // Didn't added break because it's unreachable if exit function called first.
        defaul ); cout << "Wrong Choice, Exiting Program."; break;
    }
    */
    if (gameSelection == 1)
        gameSelection = 0;
    else if (gameSelection < 0) {
        cout << "Invalid choice.\n";
        return 0;
    } else if (gameSelection >= 4) {
        cout << "Thank you so much for using.\n";
        cout << "Have a good day.";
        exit(EXIT_SUCCESS);
    }

    ( * gameFunctions[gameSelection])();
    return 0;
}

void drawLine(int length, char character) {
    for (int i = 1; i <= length; ++i)
        cout << character;
    cout << "\n";
}


vo tab_length) {
    for (int i = 1; i <= newline_length; ++i)
        cout << endl;
    for (int i = 1; i <= tab_length; ++i)
        cout << "\t";
}

void diceRoll() {
    start_of_diceRoll: gameGreetings("Dice Roll");
    bool rolldice_check = true;

    /*
        According to betting rule minimum bet allowed is 5$
        whereas maximum is 700$ user can't bypass these rules
        if g_userBettingAmount is more then the deposited money by the user
        then it also not allowed
    */
    /*
     * MAX_BET_AMT represents maximum bet can be placed in dice roll which is 700$
     * MIN_BET_AMT represents minimum bet can be placed in dice roll which is 5$
     */
    askUserBet(MAX_BET_AMT, MIN_BET_AMT);

    /*
     * Array of integer dice contains the sum of dices rolled both by computer and user.
     * First two indexes of dice array represents computer dices rolled on floor
     * dice [ PIC_FIRST_DICE -> equivalent to 0 ] , dice [ PC_SECOND_DICE -> equivalent to 1 ]
     * Last two indexes of dice array represents user or player dices
     * dice [ USER_FIRST_DICE -> equivalent to 2 ] , dice [ USER_SECOND_DICE -> equivalent to 3 ]
     */

    int dice[4],
    diceSum[2];
    dice[PC_FIRST_DICE] = (rand() % 6) + 1; // in range 1 - 6;
    dice[PC_SECOND_DICE] = (rand() % 6) + 1;
    diceSum[PC_DICE_SUM] = dice[PC_FIRST_DICE] + dice[PC_SECOND_DICE];drawLine(80, '*
    cout << "Computer rolls the dice on the floor " << diceSum[PC_DICE_SUM] <<
    " for the bet of " << g_userBettingAmount << "$" << endldrawLine(80, '*');

    if (diceSum[PC_DICE_SUM] == 2) {
        // Computer Loses automatically
        drawLine(80, '_');
        cout << "Computer looses automatically as it lands on 2." << endl;
        cout << "Congratulations you have won " << g_userBettingAmount * 2 << "$.";
        drawLine(80, '_');
        drawLine(80, '^');
        g_startingBalanceOfUser = g_startingBalanceOfUser + (g_userBettingAmount * 2);
        cout /* << endl */ << "Your new balance is " << g_startingBalanceOfUser << "$.";
        drawLine(80, '.');
        goto end_of_diceRollGame;
    } else if (diceSum[PC_DICE_SUM] == 12) {
        // Computer Won automatically
        drawLine(80, '_');
        cout << "Computer Wons automatically as it lands on 12." << endl;
        cout << "Sorry you can't roll dice, as chances of yours getting 12 " <<
            " is equal to NULL." << endl;
        drawLine(80, '_');
        drawLine(80, '^');
        cout << "Your new balance is " << g_startingBalanceOfUser << "$.";
        drawLine(80, '.');
        goto end_of_diceRollGame;
    }
    // if computer didn't got 2, or 12 then
    char rollDice;

    do {
        cout << " Please press r/R to roll your dice : ";
        cin >> rollDice;
        // to let user out of loop if he/she typed r/R
        rolldice_check = !(rollDice == 'r' || rollDice == 'R');
    } while (rolldice_check); /*rollDice != 'r' || rollDice != 'R'*/

    dice[USER_FIRST_DICE] = (rand() % 6) + 1; // in range 1 - 6;
    dice[USER_SECOND_DICE] = (rand() % 6) + 1;
    diceSum[USER_DICE_SUM] = dice[USER_FIRST_DICE] + dice[USER_SECOND_DICE];drawLine(80, '*
    cout << g_userName << " rolls the dice on the floor " << diceSum[USER_DICE_SUM] <<
    " for the bet of " << g_userBettingAmount << "$" << endldrawLine(80, '*');

    if (diceSum[USER_DICE_SUM] == 2) {
        // User Losses automatically
        drawLine(80, '_');
        cout << g_userName << " Sorry you have lost as you got 2." << endl;
        drawLine(80, '_');
        drawLine(80, '^');
        // g_startingBalanceOfUser = g_startingBalanceOfUser - g_userBettingAmount;
        cout << "Your new balance is " << g_startingBalanceOfUser << "$.";
        drawLine(80, '.');
        goto end_of_diceRollGame;
    } else if (diceSum[USER_DICE_SUM] == 12) {
        // User Won automatically
        drawLine(80, '_');
        cout << g_userName << " Congratulation on getting number 12, you've won automatically " <<
            endl;
        drawLine(80, '_');
        drawLine(80, '^');
        g_startingBalanceOfUser = g_startingBalanceOfUser + (g_userBettingAmount * 2);
        cout << "Your new balance is " << g_startingBalanceOfUser << "$.";
        drawLine(80, '.');
        goto end_of_diceRollGame;
    } else if (diceSum[PC_DICE_SUM] == diceSum[USER_DICE_SUM]) {
        // if both got the same number in their dices
        drawLine(80, '^');
        cout << " Haha, Sorry no one won as both players dices rolled";
        cout << " on same number. " << endl;
        drawLine(80, '.');
        /*
         * Assigning user bett amount back to user starting balance ( g_startingBalanceOfUser )
         * As of it's gonna ask user again to bet new amount after goto statement.
         */
        g_startingBalanceOfUser = g_userBettingAmount;
        goto end_of_diceRollGame;
    }
    // else if user didn't got either 2, or 12

    if (diceSum[PC_DICE_SUM] > diceSum[USER_DICE_SUM]) {
        drawLine(80, '_');
        cout << "Computer got the higher number on their dice " <<
            " Which was " << diceSum[PC_DICE_SUM]; /*<< endl */
        cout << " Whereas you got " << diceSum[USER_DICE_SUM];
        drawLine(80, '_');
        drawLine(80, '^');
        cout << " Sorry you've just lost " << g_userBettingAmount << "$.";
        drawLine(80, '^');
        drawLine(80, '^');
        cout << "Your new balance is " << g_startingBalanceOfUser << "$.";
        drawLine(80, '.');
    } else {
        drawLine(80, '_');
        cout << g_userName << " got the higher number on their dice " <<
            " Which was " << diceSum[USER_DICE_SUM];
        cout << " Whereas Computer got " << diceSum[PC_DICE_SUM];
        drawLine(80, '_');
        cout << " Congratulations you've won " << g_userBettingAmount << "$.";, '^');
        g_startingBalanceOfUser = g_startingBalanceOfUser + (g_userBettingAmount * 2);
        cout << "Your new balance is " << g_startingBalanceOfUser << "$.";
        drawLine(80, '.');
    }
    end_of_diceRollGame:
        /*
         * checkUserMoney returns true if balance == 0 or < 0 else -> returns false
         * playAgain returns true if userChoice == y || Y else returns false
         */
        if (checkUserMoney())
            /* Send to main menu */
            backToMain();
        else {
            if (playAgain())
                goto start_of_diceRoll;
            else
                backToMain();
        }

    /*
        Eliminating use of conditions directly inside while
        loop as it's gives un-expected results
        using boolean variable playagain_check to determine
        whether user want to play again or not.
        Sending back user to the lable "END" if user entered
        character different then Y/y N/n
    */

    /* if( g_startingBalanceOfUser < 0 || g_startingBalanceOfUser == 0 || g_startingBalanceOfUser > 0 ) */

    // return 0; -> Useless return 
}

void NumberGuessing() {
    start_of_numberGuessing: gameGreetings("Number Guessing");
    askUserBet(200, 100);
    // After user bet is validated properly
    // generates number in range of 1 - 10 and stores in RandomNumberByComputer;
    int RandomNumberByComputer = (rand() % 10) + 1;
    int getUserGuess = 0;
    cout << "Computer Generated a random number in range of ( 1 - 10) "drawLine(80, '*');
    bool validateUserGuess = false;
    do {, '*');
        cout << "Enter your guess : ";
        cin >> getUserGuess;
        if (getUserGuess < 1 || getUserGuess > 10) {
            validateUserGuess = true;

            cout << "Your Guess is invalid , it must be in range of 1 - 10." << endl;

            cout << "Please enter guess again in range of ( 1 - 10 )" << endl;
        } else
            validateUserGuess = false;
    } while (validateUserGuess);
    // Checking user Guess
    if (getUserGuess == RandomNumberByComputer) {
        drawLine(80, '$');
        cout << "Congratulations Your guess is correct." << endl;
        cout << "Computer Generated Number was " << RandomNumberByComputer;
        cout << "You have won x10 money " << g_userBettingAmount * 10 << " $ ";
        g_startingBalanceOfUser = g_startingBalanceOfUser + (g_userBettingAmount * 10);
        cout << "Your new balance is " << g_startingBalanceOfUser << "$";
        drawLine(80, '$');
    } else {
        drawLine(80, '*');
        cout << "Computer Generated Number was " << RandomNumberByComputer;
        cout << "Whereas your guess was " << getUserGuess;
        cout << "Sorry you've lost " << g_userBettingAmount << " $ ";
        drawLine(80, '*');
    }

    if (checkUserMoney())
        /* Send to main menu */
        backToMain();
    else {
        if (playAgain())
            goto start_of_numberGuessing;
        else
            backToMain();
    }
}

void High_and_Low() {
    start_of_highAndLow: gameGreetings("High and Low");
    char takeGuessFromUser;
    bool validateGuessByUser = false;
    int holdTwoNumbers[2];
    askUserBet(800, 100);
    // Starting Game by generating two random numbers
    holdTwoNumbers[0] = (rand() % 10) + 1; // in range 1 - 10
    holdTwoNumbers[1] = (rand() % 10) + 1;
    getValid_randomNumber: if (holdTwoNumbers[0] > 8 || holdTwoNumbers[0] < 3) {
        /*
         * Did, because if first random generated number is greater then 8
         * Then it's obvious that second number will be lesser
         * Or if first random generated number is lesser then 3
         * Then it's also obvious that second number will be greater no matter what!
         */
        holdTwoNumbers[0] = (rand() % 10) + 1;
        goto getValid_randomNumber;
    drawLine(80, '*
    cout << "Computer Generated first number is " << holdTwoNumbers[0]drawLine(80, '*');
    // Taking User guess
    do {
        cout << "Tell whether next generated number is high or low";
        cout << "then previously generated number. ( H/h for high )";
        cout << "(L/l for Low) ";
        cout << "Enter your guess : ";
        cin >> takeGuessFromUser;
        if (takeGuessFromUser == 'H' || takeGuessFromUser == 'h') {
            validateGuessByUser = false;
            if (holdTwoNumbers[1] > holdTwoNumbers[0]) {
    
                drawLine(80, '*');
    
                cout << "Congratulations you guessed right";
    
                cout << "Second generated number was " << holdTwoNumbers[1];
    
                cout << "You won " << g_userBettingAmount * 2 << "$";
    
                drawLine(80, '*');
    
    
    
                g_startingBalanceOfUser = g_startingBalanceOfUser + (g_userBettingAmount * 2);
                cout << "Your new balance is " << g_startingBalanceOfUser;
     end_of_highAndLow;
            } else {
    
                drawLine(80, '*');
    
                cout << "Sorry you have lost " << g_userBettingAmount << "$";
    
                cout << "Second generated number was " << holdTwoNumbers[1];
    
    
    
                cout << "Your new balance is " << g_startingBalanceOfUser << "$";
    
    
                goto end_of_highAndLow;
            }
        } else if (takeGuessFromUser == 'L' || takeGuessFromUser == 'l') {
            validateGuessByUser = false;
            if (holdTwoNumbers[1] < holdTwoNumbers[0]) {
    
                drawLine(80, '*');
    
                cout << "Congratulations you guessed right";
    
                cout << "Second generated number was " << holdTwoNumbers[1];
    
                cout << "You won " << g_userBettingAmount * 2 << "$";
    
                drawLine(80, '*');
    
    
    
                g_startingBalanceOfUser = g_startingBalanceOfUser + (g_userBettingAmount * 2);
                cout << "Your new balance is " << g_startingBalanceOfUser << "$";
    
    
                goto end_of_highAndLow;
            } else {
    
                drawLine(80, '*');
    
                cout << "Sorry you have lost " << g_userBettingAmount << "$";
    
                cout << "Second generated number was " << holdTwoNumbers[1];
    
    
    
                cout << "Your new balance is " << g_startingBalanceOfUser << "$";
    
    
                goto end_of_highAndLow;
            }
        } else {

            cout << "You entered invalid guess.";

            cout << "Please enter valid guess again.";
            validateGuessByUser = true;
        }
    } while (validateGuessByUser);
    end_of_highAndLow: if (checkUserMoney()) {
        /* Send to main menu */
        backToMain();
    }
    else {
        if (playAgain())
            goto start_of_highAndLow;
        else
            backToMain();
    }
}

void backToMain() {
    bool confirmTransfer = false;
    do {
        cout << "Please Press m or M to go to main menu : ";
        char askUser;
        cin >> askUser;
        if (askUser == 'M' || askUser == 'm')
            confirmTransfer = false;
        else {
            confirmTransfer = true;

            cout << "Please enter m or M to get back to main menu.";

            cout << "Anything else is not accepted.";
        }
    } while (confirmTransfer);

    g_getBackToMain = false;
    main();
}

bool askUserBet(int maxBet, int minBet) {
    bool validateUserBet = false;
    do {
        cout << "Please enter the amount you want to bet : ";
        cin >> g_userBettingAmount;
        if (g_userBettingAmount > g_startingBalanceOfUser) {
            validateUserBet = true;

            cout << "Sorry you can't bet more then your original balance.";
        } else if (g_userBettingAmount > maxBet) {
            validateUserBet = true;

            cout << "Sorry you cannot place bet more then " << maxBet << "$.";
        } else if (g_userBettingAmount < minBet) {
            validateUserBet = true;

            cout << "Sorry your bet must be greater then " << minBet << "$.";
        } else {
            validateUserBet = false;
            // deducting money before hand
            g_startingBalanceOfUser = g_startingBalanceOfUser - g_userBettingAmount;
        }
    } while (validateUserBet);
    return true;
}

bool playAgain() {
    bool confirmPlayAgain = false;
    char askUser;
    do {
        cout << "Do you want to play again ? (Y/N) : ";
        cin >> askUser;
        if (askUser == 'Y' || askUser == 'y')
            return true;

        else if (askUser == 'N' || askUser == 'n')
            return false;

        else {
            confirmPlayAgain = true;

            cout << "Please enter your choice correctly.";
        }
    } while (confirmPlayAgain);
}

bool checkUserMoney() {
    if (g_startingBalanceOfUser <= 0) {
        drawLine(80, '#');
        cout << "You don't have any money left to bet. ";
        cout << "Sending you back to main menu.";
        drawLine(80, '#');
        return true;
    } else
        return false;
}

void gameGreetings(string gameName) {
    system("cls")
    drawLine(80, '$')
    cout << "Welcome to " << gameName << " Game " << " Mr." << g_userName << endl
    drawLine(80, '$')
}

bool v_startingBalance(int getStartingBalance) {
    if (getStartingBalance > 700) {
        cout << "Sorry you can't deposit more then 700$.";
    } else if (getStartingBalance < 200) {
        cout << "Sorry you must not deposit less then 200$.";
    } else
        return false;
    return true;
}